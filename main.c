#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#ifdef main
#undef main
#endif

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

const int FPS = 60;
const int tool=1000;
const int arz =720;
char player1_name[20];//red
char player2_name[20]="p2";//blue
char player3_name[20]="p3";
char player4_name[20]="p4";
int scores[4][2];
SDL_Window *sdlWindow;
SDL_Renderer *sdlrenderer ;
int choice=0;
int zaman=0;
int time1=0;
int target_time=10;
//***************************************************** functions and structs
struct map{
    int x;
    int y;
    int is_ghale;
    int tedad_sol;
    Uint32 color1;
    Uint32 color2;
};
struct att_sol{
    int spell_type;///type of spell,                                0 ------> majooni mojod nist ,
    float power;///tasir sarbaz bar ghale harif,                    1 ------> Xx kardan speed  DONE
    int speed;///speed of soliders,                                 2 ------> taghir power be 2 ya 0.5
    int  att;                                                ///    3 ------> taghir power be -1
                                                               //// 4----> att yani tavanayi hamle 0 ya 1
};
void remove_alone_pieces(int m,int xy[][m]){
    for(int i=0;i<7;++i){
        for(int j=0;j<m;++j){
            if(xy[i][j]!=0){
                if(i==0&&j==0){
                    if(xy[i][j+1]==0&&xy[i+1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else if(i==6&&j==0){
                    if(xy[i-1][j]==0&&xy[i][j+1]==0){
                        xy[i][j]=0;
                    }
                }
                else if(i==6&&j==m-1){
                    if(xy[i-1][j]==0&&xy[i][j-1]==0){
                        xy[i][j]=0;
                    }
                }
                else if(i==0&&j==m-1){
                    if(xy[i][j-1]==0&&xy[i+1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else if(i==0&&(0<j&&j<m-1)){
                    if(xy[i][j+1]==0&&xy[i][j-1]==0&&xy[i+1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else if(i==6&&(0<j&&j<m-1)){
                    if(xy[i][j+1]==0&&xy[i][j-1]==0&&xy[i-1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else if(j==0&&(0<i&&i<6)){
                    if(xy[i][j+1]==0&&xy[i+1][j]==0&&xy[i-1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else if(j==m-1&&(0<i&&i<6)){
                    if(xy[i][j-1]==0&&xy[i+1][j]==0&&xy[i-1][j]==0){
                        xy[i][j]=0;
                    }
                }
                else{
                    if(xy[i][j-1]==0&&xy[i+1][j]==0&&xy[i-1][j]==0&&xy[i][j+1]==0){
                        xy[i][j]=0;
                    }
                }
            }
        }
    }
}
int empty(int x,int kingx[],int y,int kingy[],int index,int xy[][x]){
   int X[9]={0,1,2,3,4,5,6,7,8};
   int Y[7]={0,1,2,3,4,5,6};
   for(int i=0;i<9;++i){
       if(X[i]!=kingx[0]&&X[i]!=kingx[1]&&X[i]!=kingx[2]&&X[i]!=kingx[3]){
           kingx[index]=X[i];
           break;
       }
   }
   for(int j=0;j<7;++j){
       if(Y[j]!=kingy[0]&&Y[j]!=kingy[1]&&Y[j]!=kingy[2]&&Y[j]!=kingy[3]){
           kingy[index]=Y[j];
           break;
       }
   }
}
void check(int kingx[],int kingy[],int n,int m,int xy[][m]){
    srand(time(0));
    kingy[0]=0;
    kingy[1]=2;
    kingy[2]=4;
    kingy[3]=6;
    int tedad[4]={0};
    for(int i=0;i<m;++i){
        if(xy[kingy[0]][i]!=0 && tedad[0]==0){
            kingx[0]=i;
            tedad[0]++;
        }
        if(xy[kingy[2]][i]!=0 && tedad[2]==0){
            kingx[2]=i;
            tedad[2]++;
        }
    }
    for(int i=m-1;i>=0;--i){
        if(xy[kingy[1]][i]!=0 && tedad[1]==0){
            kingx[1]=i;
            tedad[1]++;
        }
        if(xy[kingy[3]][i]!=0 && tedad[3]==0){
            kingx[3]=i;
            tedad[3]++;
        }
    }
}
void ghale(int n,int m,int xy[][m],int count,struct map Map[],struct att_sol attSol[]){
    int kingx[4];
    int kingy[4];

    check(kingx,kingy,7,9,xy);
    int k=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(xy[i][j]!=0){
                Map[k].x=(j*80)+120;
                Map[k].y=(i*80)+120;
                attSol[k].spell_type=0;
                attSol[k].power=1;
                attSol[k].speed=1;
                attSol[k].att=1;
                if(kingx[0]==j&&kingy[0]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[1]==j&&kingy[1]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[2]==j&&kingy[2]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[3]==j&&kingy[3]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else {
                    Map[k].is_ghale = 0;
                    Map[k].tedad_sol = 0;
                }
                k++;
            }
        }
    }

}
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
}
void first_menu(){

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
    //  SDL_DestroyWindow(sdlWindow);
    printf("\n Hello World\n");
    //   SDL_Quit();
}
int menu(int *choice) {

    SDL_bool menuExit = SDL_FALSE;

    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../background.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};

    char *tip[4] = {"The only way to learn a new programming language is by writing programs in it.",
                    "Testing leads to failure, and failure leads to understanding.",
                    "First, solve the problem. Then, write the code.",
                    "talk  is  cheap  show  me  the  code."};
    int index = rand() % 4;
    while (menuExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);

        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);


        stringColor(sdlrenderer, 450, 25, "state.io", 0xFF000000);
        stringColor(sdlrenderer, 260, 55, tip[index], 0xFF000000);
        stringColor(sdlrenderer,450,140,"hello",0xFF000000);
        stringColor(sdlrenderer,500,140,player1_name,0xFF000000);
        stringColor(sdlrenderer, 450, 240, "random map", 0xFF000000);
        stringColor(sdlrenderer, 450, 300, "choose map", 0xFF000000);
        stringColor(sdlrenderer, 450, 360, "load game", 0xFF000000);
        stringColor(sdlrenderer, 450, 420, "leaderboard", 0xFF000000);

        ////delay render
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);

//// event marboot be khroj az window.
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            if (sdlEvent.type == SDL_QUIT) {
                menuExit = SDL_TRUE;
                break;
            } else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
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
                    }
                }
            }
        }
    }

    SDL_Delay(1000);
    // SDL_DestroyWindow(sdlWindow);
    printf("\n menu ok\n");
    //SDL_Quit();
}
void random_map_pieces(int n,int m,int randomxy[][m],int count,struct map Map[],struct att_sol attSol[]){

    //remove_alone_pieces(m, randomxy);
    ghale(7,9,randomxy,count,Map,attSol);
}
int choosing_the_map(int *ch){

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


//// event marboot be khroj az window.
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
    // SDL_DestroyWindow(sdlWindow);

    printf("\n Hello World\n");
    // SDL_Quit();
}
void specific_castles(int castlex[],int castley[],int ch){
    if(ch==1){
        castlex[0]=440;
        castley[0]=280;
        castlex[1]=760;
        castley[1]=120;
        castlex[2]=120;
        castley[2]=600;
        castlex[3]=600;
        castley[3]=600;
    }
    else if(ch==2){
        castlex[0]=200;
        castley[0]=120;
        castlex[1]=680;
        castley[1]=120;
        castlex[2]=120;
        castley[2]=520;
        castlex[3]=680;
        castley[3]=520;
    }
    else if(ch==3){
        castlex[0]=280;
        castley[0]=360;
        castlex[1]=360;
        castley[1]=120;
        castlex[2]=280;
        castley[2]=600;
        castlex[3]=760;
        castley[3]=520;
    }
}
void specific_ghale(int n,int m,int xy[][m],int count,struct map Map[],int ch){
    int castlex[4];
    int castley[4];
    specific_castles(castlex,castley,ch);
    int k=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(xy[i][j]!=0){
                Map[k].x=j*80+120;
                Map[k].y=i*80+120;
                Map[k].tedad_sol=0;
                if(castlex[0]==j*80+120&&castley[0]==i*80+120)
                    Map[k].is_ghale=1;
                else if(castlex[1]==j*80+120&&castley[1]==i*80+120)
                    Map[k].is_ghale=1;
                else if(castlex[2]==j*80+120&&castley[2]==i*80+120)
                    Map[k].is_ghale=1;
                else if(castlex[3]==j*80+120&&castley[3]==i*80+120)
                    Map[k].is_ghale=1;
                else
                    Map[k].is_ghale=0;

                k++;
            }
        }
    }
}
void specific_map(int n,int m,int xy[][m],int ch,int count,struct map Map[]){

    remove_alone_pieces(m, xy);
    specific_ghale(7,9,xy,count,Map,ch);
}
void sort_scores(){
    for(int i=1;i<4;++i){
        for(int i=0;i<3;++i){
            if(scores[i][0]<scores[i+1][0]){
                int h= scores[i][0];
                scores[i][0]=scores[i+1][0];
                scores[i+1][0]=h;
                h= scores[i][1];
                scores[i][1]=scores[i+1][1];
                scores[i+1][1]=h;
            }
        }
    }
}
void show_leaderboard(){
    sort_scores();
    SDL_bool shallExit = SDL_FALSE;
    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);

        roundedBoxColor(sdlrenderer, 250, 240, 750, 480,1, 0xFF000000);
        thickLineColor(sdlrenderer, 250, 300, 750, 300, 1, 0xFF000000);
        thickLineColor(sdlrenderer, 250, 360, 750, 360, 1, 0xFF000000);
        thickLineColor(sdlrenderer, 250, 420, 750, 420, 1, 0xFF000000);
        for (int i = 0; i < 4; ++i) {
            if (scores[i][1] == 1) {
                stringColor(sdlrenderer, 260, 270 + i * 60, player1_name, 0xFF000000);
            } else if (scores[i][1] == 2) {
                stringColor(sdlrenderer, 260, 270 + i * 60, player2_name, 0xFF000000);
            } else if (scores[i][1] == 3) {
                stringColor(sdlrenderer, 260, 270 + i * 60, player3_name, 0xFF000000);
            } else if (scores[i][1] == 4) {
                stringColor(sdlrenderer, 260, 270 + i * 60, player4_name, 0xFF000000);
            }
        }

////delay render
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
//// event marboot be khroj az window.

        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
            }
        }
    }
    SDL_Delay(1000);


    printf("\n Hello World\n");
}
void color_of_map(int c,struct map Map[]){
    int t=0;
    for(int i=0;i<c;++i){
        if(Map[i].is_ghale==1){
            if(t==0){
                Map[i].color1= 0xFF0054FF;//// red
                Map[i].color2= 0xFF0000B8;
            }
            else if(t==1){
                Map[i].color1= 0xFFFF09E1;/// blue
                Map[i].color2= 0xFF079191;
            }
            else if(t==2){
                Map[i].color1=0xFF00FF00;/// yellow
                Map[i].color2= 0xFF004600;
            }
            else if(t==3){
                Map[i].color1= 0xFF00FFFF;/// green
                Map[i].color2= 0xFF007DFF;
            }
            t++;
        }
        else{
            Map[i].color1= 0xFF998877;
            Map[i].color2= 0xFF000000;
        }
    }
}
void wich_ghale(int xm,int ym,int count,struct map Map[],int *X,int *Y,int *I){
    for(int i=0;i<count;++i){
        if((Map[i].x-40<xm&&xm<Map[i].x+40)&&(Map[i].y-40<ym&&ym<Map[i].y+40)){
            *X=Map[i].x;
            *Y=Map[i].y;
            *I=i;
            break;
        }
    }
}
void amount_of_soliders(int i,int j,struct map Map[],struct att_sol attSol[]){
    if(Map[i].color1==Map[j].color1){
        Map[j].tedad_sol=Map[i].tedad_sol+Map[j].tedad_sol;
        Map[i].tedad_sol=0;
    }

    else if(Map[i].tedad_sol*attSol[i].power>Map[j].tedad_sol){
        Map[j].tedad_sol=Map[i].tedad_sol*attSol[i].power- Map[j].tedad_sol;
        Map[j].color1=Map[i].color1;
        Map[j].color2=Map[i].color2;
        Map[j].is_ghale=1;
        Map[i].tedad_sol=0;

    }
    else if(Map[i].tedad_sol*attSol[i].power<Map[j].tedad_sol){
        Map[j].tedad_sol= Map[j].tedad_sol- Map[i].tedad_sol*attSol[i].power;
        Map[i].tedad_sol=0;
    }
    else if(Map[i].tedad_sol*attSol[i].power==Map[j].tedad_sol){
        Map[i].tedad_sol=Map[j].tedad_sol=0;
    }
}
void changing_attribute1(int c,struct map Map[],struct att_sol attSol[],int index,int s){
    Uint32 tcolor=Map[index].color1;
    for(int i=0;i<c;++i){
        if(Map[i].color1==tcolor){
            attSol[i].speed=s;
            //printf("speed of %d : %d \n",i,attSol[i].speed);
        }
    }
}
void changing_attribute23(int c,struct map Map[],struct att_sol attSol[],int index,int temp){
    srand(time(0));
    float ran;
    if(temp==0) {
        if (rand() % 2 == 0) {
            ran = 0.5;
        } else {
            ran = 2.0;
        }
    }
    else if(temp==1){
        ran=-1.0;
    }
    else if(temp==2){
        ran=1.0;
    }
    Uint32 tcolor=Map[index].color1;
    for(int i=0;i<c;++i){
        if(tcolor==Map[i].color1){
            attSol[i].power=ran;
        }
    }
}
void changing_attribute4(int c,struct map Map[],struct att_sol attSol[],int index,int bool){
    Uint32 tcolor=Map[index].color1;
    for(int i=0;i<c;++i){
        if(tcolor==Map[i].color1){
            attSol[i].att=bool;
        }
    }
}
void rest_attri(int c,struct map Map[],struct att_sol attSol[],int index,int ran){

    if(ran==1) {
        changing_attribute1(c, Map, attSol, index, 1);
    }
    else if(ran==2) {
        changing_attribute23(c, Map, attSol, index, 2);

    }
    else if(ran==3) {
        changing_attribute23(c, Map, attSol, index, 2);
    }
    else if(ran==4) {
        changing_attribute4(c, Map, attSol, index, 1);
    }
}
void wich_spell(int c,struct map Map[],struct att_sol attSol[],int index,int ran){

   if(ran==1) {
           changing_attribute1(c, Map, attSol, index, 10);
   }
  else if(ran==2) {
           changing_attribute23(c, Map, attSol, index, 0);
   }
  else if(ran==3) {
       changing_attribute23(c, Map, attSol, index, 1);
   }
      else if(ran==4) {
       changing_attribute4(c, Map, attSol, index, 0);
   }
}
void change_spell_type(int count,struct map Map[],struct att_sol attSol[],Uint32 color,int bool){
   for(int i=0;i<count;++i){
       if(Map[i].color2==color){
           attSol[i].spell_type=bool;
       }
   }
}
void moving_mouse_soliders(int count,struct map Map[],int xm1,int ym1,int xm2,int ym2,struct att_sol attSol[],int X,int Y,int *kk,
                           int ran,int *mahv,int is,Uint32 *color) {
    SDL_Event sdlEvent;
    int key = 0;
    while (SDL_PollEvent(&sdlEvent) || 1) {
        if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&xm2, &ym2);
            key = 1;
            break;
        }
    }
    SDL_bool shallexit = SDL_TRUE;
    //  printf("X: %d       y: %d\n",xm1,ym1);
    //  printf("*x: %d   *y: %d\n",xm2,ym2);
    int xs, ys, xd, yd;
    int id;
    wich_ghale(xm1, ym1, count, Map, &xs, &ys, &is);
    wich_ghale(xm2, ym2, count, Map, &xd, &yd, &id);
    printf("if  %d\n", is);
    //  printf(" X: %d       y: %d\n",xs,ys);
    // printf("*x: %d   *y: %d\n",xd,yd);
    int s = 1;
    int k = 0;
    int sol[Map[is].tedad_sol];
    int x[Map[is].tedad_sol];
    int y[Map[is].tedad_sol];
    for (int l = 0; l < Map[is].tedad_sol; ++l) {
        sol[l] = l;
        x[l] = Map[is].x;
        y[l] = Map[is].y;
    }

    while (key == 1 && shallexit == SDL_TRUE) {
        if (k == 15) {
            for (int j = 0; j < Map[is].tedad_sol; ++j) {
                if (sol[j] != 0)
                    sol[j]--;
            }
            k = 0;
        }
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        for (int i = 0; i < count; ++i) {
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
        }
 /*       if(zaman>0&&zaman<30){
            filledEllipseColor(sdlrenderer,X,Y,30,20,0xFFBC0CFF);
            stringColor(sdlrenderer,X-25,Y,"spell",0xFF000000);
            ellipseColor(sdlrenderer,X,Y,30,20,0xFFB800B8);
        }*/
        for (int j = 0; j < Map[is].tedad_sol; ++j){
            filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
        if (sol[j] == 0) {
           // printf("velocity of %d is : %d\n",is,attSol[is].speed);
            if (x[j] != xd) {
                if (x[j] > xd) {
                    x[j] -= attSol[is].speed;
                }
                else {
                    x[j] += attSol[is].speed;
                }
            }
            if (y[j] != yd) {
                if (y[j] > yd) {
                    y[j] -= attSol[is].speed;
                }
                else {
                    y[j] += attSol[is].speed;
                }
            }
        }
    }



            if (x[Map[is].tedad_sol - 1] == xd && y[Map[is].tedad_sol - 1] == yd) {
                shallexit = SDL_FALSE;
                if (time1 >= target_time && xd == X && yd == Y) {
                    *kk = 1;
                    key = 0;
                    *mahv = 0;
                    *color=Map[is].color2;
                    change_spell_type(count,Map,attSol,*color,ran);
                }

                amount_of_soliders(is, id, Map, attSol);
            }
            if (*kk == 1) {
                wich_spell(count, Map, attSol, is, ran);
            }

            SDL_RenderPresent(sdlrenderer);
            SDL_Delay(250 / FPS);
            //  printf("**%d**\n",zaman);
            k++;
            if (x[Map[is].tedad_sol - 1] == xd && y[Map[is].tedad_sol - 1] == yd) {
                shallexit = SDL_FALSE;
                break;
            }
        }
//return is;
    }

int is_your_ghale(int x,int y,int count,struct map  Map[]){
    for(int i=0;i<count;++i){
        if((Map[i].x-40<x&&x<Map[i].x+40)&&(Map[i].y-40<y&&y<Map[i].y+40)){
            if(Map[i].color1==0xFF0054FF){
                return i;
            }
            else{
                return -1;
            }
        }
    }
}
int who_is_winner(int count,struct map Map[]){
    int key1=0;
    int key2=0;
    int key3=0;
    int key4=0;
    for(int i=0;i<count;++i){
        if(Map[i].color1==0xFF998877||Map[i].color1==0xFF0054FF){
            key1=1;
        }
        else if(Map[i].color1==0xFF998877||Map[i].color1== 0xFFFF09E1){
            key2=2;
        }
        else if(Map[i].color1==0xFF998877||Map[i].color1==0xFF00FF00){
            key3=3;
        }
        else if(Map[i].color1==0xFF998877||Map[i].color1==0xFF00FFFF){
            key4=4;
        }
    }
    if(key1==1&&key2==0&&key3==0&&key4==0){
        return 1;
    }
    else if(key1==0&&key2==2&&key3==0&&key4==0){
        return 2;
    }
    else if(key1==0&&key2==0&&key3==3&&key4==0){
        return 3;
    }
    else if(key1==0&&key2==0&&key3==0&&key4==4){
        return 4;
    }
    else{
        return 0;
    }
}
void show_result(int x) {
    SDL_bool shallExit = SDL_FALSE;
    char cmnd[5];
    int i=0;
    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        stringColor(sdlrenderer,400,300,"The winner is:",0xFF000000);
        if(x==1){
            stringColor(sdlrenderer,400,360,player1_name,0xFF000000);
        }
        else if(x==2){
            stringColor(sdlrenderer,400,360,player2_name,0xFF000000);
        }
        else if(x==3){
            stringColor(sdlrenderer,400,360,player3_name,0xFF000000);
        }
        else if(x==4){
            stringColor(sdlrenderer,400,360,player4_name,0xFF000000);
        }
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(1000 / FPS);
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    cmnd[i]=sdlEvent.key.keysym.sym;
                    i++;
            }
            cmnd[4]='\0';
            if(cmnd=="menu"){
                menu(&choice);
            }
        }
    }
}
void changing_the_scores(int x){
    for(int i=0;i<4;++i){
        if(scores[i][1]==x){
            scores[i][0]+=20;
        }
        else{
            scores[i][0]-=10;
        }
    }
}
void random_spell_xy(int *x,int *y,int n,int m,int xy[][m],int c,struct map Map[]){
    srand(time(0));
    int ran=rand()%c;
    if(Map[ran].color1==0xFF998877){
        *x= Map[ran].x;
        *y=Map[ran].y;
    }
}
int des_coordinate(int index,int c,struct map Map[],struct att_sol attSol[]){
   int karan[4]={0,10,20,30};
    srand(time(0));
   int random=rand()%5;///0 1 -->toosi       2 3 4 --> Rangi
   //printf("des_coor : %d\n",random);
           for(int i=karan[rand()%4];i<c;++i){
               if(random==0||random==1){
        if(Map[i].color1==0xFF998877 && Map[i].tedad_sol<=Map[index].tedad_sol){
            return i;
        }
        }
               else{
                   if(Map[i].color1!=Map[index].color1 && Map[i].tedad_sol<=Map[index].tedad_sol && Map[i].color1!=0xFF998877){
                       return i;
                   }
               }
    }
           return -1;
}
void bot_rendering(int X,int Y,int is,int c,struct map Map[],struct att_sol attSol[],int ran,int *mahv,int *kk){
 int id  = des_coordinate(is,c,Map,attSol);
 if(id==-1){
     return ;
 }
 int xd=Map[id].x,yd=Map[id].y;
 SDL_bool shallexit=SDL_TRUE;
    int sol[Map[is].tedad_sol];
    int x[Map[is].tedad_sol];
    int y[Map[is].tedad_sol];
    int att_time=0;
    for (int l = 0; l < Map[is].tedad_sol; ++l) {
        sol[l] = l;
        x[l] = Map[is].x;
        y[l] = Map[is].y;
    }
 while(shallexit==SDL_TRUE){
     if (att_time == 15) {
         for (int j = 0; j < Map[is].tedad_sol; ++j) {
             if (sol[j] != 0)
                 sol[j]--;
         }
         att_time=0;
     }
     SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
     SDL_RenderClear(sdlrenderer);
     for (int i = 0; i < c; ++i) {
         filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
         filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                           Map[i].color2);
         char c[4];
         sprintf(c, "%d", Map[i].tedad_sol);
         stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
     }
     for (int j = 0; j < Map[is].tedad_sol; ++j){
         filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
         if (sol[j] == 0) {
             if (x[j] != xd) {
                 if (x[j] > xd) {
                     x[j] -= attSol[is].speed;
                 } else {
                     x[j] += attSol[is].speed;
                 }
             }
             if (y[j] != yd) {
                 if (y[j] > yd) {
                     y[j] -= attSol[is].speed;
                 } else {
                     y[j] += attSol[is].speed;
                 }
             }
         }
     }
     if (x[Map[is].tedad_sol - 1] == xd && y[Map[is].tedad_sol - 1] == yd) {
         shallexit = SDL_FALSE;
       /*  if (time1 >= target_time && xd == X && yd == Y) {
             *kk = 1;
             key = 0;
             *mahv = 0;
             attSol[is].spell_type=ran;
         }*/
         amount_of_soliders(is, id, Map, attSol);
     }
    /* if (*kk == 1) {
         wich_spell(count, Map, attSol, is, ran, 0);
     }*/

     SDL_RenderPresent(sdlrenderer);
     SDL_Delay(250 / FPS);//250
     //  printf("**%d**\n",zaman);
     att_time++;
     if (x[Map[is].tedad_sol - 1] == xd && y[Map[is].tedad_sol - 1] == yd) {
         shallexit = SDL_FALSE;
         break;
     }
 }
 }
void bot_coordinate(int key,Uint32 color ,int c,struct map Map[],struct att_sol attSol[],int ran,int *mahv,int *kk,int *is){
    if(key==0){
        return ;
    }
    else{
        int coo[c][3];
        int k=0;
        for(int i=0;i<c;++i){
            if(Map[i].color1==color){
                coo[k][0]=Map[i].x;
                coo[k][1]=Map[i].y;
                coo[k][2]=i;
                k++;
            }
        }
        if(k==0){
            return ;
        }
       // printf("k in bot_coo : %d\n",k);
        srand(time(0));
        int random=rand()%k;
        *is = coo[random][2];
        bot_rendering(coo[random][0],coo[random][1],coo[random][2],c,Map,attSol,ran,mahv,kk);
    }
}
void bots_gate(int c,struct map Map[],struct att_sol attSol[],int ran,int *mahv,int *kk,int *is) {
    srand(time(0));
    bot_coordinate(rand()%2,0xFFFF09E1,c,Map,attSol,ran,mahv,kk,is); /// blue ,
    bot_coordinate(rand()%2,0xFF00FF00,c,Map,attSol,ran,mahv,kk,is); ///green
    bot_coordinate(rand()%2, 0xFF00FFFF,c,Map,attSol,ran,mahv,kk,is); ///yellow
}

int main (){
    for(int i=0;i<4;++i){
        scores[i][0]=0;
        scores[i][1]=i+1;
    }
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("moshkel barat pish amade. %s\n", SDL_GetError());
        return 0;
    }
    sdlWindow =  SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, tool,arz, SDL_WINDOW_OPENGL);
    sdlrenderer = SDL_CreateRenderer(sdlWindow, -1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    first_menu();

    menu(&choice);

    if(choice==1) {
        srand(time(0));
        int count = 0;
        SDL_bool shallExit = SDL_FALSE;
        int randomxy[7][9];
        srand(time(0));
        int n = 7, m = 9;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                randomxy[i][j] = rand() % 4;
                if (randomxy[i][j] != 0) {
                    count++;
                }
            }
        }
        struct map Map[count];
        struct att_sol attSol[count];

        random_map_pieces(7, 9, randomxy, count, Map,attSol);
        color_of_map(count, Map);
       // printf("%d",count);
      /*  for(int i=0;i< count;++i){

            printf("x: %d  y: %d\n",Map[i].x,Map[i].y);
        }*/
        int xs,ys,xd,yd;
        int xm1,ym1;
        int xm2,ym2;
        int is,id;
        int isb;
        int result;
        int key2=0;
        int mahv=1;
        int bots_time=0;
        int bt_target=rand()%10+10;
        Uint32 color_ghale_spell;
        SDL_Event sdlEvent;
        int X,Y;
        random_spell_xy(&X,&Y,7,9,randomxy,count,Map);
        srand(time(0));
        int ran=0;//rand()%3;
        ran++;

        ///in tike khodesh ye tabe mohem.
//*******************************************************************************************************
        while (shallExit == SDL_FALSE) {
            printf("t:%d & z:%d  &r:%d\n", time1, zaman, ran);


            SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(sdlrenderer);
///spell handling.
            if (zaman == 30) {
                rest_attri(count, Map, attSol, is, ran);
                key2 = 0;
                zaman = 0;
                time1 = 0;
                change_spell_type(count, Map, attSol, color_ghale_spell, 0);
                color_ghale_spell = 0xFF000000;
                random_spell_xy(&X, &Y, 7, 9, randomxy, count, Map);
                srand(time(0));
                ran = 0;//rand()%3;
                ran++;
                mahv = 1;
            }  ///Handling The Time Of Each Spell.
            if (zaman > 0 && zaman < 30) {
                change_spell_type(count, Map, attSol, color_ghale_spell, ran);
            }
            for (int i = 0; i < count; ++i) { ///Baraye Render Kardan e Spell Va Map.
           /* if(Map[i].color1==color_ghale_spell) {
                printf("speed:%d\n", attSol[i].speed);
            }*/
                filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
                filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x,
                                  Map[i].y + 10,
                                  Map[i].color2);
                char c[4];
                sprintf(c, "%d", Map[i].tedad_sol);
                stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
                if (attSol[i].spell_type == ran) {
                    stringColor(sdlrenderer, Map[i].x - 22, Map[i].y, "++", Map[i].color2);
                    stringColor(sdlrenderer, Map[i].x + 22, Map[i].y, "++", Map[i].color2);
                    stringColor(sdlrenderer, Map[i].x, Map[i].y - 22, "++", Map[i].color2);
                    stringColor(sdlrenderer, Map[i].x, Map[i].y + 22, "++", Map[i].color2);
                }
                if (time1 >= target_time && mahv == 1) {
                    filledEllipseColor(sdlrenderer, X, Y, 30, 20, 0xFFBC0CFF);
                    stringColor(sdlrenderer, X - 25, Y, "spell", 0xFF000000);
                    ellipseColor(sdlrenderer, X, Y, 30, 20, 0xFFB800B8);
                }
            }
            /*if(bots_time>=bt_target){
                bots_gate(count,Map,attSol,ran,&mahv,&key2,&isb);
                bots_time=0;
            }*/
            SDL_RenderPresent(sdlrenderer);
            SDL_Delay(50000 / FPS);

            bots_time++;

///zaman e mandegari har spell
            if (key2 == 1) {
                zaman++;
            }
/// time namayan shodan spell jadid.
            time1++;
            //   printf("**%d**\n",zaman);
/// afzayesh sarbaz ha.
            for (int i = 0; i < count; ++i) {
                if (Map[i].is_ghale == 1 && Map[i].tedad_sol < 100)
                    Map[i].tedad_sol++;
            }
/// event khoroj va mouse .
            while (SDL_PollEvent(&sdlEvent)) {
                switch (sdlEvent.type) {
                    case SDL_QUIT:
                        shallExit = SDL_TRUE;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_GetMouseState(&xm1, &ym1);
                        int is = is_your_ghale(xm1, ym1, count, Map);
                        printf("%d\n", is);
                        if (is != -1 && attSol[is].att == 1) {
                            moving_mouse_soliders(count, Map, xm1, ym1, xm2, ym2, attSol, X, Y, &key2, ran, &mahv, is,
                                                  &color_ghale_spell);
                        }
                        break;
                }
            }
/// agar barande moshakhas ast bazi tamom ast.
            result = who_is_winner(count, Map);
            if (result) {
                break;
            }
        }
        //************************************************************************************
        show_result(result);
        changing_the_scores(result);

        SDL_Delay(1000);
        printf("\n Hello World\n");
    }

    else if(choice==2){
        int ch = 0;
        choosing_the_map(&ch);
        SDL_bool shallExit = SDL_FALSE;
        srand(time(0));

        int count = 0;
        int xy[7][9];
        if (ch == 1) {
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (i % 4 + j % 3 != 0 && i % 4 + j % 3 != 1) {
                        xy[i][j] = 1;
                        count++;
                    } else
                        xy[i][j] = 0;
                }
            }
        } else if (ch == 2) {
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (i % 2 + j % 2 != 0) {
                        xy[i][j] = 1;
                        count++;
                    } else {
                        xy[i][j] = 0;
                    }
                }
            }
        } else if (ch == 3) {
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (i % 3 + j % 4 != 0 && i % 3 + j % 4 != 1) {
                        xy[i][j] = 1;
                        count++;
                    } else {
                        xy[i][j] = 0;
                    }
                }
            }
        }

        struct map Map[count];
        specific_map(7, 9, xy, ch, count, Map);

        color_of_map(count, Map);

        while (shallExit == SDL_FALSE) {
            SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
            SDL_RenderClear(sdlrenderer);

            for (int i = 0; i < count; ++i) {
                filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
                filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                                  Map[i].color2);
            }
            SDL_RenderPresent(sdlrenderer);
            SDL_Delay(1000 / FPS);

            SDL_Event sdlEvent;
            while (SDL_PollEvent(&sdlEvent)) {
                switch (sdlEvent.type) {
                    case SDL_QUIT:
                        shallExit = SDL_TRUE;
                        break;
                }
            }
        }

        SDL_Delay(1000);
        printf("\n Hello World\n");
    }

    else if(choice==3){


        SDL_bool shallExit = SDL_FALSE;

        while (shallExit == SDL_FALSE) {
            SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
            SDL_RenderClear(sdlrenderer);
            SDL_RenderPresent(sdlrenderer);
            SDL_Delay(1000 / FPS);

            SDL_Event sdlEvent;
            while (SDL_PollEvent(&sdlEvent)) {
                switch (sdlEvent.type) {
                    case SDL_QUIT:
                        shallExit = SDL_TRUE;
                        break;
                }
            }
        }
        SDL_Delay(1000);
        SDL_DestroyWindow(sdlWindow);

        printf("\n Hello World\n");
        SDL_Quit();

    }

    else if(choice==4){
        show_leaderboard();
    }
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}