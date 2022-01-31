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



////main
int main() {
////srand baraye random num
srand(time(0));

////baraye namayesh kardn error window.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("moshkel barat pish amade. %s\n", SDL_GetError());
        return 0;
    }
    SDL_Window *sdlWindow = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, tool,
                                             arz, SDL_WINDOW_OPENGL);

////render
    SDL_Renderer *sdlrenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_bool shallExit = SDL_FALSE;

    srand(time(0));
////randomxy baraye noghat random ke bayad dayere dashte bashand ya na.
    int randomxy[7][9];
    for(int i=0;i<7;++i){
        for(int j=0;j<9;++j){
            randomxy[i][j]=rand()%5;
        }
    }

remove_alone_pieces(9,randomxy);
////randomx & randomy baray mokhtasat marakez.
    int randomx[9];
    int randomy[7];
coordinate(randomx,randomy,7,randomxy);
////mokhtasat random ghale ha.
    int castlex[4];
    int castley[4];
    random_castles(castlex,castley,randomx,randomy,randomxy);
    for(int i=0;i<4;++i){
        printf("x :%d   y :%d\n",castlex[i],castley[i]);
    }

   ////havaset bashe while bara namayesh tasavir va event ha va .....
    while (shallExit==SDL_FALSE) {
        SDL_SetRenderDrawColor(sdlrenderer, 0xAF, 0xEE, 0xEE, 0xFF);
        SDL_RenderClear(sdlrenderer);
////for baraye rang ghale ha va sarbaz khoone.
for(int i=0 ; i<7 ;++i) {
    for (int j = 0; j < 9; ++j) {
         if(randomxy[i][j]!=0) {
             if(randomx[j]==castlex[0]&&randomy[i]==castley[0]) {
                 Uint32 color = 0xFF0054FF;//red
                 Sint16 x = randomx[j];
                 Sint16 y = randomy[i];
                 Uint32 colort=0xFF0000B8;
                 filledCircleColor(sdlrenderer, x, y, 40, color);
                 filledTrigonColor(sdlrenderer,x+10,y,x-10,y,x,y+10,colort);
             }
             else if(randomx[j]==castlex[1]&&randomy[i]==castley[1]){
                 Uint32 color = 0xFFFF09E1;//blue
                 Sint16 x = randomx[j];
                 Sint16 y = randomy[i];
                 Uint32 colort=0xFF079191;
                 filledCircleColor(sdlrenderer, x, y, 40, color);
                 filledTrigonColor(sdlrenderer,x+10,y,x-10,y,x,y+10,colort);
             }
             else if(randomx[j]==castlex[2]&&randomy[i]==castley[2]){
                 Uint32 color = 0xFF00FF00;//sabz
                 Sint16 x = randomx[j];
                 Sint16 y = randomy[i];
                 Uint32 colort=0xFF004600;
                 filledCircleColor(sdlrenderer, x, y, 40, color);
                 filledTrigonColor(sdlrenderer,x+10,y,x-10,y,x,y+10,colort);
             }
             else if(randomx[j]==castlex[3]&&randomy[i]==castley[3]){
                 Uint32 color = 0xFF00FFFF;//zard
                 Sint16 x = randomx[j];
                 Sint16 y = randomy[i];
                 Uint32 colort=0xFF007DFF;
                 filledCircleColor(sdlrenderer, x, y, 40, color);
                 filledTrigonColor(sdlrenderer,x+10,y,x-10,y,x,y+10,colort);
             }
             else {
                 Uint32 color = 0xFF998877;//toosi
                 Sint16 x = randomx[j];
                 Sint16 y = randomy[i];
                 Uint32 colort=0xFF000000;
                 filledCircleColor(sdlrenderer, x, y, 40, color);
                 filledTrigonColor(sdlrenderer,x+10,y,x-10,y,x,y+10,colort);
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
    SDL_DestroyWindow(sdlWindow);

    printf("\n Hello World\n");
    SDL_Quit();
    return 0;
}