#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#ifdef main
#undef main
#endif

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
#include "global.h"
#include "func.h"
#include "func2.h"

    int main() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
            printf("moshkel barat pish amade. %s\n", SDL_GetError());
            return 0;
        }
        sdlWindow = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, tool, arz,
                                     SDL_WINDOW_OPENGL);
        sdlrenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
        int tedad=0;
    while (1) {
        if(tedad==0){
         first_menu();
        }
        menu(&choice);

            if (choice == 1) {
                srand(time(0));
                int count = 0;
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
                random_map_pieces(7, 9, randomxy, count, Map, attSol);
                color_of_map(count, Map);
                game(count, Map, attSol, 7, 9, randomxy,3);
            }
            else if (choice == 2) {
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
                }
                else if (ch == 2) {
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
                }
                else if (ch == 3) {
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
                struct att_sol attSol[count];
                specific_map(7, 9, xy, ch, count, Map, attSol);
                color_of_map(count, Map);
                game(count, Map, attSol, 7, 9, xy,3);
            }
            else if (choice == 3) {
                int count=0;
                int xy[7][9];
                for(int i=0;i<7;++i){
                    for(int j=0;j<9;++j){
                        if(i % 3 + j % 4 != 0 && i % 3 + j % 4 != 1){
                            xy[i][j]=1;
                            count++;
                        }else{
                            xy[i][j]=0;
                        }
                    }
                }
               struct map Map[count];
                struct att_sol attSol[count];
                testing_map(count,Map,attSol,xy);
                game(count,Map,attSol,7,9,xy,1);
            }
            else if (choice == 4) {
                take_from_file();
            }
            else if(choice==5){
                break;
            }
            tedad++;
        }
        SDL_DestroyRenderer(sdlrenderer);
        SDL_DestroyWindow(sdlWindow);
    return 0;
    }