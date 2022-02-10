//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// function haye marboot be kar ba file, natije ,menu ha va logic haye gheir bazi dat inja ast .


#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
#include "global.h"
#include"func.h"


int min(int x,int y){
    if(x>y){
        return y;
    }
    return x;
}///minimum yaftan.
void copy_in_array(struct fdata *head,char name[][20],int scores[],int count) {
    struct fdata *cu=head;
    int i=0;
    while(cu!=NULL){
        strcpy(name[i],cu->name);
        scores[i]=cu->score;
        i++;
        cu=cu->ptr;
    }
} /// baraye sort kardan asami va score ha dar array rikhte shod.
void save_in_file(struct fdata *head) {
    FILE *des;
    des = fopen("names&scores.txt", "w");
    struct fdata *cu=head;
    while(cu!=NULL){
        fprintf(des,"%s",cu->name);
        fprintf(des," ");
        fprintf(des,"%d",cu->score);
        fprintf(des," ");
        cu=cu->ptr;
    }
    fclose(des);
}/// zakhire asami va score ha dar file txt.
void sort_scores(struct fdata *head,int scores[],char name[][20],int count) {
    for(int i=1;i<count;++i){
        for(int j=0;j<count-1;++j){
            if(scores[j]<scores[j+1]){
                int t=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=t;
                char te[20];
                strcpy(te,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],te);
            }
        }
    }
}/// ba estefade az bubble sort , list ra az bala ta paien moratab mikonam.
void free_the_list(struct fdata *head){
    struct fdata *cu;
    while(head!=NULL){
        cu = head->ptr;
        free(head);
        head=cu;
    }
}/// free the linked list
void show_leaderboard(struct fdata *head,int count) {
    char name[count][20];
    int scores[count];
    char cmnd;
    copy_in_array(head,name,scores,count);
    sort_scores(head,scores,name,count);
    SDL_bool shallExit = SDL_FALSE;

    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
        stringColor(sdlrenderer,380,40,"LEADERBOARD",0xFF000000);
        for(int i=0;i<count;++i){
            stringColor(sdlrenderer,380,80+i*40,name[i],0xFF000000);
        }
        stringColor(sdlrenderer,350,700,"*** please press m to save names and scores and return to menu ***",0xFF000000);
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    cmnd=sdlEvent.key.keysym.sym;
                    break;
            }
        }
        if(cmnd=='m'){
            save_in_file(head);
            free_the_list(head);
            shallExit = SDL_TRUE;
            break;
        }
    }
    SDL_Delay(1000);
    printf("\n Hello World\n");
}/// showing leaderboard va kelid 'm' baraye bargasht be menu va save kardan asami va scores .
void is_player_rep(struct fdata *head,int count) {
    int cntrl = 0;
    struct fdata *cu = head;
    while (cu->ptr != NULL) {
        if (cu->name == player1_name) {
            cu->score += score;
            cntrl = 1;
            break;
        }
        cu = cu->ptr;
    }
    if (cntrl == 0) {
        struct fdata *ne = (struct fdata *) malloc(sizeof(struct fdata));
        ne->ptr = NULL;
        ne->score = score;
        strcpy(ne->name,player1_name);
        cu->ptr=ne;
    }
    show_leaderboard(head,count);
}/// handle kardan esm tekrari va update kardan on dar sorat tekrar.
void add_at_tail(struct fdata *head,char n[],int x) {
    struct fdata *cu=head;
    while(cu->ptr!=NULL){
        cu=cu->ptr;
    }
    struct fdata *ne=(struct fdata *)malloc(sizeof(struct fdata));
    ne->ptr=NULL;
    ne->score=x;
    strcpy(ne->name,n);
    cu->ptr=ne;
}/// afzodan motavaye file be akhar linkedlist.
SDL_Texture *menuTexture(SDL_Renderer *sdlRenderer, char *image_path) {
    SDL_Surface *image = SDL_LoadBMP(image_path);

    /* Let the user know if the file failed to load */
    if (!image) {
        printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
        return 0;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(sdlRenderer, image);

    SDL_FreeSurface(image);
    image = NULL;

    return texture;
}/// baraye load kardan png moshabe code kargah.
void first_menu() {
    SDL_bool menuExit = SDL_FALSE;
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../bc2.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};

    int i=0;
    while (menuExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
        stringColor(sdlrenderer,350,360,"welcome please enter your name",0xFF000000);
        stringColor(sdlrenderer,300,390,"** please press space button when you finish **",0xFF000000);

        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);

        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            if(sdlEvent.type==SDL_QUIT){
                menuExit=SDL_TRUE;
                break;
            }
            else if(sdlEvent.type==SDL_KEYDOWN){
                if(sdlEvent.key.keysym.sym==SDLK_SPACE){
                    menuExit=SDL_TRUE;
                    break;
                }
                player1_name[i]=sdlEvent.key.keysym.sym;
                i++;
            }
        }
    }
    printf("%s",player1_name);
    SDL_Delay(1000);
} /// baraye safhe aval ke moshahede mishavad , event keyboard baraye daryaft esm karbar .
int menu(int *choice) {
    SDL_bool menuExit = SDL_FALSE;
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../background.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};
    char *tip[4] = {"The only way to learn a new programming language is by writing programs in it.",
                    "Testing leads to failure, and failure leads to understanding.",
                    "First, solve the problem. Then, write the code.",
                    "Talk  is  cheap  show  me  the  code."};
    int index = rand() % 4;

    while (menuExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);


        stringColor(sdlrenderer, 450, 25, "state.io", 0xFF000000);
        stringColor(sdlrenderer, 260, 55, tip[index], 0xFF000000);
        stringColor(sdlrenderer,450,140,"hello",0xFF000000);
        stringColor(sdlrenderer,500,140,player1_name,0xFF000000);
        stringColor(sdlrenderer,450,160,"your color is red ",0xFF000000);
        stringColor(sdlrenderer, 450, 240, "random map", 0xFF000000);
        stringColor(sdlrenderer, 450, 300, "choose map", 0xFF000000);
        stringColor(sdlrenderer, 450, 360, "testing map", 0xFF000000);
        stringColor(sdlrenderer, 450, 420, "leaderboard", 0xFF000000);
        stringColor(sdlrenderer, 470, 480, "EXIT", 0xFF000000);

        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            if (sdlEvent.type == SDL_QUIT) {
                menuExit = SDL_TRUE;
                break;
            }
            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
                if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
                    if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                        (220 <= sdlEvent.button.y && sdlEvent.button.y <= 260)) {
                        *choice = 1;
                        menuExit = SDL_TRUE;
                        break;
                    } else if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                               (280 <= sdlEvent.button.y && sdlEvent.button.y <= 320)) {
                        *choice = 2;
                        menuExit = SDL_TRUE;
                        break;
                    } else if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                               (340 <= sdlEvent.button.y && sdlEvent.button.y <= 380)) {
                        *choice = 3;
                        menuExit = SDL_TRUE;
                        break;
                    } else if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                               (400 <= sdlEvent.button.y && sdlEvent.button.y <= 440)) {
                        *choice = 4;
                        menuExit = SDL_TRUE;
                        break;
                    }else if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                              (460 <= sdlEvent.button.y && sdlEvent.button.y <= 500)) {
                        *choice = 5;
                        menuExit = SDL_TRUE;
                        break;
                    }
                }
            }
        }
    }
    SDL_Delay(1000);
    printf("\n menu ok\n");
}/// menu 2 , daraye tip rooz :) , namayesh esm , va event mouse baraye entekhab bakhsh morede nazar.
int choosing_the_map(int *ch) {
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../background.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};
    SDL_bool shallExit = SDL_FALSE;

    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);

        stringColor(sdlrenderer, 450, 300, "map 1", 0xFF000000);
        stringColor(sdlrenderer, 450, 360, "map 2", 0xFF000000);
        stringColor(sdlrenderer, 450, 420, "map 3", 0xFF000000);

        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            if(sdlEvent.type==SDL_QUIT){
                shallExit=SDL_TRUE;
                break;
            }
            else if(sdlEvent.type==SDL_MOUSEBUTTONDOWN){
                if(sdlEvent.button.button==SDL_BUTTON_LEFT){
                    if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&(280 <= sdlEvent.button.y && sdlEvent.button.y <= 320)) {
                        *ch=1;
                        shallExit = SDL_TRUE;
                        break;
                    }
                    else  if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                              (340 <= sdlEvent.button.y && sdlEvent.button.y <= 380)) {
                        *ch=2;
                        shallExit = SDL_TRUE;
                        break;
                    }
                    else  if ((400 < sdlEvent.button.x && sdlEvent.button.x < 600) &&
                              (400 <= sdlEvent.button.y && sdlEvent.button.y <= 440)) {
                        *ch=3;
                        shallExit = SDL_TRUE;
                        break;
                    }
                }
            }
        }
    }
    SDL_Delay(1000);
}/// entekhab map moshakhas 3 ta map , event mouse baraye click
void take_from_file() {
    int temps;
    int count;
    char tempn[20];
    struct fdata *head=NULL;
    head=(struct fdata *)malloc(sizeof(struct fdata));
    FILE *source;
    source=fopen("names&scores.txt","r");
    fscanf(source, "%s",tempn);
    strcpy(head->name,tempn);
    fscanf(source," ");
    fscanf(source,"%d",&temps);
    head->score=temps;
    fscanf(source," ");
    head->ptr=NULL;
    count++;
    while(!feof(source)){
        fscanf(source,"%s",tempn);
        fscanf(source," ");
        fscanf(source,"%d",&temps);
        fscanf(source," ");
        add_at_tail(head,tempn,temps);
        count++;
    }
    fclose(source);
    is_player_rep(head,count);
}//// asami va score ha az file kharej shode va dar linkedlist zakhire mishavad .
int who_is_winner(int count,struct map Map[]) {
    int key1=0;
    int key2=0;
    for(int i=0;i<count;++i) {
        if (Map[i].color1 ==  0xFF0054FF  ) {
            key1=1;
        }
        else if(  Map[i].color1 ==0xFFFF09E1  ||  Map[i].color1 == 0xFF00FF00 ||  Map[i].color1 ==0xFF00FFFF) {
            key2=2;
        }
    }
    if(key1==1 && key2==0){
        return 1;
    }
    else if(key1==0 && key2==2){
        return 2;
    }
    return 0;
}/// taeen inke ma (red) barande im ya bazande .
void show_result(int x) {
    SDL_bool shallExit = SDL_FALSE;
    char cmnd;
    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        if(x==1){
            stringColor(sdlrenderer,400,300,"The winner is:",0xFF000000);
            stringColor(sdlrenderer,400,360,player1_name,0xFF000000);
            score+=20;
        }
        else if(x==2){
            stringColor(sdlrenderer,400,300,player1_name,0xFF000000);
            stringColor(sdlrenderer,400,360,"unfortunately you lost ",0xFF000000);
            score-=10;
        }
        stringColor(sdlrenderer,350,200,"** baraye bargasht be menu m ra befesharid **",0xFF000000);
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    cmnd=sdlEvent.key.keysym.sym;
                    break;
            }
        }
        if(cmnd=='m'){
            shallExit = SDL_TRUE;
            break;
        }
    }
}/// neshoon mide bordi ya bakhti . ba m vared menu mishi .