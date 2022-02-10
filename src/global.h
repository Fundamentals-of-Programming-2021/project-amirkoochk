//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// struct ha va motagheir haye global dar inja ast .

#ifndef MAIN_C_GLOBAL_H
#define MAIN_C_GLOBAL_H
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
extern int FPS;
extern const int arz;
extern const int tool;
extern const int arz;
extern char player1_name[20];//red
extern int score;
extern SDL_Window *sdlWindow;
extern SDL_Renderer *sdlrenderer ;
extern int choice;
extern int zaman;
extern int time1;
extern int target_time;
extern int index_spell;
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
    int  att;                                                ///    3 ------> power harif -1 mishe
    //// 4----> att yani tavanayi hamle 0 ya 1
};
struct fdata{
    int score;
    char name[20];
    struct fdata *ptr;
};/// in struct baraye zakhire file names&scores ke esm va emtiaz player hara be sorat linkedlist darad.
struct spell{
    int type;
    char string[50];
    Uint32 color;
};///string rahnama , rang va noE har spell .


#endif //MAIN_C_GLOBAL_H
