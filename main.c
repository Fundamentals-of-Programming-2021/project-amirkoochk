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
char player1_name[20];
char player2_name[20]="ArshiA";
char player3_name[20]="parham";
char player4_name[20]="parsa";
int scores[4][2];
 SDL_Window *sdlWindow;
 SDL_Renderer *sdlrenderer ;
//***************************************************** functions and structs

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
}////tike haye tanha ra hazf mikonad.
void coordinate(int x[],int y[],int n,int xy[][n]){

    for(int j=0;j<9;++j){
        x[j]=120+80*j;
    }
    for(int i=0;i<7;++i){
        y[i]=120+80*i;
    }

}////mokhtasat markaz ha.
void random_castles(int cx[],int cy[],int x[],int y[],int xy[][9]){
    srand(time(0));
    int rx[4];
    int ry[4];
    for(int i=0;i<4;++i){
       int X=rand()%9;
       int Y=rand()%7;
        if(xy[Y][X]==0){
            i--;
        }
        else{
            rx[i]=x[X];
            ry[i]=y[Y];
        }
    }
    for(int i=1;i<4;++i){
        for(int j=0;j<3;++j){
            if(rx[j]==rx[j+1]&&ry[j]==ry[j+1]){
                rx[j]=x[(rx[j]+3)%9];
                ry[j]=x[(ry[j]+3)%7];
            }

        }
    }
    for(int i=0;i<4;++i){
        cy[i]=ry[i];
        cx[i]=rx[i];
    }
}////mokhtasat ghale ha.
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
    printf("\n Hello World\n");
    //SDL_Quit();
}
void random_map_pieces(int n,int m,int randomxy[][m],int randomx[],int randomy[],int castlex[],int castley[]){
    srand(time(0));
////randomxy baraye noghat random ke bayad dayere dashte bashand ya na.

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            randomxy[i][j] = rand() % 5;
        }
    }
    remove_alone_pieces(m, randomxy);
////randomx & randomy baray mokhtasat marakez.

coordinate(randomx, randomy, n, randomxy);
////mokhtasat random ghale ha.

    random_castles(castlex, castley, randomx, randomy, randomxy);
    for (int i = 0; i < 4; ++i) {
        printf("x :%d   y :%d\n", castlex[i], castley[i]);
    }
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
void specific_castles(int castlex[],int castley[],int x[],int y[],int xy[][9],int ch){
 if(ch==1){
     castlex[0]=x[4];
     castley[0]=y[2];
     castlex[1]=x[8];
     castley[1]=y[0];
     castlex[2]=x[0];
     castley[2]=y[6];
     castlex[3]=x[8];
     castley[3]=y[6];
 }
   else if(ch==2){
     castlex[0]=x[1];
     castley[0]=y[0];
     castlex[1]=x[7];
     castley[1]=y[0];
     castlex[2]=x[0];
     castley[2]=y[5];
     castlex[3]=x[7];
     castley[3]=y[5];
   }
   else if(ch==3){
     castlex[0]=x[2];
     castley[0]=y[3];
     castlex[1]=x[3];
     castley[1]=y[0];
     castlex[2]=x[2];
     castley[2]=y[6];
     castlex[3]=x[8];
     castley[3]=y[5];
   }
}
void specific_map(int n,int m,int xy[][m],int x[],int y[],int castlex[],int castley[],int ch){
    srand(time(0));
////randomxy baraye noghat random ke bayad dayere dashte bashand ya na.
if(ch==1) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(i%4+j%3!=0&&i%4+j%3!=1)
            xy[i][j] =1 ;
            else
                xy[i][j] =0 ;
        }
    }
}

else if(ch==2){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i%2+j%2!=0) {
            xy[i][j]=1;
        }
            else{
            xy[i][j]=0;
            }
        }
        }
    }

else if(ch==3){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i%3+j%4!=0&&i%3+j%4!=1){
                xy[i][j]=1;
            }
            else{
                xy[i][j]=0;
            }
            }
        }
    }

    remove_alone_pieces(m, xy);
////randomx & randomy baray mokhtasat marakez.

    coordinate(x, y, m, xy);
////mokhtasat random ghale ha.

    specific_castles(castlex, castley, x, y, xy,ch);
    for (int i = 0; i < 4; ++i) {
        printf("x :%d   y :%d\n", castlex[i], castley[i]);
    }
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
void   show_leaderboard(){
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
int choice=0;
menu(&choice);

if(choice==1) {
////srand baraye random num
    srand(time(0));



    SDL_bool shallExit = SDL_FALSE;

    srand(time(0));
////randomxy baraye noghat random ke bayad dayere dashte bashand ya na.
    int randomxy[7][9];
    int randomx[9],randomy[7];
    int castlex[4],castley[4];
    random_map_pieces(7,9,randomxy,randomx,randomy,castlex,castley);
    ////havaset bashe while bara namayesh tasavir va event ha va .....
    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
////for baraye rang ghale ha va sarbaz khoone.
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (randomxy[i][j] != 0) {
                    if (randomx[j] == castlex[0] && randomy[i] == castley[0]) {
                        Uint32 color = 0xFF0054FF;//red
                        Sint16 x = randomx[j];
                        Sint16 y = randomy[i];
                        Uint32 colort = 0xFF0000B8;
                        filledCircleColor(sdlrenderer, x, y, 40, color);
                        filledTrigonColor(sdlrenderer, x + 10, y, x - 10, y, x, y + 10, colort);
                    }
                    else if (randomx[j] == castlex[1] && randomy[i] == castley[1]) {
                        Uint32 color = 0xFFFF09E1;//blue
                        Sint16 x = randomx[j];
                        Sint16 y = randomy[i];
                        Uint32 colort = 0xFF079191;
                        filledCircleColor(sdlrenderer, x, y, 40, color);
                        filledTrigonColor(sdlrenderer, x + 10, y, x - 10, y, x, y + 10, colort);
                    }
                    else if (randomx[j] == castlex[2] && randomy[i] == castley[2]) {
                        Uint32 color = 0xFF00FF00;//sabz
                        Sint16 x = randomx[j];
                        Sint16 y = randomy[i];
                        Uint32 colort = 0xFF004600;
                        filledCircleColor(sdlrenderer, x, y, 40, color);
                        filledTrigonColor(sdlrenderer, x + 10, y, x - 10, y, x, y + 10, colort);
                    }
                    else if (randomx[j] == castlex[3] && randomy[i] == castley[3]) {
                        Uint32 color = 0xFF00FFFF;//zard
                        Sint16 x = randomx[j];
                        Sint16 y = randomy[i];
                        Uint32 colort = 0xFF007DFF;
                        filledCircleColor(sdlrenderer, x, y, 40, color);
                        filledTrigonColor(sdlrenderer, x + 10, y, x - 10, y, x, y + 10, colort);
                    }
                    else {
                        Uint32 color = 0xFF998877;//toosi
                        Sint16 x = randomx[j];
                        Sint16 y = randomy[i];
                        Uint32 colort = 0xFF000000;
                        filledCircleColor(sdlrenderer, x, y, 40, color);
                        filledTrigonColor(sdlrenderer, x + 10, y, x - 10, y, x, y + 10, colort);
                    }
                }
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
    //SDL_DestroyWindow(sdlWindow);

    printf("\n Hello World\n");
  //  SDL_Quit();
}

else if(choice==2) {
    int ch = 0;
    choosing_the_map(&ch);

    SDL_bool shallExit = SDL_FALSE;

    srand(time(0));
////randomxy baraye noghat random ke bayad dayere dashte bashand ya na.
    int xy[7][9];
    int x[9],y[7];
    int castlex[4], castley[4];
    specific_map(7, 9, xy, x, y, castlex, castley, ch);

    for(int i=0;i<9;++i){
        printf("x:%d\n",x[i]);
    }

    ////havaset bashe while bara namayesh tasavir va event ha va .....
    while (shallExit == SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
        //boxColor(sdlrenderer,500,360,550,410,0xFF000000);
////for baraye rang ghale ha va sarbaz khoone.
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (xy[i][j] != 0) {
                    if (x[j] == castlex[0] && y[i] == castley[0]) {
                        Uint32 color = 0xFF0054FF;//red
                        Sint16 xo = x[j];
                        Sint16 yo = y[i];
                        Uint32 colort = 0xFF0000B8;
                        filledCircleColor(sdlrenderer, xo, yo, 40, color);
                        filledTrigonColor(sdlrenderer, xo + 10, yo, xo - 10, yo, xo, yo + 10, colort);
                    } else if (x[j] == castlex[1] && y[i] == castley[1]) {
                        Uint32 color = 0xFFFF09E1;//blue
                        Sint16 xo = x[j];
                        Sint16 yo = y[i];
                        Uint32 colort = 0xFF079191;
                        filledCircleColor(sdlrenderer, xo, yo, 40, color);
                        filledTrigonColor(sdlrenderer, xo + 10, yo, xo - 10, yo, xo, yo + 10, colort);
                    } else if (x[j] == castlex[2] && y[i] == castley[2]) {
                        Uint32 color = 0xFF00FF00;//sabz
                        Sint16 xo = x[j];
                        Sint16 yo = y[i];
                        Uint32 colort = 0xFF004600;
                        filledCircleColor(sdlrenderer, xo, yo, 40, color);
                        filledTrigonColor(sdlrenderer, xo + 10, yo, xo - 10, yo, xo, yo + 10, colort);
                    } else if (x[j] == castlex[3] && y[i] == castley[3]) {
                        Uint32 color = 0xFF00FFFF;//zard
                        Sint16 xo = x[j];
                        Sint16 yo = y[i];
                        Uint32 colort = 0xFF007DFF;
                        filledCircleColor(sdlrenderer, xo, yo, 40, color);
                        filledTrigonColor(sdlrenderer, xo + 10, yo, xo - 10, yo, xo, yo + 10, colort);
                    } else {
                        Uint32 color = 0xFF998877;//toosi
                        Sint16 xo = x[j];
                        Sint16 yo = y[i];
                        Uint32 colort = 0xFF000000;
                        filledCircleColor(sdlrenderer, xo, yo, 40, color);
                        filledTrigonColor(sdlrenderer, xo + 10, yo, xo - 10, yo, xo, yo + 10, colort);
                    }
                }
            }
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
  //  SDL_DestroyWindow(sdlWindow);

    printf("\n Hello World\n");
   // SDL_Quit();
}

else if(choice==3){


SDL_bool shallExit = SDL_FALSE;

while (shallExit == SDL_FALSE) {
SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
SDL_RenderClear(sdlrenderer);


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