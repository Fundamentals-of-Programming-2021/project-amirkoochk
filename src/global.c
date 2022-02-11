//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// struct ha va motagheir haye global dar inja ast .

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>

const int FPS = 60;
const int tool=1000;
const int arz =720;
char player1_name[20];//red
int score=0;
SDL_Window *sdlWindow;
SDL_Renderer *sdlrenderer ;
int choice=0;
int zaman=0;
int time1=0;
int target_time;
int index_spell;
Uint32 scolor;

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
}; /// in struct baraye zakhire file names&scores ke esm va emtiaz player hara be sorat linkedlist darad.
struct spell{
    int type;
    char string[50];
    Uint32 color;
}; ///string rahnama , rang va noE har spell .