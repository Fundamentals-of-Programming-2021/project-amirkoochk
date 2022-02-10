//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// function haye marboot be render kardan ghale ha, x , y , rang ,atttribute sarbaz ha va ... bazi dar inja ast.


#ifndef MAIN_C_FUNC_H
#define MAIN_C_FUNC_H
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>




#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
#include"global.h"
#include"func2.h"

void check(int kingx[],int kingy[],int n,int m,int xy[][m]); /// mokhtasat ghale haye rangi.
void ghale(int n,int m,int xy[][m],int count,struct map Map[],struct att_sol attSol[]); /// dadan x ,y , attribute sarbaz ha, va tedad sarbaz ha , rang ghale ha.
void random_map_pieces(int n,int m,int randomxy[][m],int count,struct map Map[],struct att_sol attSol[]);
void specific_castles(int castlex[],int castley[],int ch);/// mokhtasat x , y ghale haye rangi .
void specific_ghale(int n,int m,int xy[][m],int count,struct map Map[],struct att_sol attSol[],int ch);/// mokhtasat dehi , tedad sarbaz , rang , ... map haye entekhabi .
void specific_map(int n,int m,int xy[][m],int ch,int count,struct map Map[],struct att_sol attSol[]);
void test_map_ghale(int x[],int y[]); /// ghale haye map test.
void testing_map(int count,struct map Map[],struct  att_sol attSol[],int xy[][9]);
void barkhord(struct map Map[],int *size,int sol[],int x[],int y[],int is,int *sizeb,int solb[],int xb[],int yb[],int isb);/// handle kardan barkhord sarbaz ha dar bein rah .
void color_of_map(int c,struct map Map[]); //// rang manategh map .
void wich_ghale(int xm,int ym,int count,struct map Map[],int *X,int *Y,int *I);/// baraye inke click haye gheir daghigh ham ghale mored nazar ra bedahad . x, y , index on return mishavad .
void amount_of_soliders(int i,int j,struct map Map[],struct att_sol attSol[]);/// ta'en meghdar sarbaz ha dar asar hamle .index i mohajem .index j modafe .
void changing_attribute1(int c,struct map Map[],struct att_sol attSol[],int index,int s);/// thaghir sorat sarbaz haye ghale haye hamrang be 10 .
void changing_attribute23(int c,struct map Map[],struct att_sol attSol[],int index,int temp); /// taghir ghodrat sarbaz ha be 2 ya 0.5 . -1 baraye inke mohajem be tedad sarbaz haye modafe ezafe konad.
void changing_attribute4(int c,struct map Map[],struct att_sol attSol[],int index,int bool);/// az dast raftan ghodrat hamle.
void rest_attri(int c,struct map Map[],struct att_sol attSol[],int index,int ran); /// az bein bordan khasiat spell bar asas adad ran ke 1 2 3 4 ast ke adad har spell ast.
void wich_spell(int c,struct map Map[],struct att_sol attSol[],int index,int ran);/// dadan ghodrat spell be ghale haye ham rang .
void change_spell_type(int count,struct map Map[],struct att_sol attSol[],int index,int bool);/// dadan no'e spell be vizhegie sarbaz.
int is_your_ghale(int x,int y,int count,struct map  Map[]);/// hargah karbar dar bazi click kard bayad ghale khodash bashad ( red ) index khodash va agar nabod -1 return mishavad .
void moving_mouse_soliders_2(int count,struct map Map[],int xs,int ys,struct att_sol attSol[],int X,int Y,int *kk,int ran,int *mahv,int Is,Uint32 *color,
                             int is,int id,int j,int x1[],int y1[],int sol1[],struct spell majoon[]);
///1 toolid event mouse baraye maghsad ghale 2 ya ghale ke dobar miferestad . render kardan hamzaman harekat sarbaz ha
///2 tedadi kelid baraye handle kardan mavared tanha yekbar .
///3 taghir tedad sarbaz ha va handle kardan obor az spell ha.
///4 array e az sarbaz ha ke meghdar on be andaze index ast va faghat moghe ke 0 shavad mojaz be harekat ast .
///5 in kar mojeb fasele bein sarbaz ha shode va dar for dar har bar render kardan x y har sarbaz taghir mikond be andaze sorat sarbaz.
void moving_mouse_soliders(int count,struct map Map[],int xm1,int ym1,int xm2,int ym2,struct att_sol attSol[],int X,int Y,int *kk,
                           int ran,int *mahv,int is,Uint32 *color,struct spell majoon[]);
///1 tedadi kelid baraye handle kardan mavared tanha yekbar .
///2 taghir tedad sarbaz ha va handle kardan obor az spell ha.
///3 array e az sarbaz ha ke meghdar on be andaze index ast va faghat moghe ke 0 shavad mojaz be harekat ast .
///4 in kar mojeb fasele bein sarbaz ha shode va dar for dar har bar render kardan x y har sarbaz taghir mikond be andaze sorat sarbaz.
void majoon_atri(struct spell majoon[],int ran);/// dadan rang be spell va rahnama on ke dar struct spell ast .
void random_spell_xy(int *x,int *y,int n,int m,int xy[][m],int c,struct map Map[]);/// toolid konande x , y spell .[ mitavanad ro ghale haye rangi bioftad]
int des_coordinate(int index,int c,struct map Map[],struct att_sol attSol[]);/// mokhtasat x y maghsad bot ra midahad . 0 1 40% bara toosi va 2 3 4 60% bara rangi hamle mikonad.
void bot_rendering_2(int count,struct map Map[],int ran,struct att_sol attSol[],int *mahv,int *kk,int is,int id,int Is,
                     Uint32 *colort,int xspell,int yspell,int Xs,int Ys,int index,int sol_bot[],int xb[],int yb[],struct spell majoon[]);
///1 render kardan harekat sarbaz haye bot va karbar (red) .
///2 handle kardan barkhord sarbaz ha .
///3 handle kardan daryaft spell bara karbar ya bot .
///4 handle kardan tedad sarbaz ha baraye bot va karbar .
///5 payan func ba residan hardo bot va karbar be maghsad ya mahv kamel shodan .
void bot_rendering(int X, int Y, int is, int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv,
                   int *kk,Uint32 *colort, int xspell, int yspell,struct spell majoon[]);
///1 handle kardan daryaft spell bara karbar ya bot .
///2 handle kardan tedad sarbaz ha baraye bot va karbar .
///3 payan func ba residan hardo bot va karbar be maghsad ya mahv kamel shodan .
///4 ersal sarbaz tavasot bot.
///5 event mouse baraye ersal sarbaz karbar .
void bot_coordinate(int key, Uint32 color, int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv, int *kk,
                    int *is,Uint32 *colort, int xspell, int yspell,struct spell majoon[]);/// daryaft random mokhtasat yek bot hamrang .
void bots_gate(int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv, int *kk, int *is, Uint32 *color,
               int xspell, int yspell,int ted_bot,struct spell majoon[]);/// mahal inke aya bot mitavanad hamle konad 1 ya na 0.
void game(int count, struct map Map[], struct att_sol attSol[], int n, int m, int randomxy[][m],int ted_bot);
/// func game baraye render kardan map , handle kardan event mouse karbar , handle kardan time spell bara render shodan ,
/// time hamle bot ha , afzayesh tedad sarbaz ha ta 100 , etmam loop while dar sorat barande ya bazande shodan karbar .


#endif //MAIN_C_FUNC_H
