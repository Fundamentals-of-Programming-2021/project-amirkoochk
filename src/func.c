//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// function haye marboot be render kardan ghale ha, x , y , rang ,atttribute sarbaz ha va ... bazi dar inja ast.

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>




#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
#include"global.h"
#include"func2.h"

void check(int kingx[],int kingy[],int n,int m,int xy[][m]) {
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
}/// mokhtasat ghale haye rangi.
void ghale(int n,int m,int xy[][m],int count,struct map Map[],struct att_sol attSol[]) {
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
                if(kingx[0]==j&& kingy[0]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[1]==j && kingy[1]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[2]==j && kingy[2]==i) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[3]==j && kingy[3]==i) {
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
}/// dadan x ,y , attribute sarbaz ha, va tedad sarbaz ha , rang ghale ha.

void random_map_pieces(int n,int m,int randomxy[][m],int count,struct map Map[],struct att_sol attSol[]) {
    ghale(7,9,randomxy,count,Map,attSol);
}/// :|

void specific_castles(int castlex[],int castley[],int ch) {
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
}/// mokhtasat x , y ghale haye rangi .
void specific_ghale(int n,int m,int xy[][m],int count,struct map Map[],struct att_sol attSol[],int ch) {
    int kingx[4];
    int kingy[4];
    int k=0;
    specific_castles(kingx,kingy,ch);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(xy[i][j]!=0){
                Map[k].x=(j*80)+120;
                Map[k].y=(i*80)+120;
                attSol[k].spell_type=0;
                attSol[k].power=1;
                attSol[k].speed=1;
                attSol[k].att=1;
                if(kingx[0]==(j*80)+120 && kingy[0]==(i*80)+120) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[1]==(j*80)+120 && kingy[1]==(i*80)+120) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[2]==(j*80)+120 && kingy[2]==(i*80)+120) {
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                }
                else if(kingx[3]==(j*80)+120 && kingy[3]==(i*80)+120) {
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
}/// mokhtasat dehi , tedad sarbaz , rang , ... map haye entekhabi .
void specific_map(int n,int m,int xy[][m],int ch,int count,struct map Map[],struct att_sol attSol[]) {
    specific_ghale(7,9,xy,count,Map,attSol,ch);
}/// :|
void test_map_ghale(int x[],int y[]) {
    x[0]=3;
    y[0]=0;
    x[1]=6;
    y[1]=0;
    x[2]=1;
    y[2]=1;
    x[3]=7;
    y[3]=1;
    x[4]=0;
    y[4]=2;
    x[5]=8;
    y[5]=2;
    x[6]=3;
    y[6]=3;
    x[7]=6;
    y[7]=3;
    x[8]=2;
    y[8]=4;
    x[9]=7;
    y[9]=4;
    x[10]=5;
    y[10]=5;
}
void testing_map(int count,struct map Map[],struct  att_sol attSol[],int xy[][9]) {
    int kingx[11];
    int kingy[11];
    int k = 0;
    test_map_ghale(kingx, kingy);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (xy[i][j] != 0) {
                Map[k].x = (j * 80) + 120;
                Map[k].y = (i * 80) + 120;
                attSol[k].spell_type = 0;
                attSol[k].power = 1;
                attSol[k].speed = 1;
                attSol[k].att = 1;
                if(i==kingy[0] && j==kingx[0]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[1] && j==kingx[1]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[2] && j==kingx[2]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[3] && j==kingx[3]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[4] && j==kingx[4]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[5] && j==kingx[5]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[6] && j==kingx[6]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[7] && j==kingx[7]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[8] && j==kingx[8]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[9] && j==kingx[9]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFF0054FF;//// red
                    Map[k].color2= 0xFF0000B8;
                }
                else if(i==kingy[10] && j==kingx[10]){
                    Map[k].is_ghale = 1;
                    Map[k].tedad_sol=10;
                    Map[k].color1= 0xFFFF09E1;/// blue
                    Map[k].color2= 0xFF079191;
                }
                else{
                    Map[k].is_ghale = 0;
                    Map[k].tedad_sol=0;
                    Map[k].color1= 0xFF998877;//// toosi
                    Map[k].color2= 0xFF000000;
                }
                k++;
            }
        }
    }
}
void barkhord(struct map Map[],int *size,int sol[],int x[],int y[],int is,int *sizeb,int solb[],int xb[],int yb[],int isb) {
    int cntrl=0;
    for(int i=0;i<*size;++i){
        for(int j=0;j<*sizeb;++j){
            if(sol[i]==0 && solb[j]==0){
                if(x[i]==xb[j] && y[i]==yb[j]){
                    int k=min(*size-i,*sizeb-j);
                    *size=*size-k;
                    *sizeb=*sizeb-k;
                    Map[is].tedad_sol=Map[is].tedad_sol-k;
                    Map[isb].tedad_sol=Map[isb].tedad_sol-k;
                    cntrl=1;
                    break;
                }
            }
        }
        if(cntrl==1){
            break;
        }
    }
}/// handle kardan barkhord sarbaz ha dar bein rah .

void color_of_map(int c,struct map Map[]) {
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
            Map[i].color1= 0xFF998877;//// toosi
            Map[i].color2= 0xFF000000;
        }
    }
}//// rang manategh map .
void wich_ghale(int xm,int ym,int count,struct map Map[],int *X,int *Y,int *I) {
    for(int i=0;i<count;++i){
        if((Map[i].x-40<xm&&xm<Map[i].x+40)&&(Map[i].y-40<ym&&ym<Map[i].y+40)){
            *X=Map[i].x;
            *Y=Map[i].y;
            *I=i;
            break;
        }
    }
}/// baraye inke click haye gheir daghigh ham ghale mored nazar ra bedahad . x, y , index on return mishavad .
void amount_of_soliders(int i,int j,struct map Map[],struct att_sol attSol[]) {
    if(Map[i].color1==Map[j].color1){
        Map[j].tedad_sol=Map[i].tedad_sol+Map[j].tedad_sol;
        Map[i].tedad_sol=0;
    }
    else if(Map[i].tedad_sol*attSol[i].power>Map[j].tedad_sol*attSol[j].power){
        if(attSol[j].power==-1 ){
            Map[j].tedad_sol = Map[i].tedad_sol  + Map[j].tedad_sol;
            Map[i].tedad_sol = 0;
        }
        else {
            Map[j].tedad_sol = Map[i].tedad_sol * attSol[i].power - Map[j].tedad_sol*attSol[j].power;
            Map[j].color1 = Map[i].color1;
            Map[j].color2 = Map[i].color2;
            Map[j].is_ghale = 1;
            Map[i].tedad_sol = 0;
        }
    }
    else if(Map[i].tedad_sol*attSol[i].power<Map[j].tedad_sol*attSol[j].power){
        if(attSol[i].power!=-1) {
            Map[j].tedad_sol = Map[j].tedad_sol - Map[i].tedad_sol * attSol[i].power;
            Map[i].tedad_sol = 0;
        }
        else{
            Map[j].tedad_sol = Map[i].tedad_sol - Map[j].tedad_sol;
            Map[j].color1=Map[i].color1;
            Map[j].color2=Map[i].color2;
            Map[i].tedad_sol=0;
        }
    }
    else if(Map[i].tedad_sol*attSol[i].power==Map[j].tedad_sol){
        Map[i].tedad_sol=Map[j].tedad_sol=0;
    }
}/// ta'en meghdar sarbaz ha dar asar hamle .index i mohajem .index j modafe .
void changing_attribute1(int c,struct map Map[],struct att_sol attSol[],int index,int s) {
    Uint32 tcolor=Map[index].color1;
    for(int i=0;i<c;++i){
        if(Map[i].color1==tcolor){
            attSol[i].speed=s;
        }
    }
}/// thaghir sorat sarbaz haye ghale haye hamrang be 10 .
void changing_attribute23(int c,struct map Map[],struct att_sol attSol[],int index,int temp) {
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
} /// taghir ghodrat sarbaz ha be 2 ya 0.5 . -1 baraye inke mohajem be tedad sarbaz haye modafe ezafe konad.
void changing_attribute4(int c,struct map Map[],struct att_sol attSol[],int index,int bool) {
    Uint32 tcolor=Map[index].color1;
    for(int i=0;i<c;++i){
        if(tcolor==Map[i].color1){
            attSol[i].att=bool;
        }
    }
}/// az dast raftan ghodrat hamle.
void rest_attri(int c,struct map Map[],struct att_sol attSol[],int index,int ran) {
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
} /// az bein bordan khasiat spell bar asas adad ran ke 1 2 3 4 ast ke adad har spell ast.
void wich_spell(int c,struct map Map[],struct att_sol attSol[],int index,int ran) {
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
}/// dadan ghodrat spell be ghale haye ham rang .
void change_spell_type(int count,struct map Map[],struct att_sol attSol[],int index,int bool) {
    for(int i=0;i<count;++i){
        if(Map[i].color1==Map[index].color1){
            attSol[i].spell_type=bool;
        }
    }
}/// dadan no'e spell be vizhegie sarbaz.
int is_your_ghale(int x,int y,int count,struct map  Map[]) {
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
}/// hargah karbar dar bazi click kard bayad ghale khodash bashad ( red ) index khodash va agar nabod -1 return mishavad .
void moving_mouse_soliders_2(int count,struct map Map[],int xs,int ys,struct att_sol attSol[],int X,int Y,int *kk,int ran,int *mahv,int Is,Uint32 *color,
                             int is,int id,int j,int x1[],int y1[],int sol1[],struct spell majoon[]) {
    int xd,yd;
    SDL_Event sdlEvent;
    int key = 0;
    while (SDL_PollEvent(&sdlEvent) || 1) {
        if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&xd, &yd);
            key = 1;
            break;
        }
    }
    SDL_bool shallexit = SDL_TRUE;
    SDL_bool shallexit1 = SDL_TRUE;
    SDL_bool shallexit2 = SDL_TRUE;
    int Xs, Ys, Xd, Yd;
    int Id;
    int size1=Map[is].tedad_sol-1,size2=Map[Is].tedad_sol-1;
    wich_ghale(xs, ys, count, Map, &Xs, &Ys, &Is);
    wich_ghale(xd, yd, count, Map, &Xd, &Yd, &Id);

    if(Is==is){
        size1=j+1;
        size2=size2-j-1;
    }
    int s = 1;
    int k = 0;
    int tedad=0,timer=0;
    int key3=0,key4=0;
    int key_is=0,key_Is=0;
    int sol[size2];
    int x[size2],y[size2];
    int ted1=0,ted2=0;
    for (int l = 0; l < size2; ++l) {
        if(is==Is){
            sol[l] = l+j+1;
            x[l] = Map[is].x;
            y[l] = Map[is].y;
        }
        sol[l] = l;
        x[l] = Map[Is].x;
        y[l] = Map[Is].y;
    }
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../pixel.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};

    while (key == 1 && shallexit == SDL_TRUE) {
        if (k == 15) {
            for (int j = 0; j < size2; ++j) {
                if (sol[j] != 0)
                    sol[j]--;
            }
            for(int j=0;j<size1;++j){
                if (sol1[j] != 0) {
                    sol1[j]--;
                }
            }
            k = 0;
        }
        /*if (timer == 60) {
            for (int i = 0; i < count; ++i) {
                if (i!=is && i!=id && i!=Is && i!=Id && Map[i].tedad_sol<100 && Map[i].is_ghale==1)
                    Map[i].tedad_sol++;
            }
            timer = 0;
        }*/
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
        for (int i = 0; i < count; ++i) {
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
        }
   /*     if(zaman==0 && *mahv ==1 && time1>=target_time){
            stringColor(sdlrenderer, 400, 40, majoon[0].string, 0xFF000000);
            filledEllipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
            stringColor(sdlrenderer, X - 25, Y, "spell", 0xFF000000);
            ellipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
        }*/
        for (int j = 0; j < size2; ++j) {
            filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
            if (sol[j] == 0) {
                if (tedad == 0 && x[j] == X && y[j] == Y && time1 >= target_time && zaman==0) {
                    key3=1;
                    index_spell=Is;
                    tedad++;
                }
                if (x[j] != Xd) {
                    if (x[j] > Xd) {
                        x[j] -= attSol[Is].speed;
                    } else {
                        x[j] += attSol[Is].speed;
                    }
                }
                if (y[j] != Yd) {
                    if (y[j] > Yd) {
                        y[j] -= attSol[Is].speed;
                    } else {
                        y[j] += attSol[Is].speed;
                    }
                }
            }
        }
        for (int j = 0; j < size1; ++j) {
            filledCircleColor(sdlrenderer, x1[j], y1[j], 5, 0xFF000000);
            if (sol1[j] == 0) {
                if (tedad == 0 && x1[j] ==X  && y1[j] ==Y  && time1 >= target_time && zaman==0) {
                    key4=1;
                    index_spell=is;
                    tedad++;
                }
                if (x1[j] != Map[id].x) {
                    if (x1[j] > Map[id].x) {
                        x1[j] -= attSol[is].speed;
                    } else {
                        x1[j] += attSol[is].speed;
                    }
                }
                if (y1[j] != Map[id].y) {
                    if (y1[j] > Map[id].y) {
                        y1[j] -= attSol[is].speed;
                    } else {
                        y1[j] += attSol[is].speed;
                    }
                }
            }
        }
        if (  ted1==0 && x[size2 - 1] == Xd && y[size2 - 1] == Yd) {
            ted1=1;
            Map[Is].tedad_sol=size2;
            if (time1 >= target_time && key3 == 1) {
                *kk = 1;
                key = 0;
                *mahv = 0;
                *color = Map[is].color2;
                key_Is=1;
                change_spell_type(count, Map, attSol, index_spell, ran);
            }
            amount_of_soliders(Is, Id, Map, attSol);
        }
        if (ted2==0 && x1[size1 - 1] == Map[id].x && y1[size1 - 1] ==Map[id].y ) {
            ted2=1;
            Map[is].tedad_sol=size1;
            if (time1 >= target_time && key4 == 1) {
                *kk = 1;
                key = 0;
                *mahv = 0;
                key_is=1;
                *color = Map[is].color2;
                change_spell_type(count, Map, attSol, index_spell, ran);
            }
            amount_of_soliders(is, id, Map, attSol);
        }
        if (*kk == 1 &&key_Is==1 && index_spell==Is) {
            wich_spell(count, Map, attSol, Is, ran);
        }
        if (*kk == 1 &&key_is==1 && index_spell==is) {
            wich_spell(count, Map, attSol, is, ran);
        }
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(250 / FPS);
        k++;
        timer++;
        if (x[size2 - 1] == Xd && y[size2 - 1] == Yd && x1[size1-1]==Map[id].x && y1[size1-1]==Map[id].y) {
            shallexit = SDL_FALSE;
            break;
        }
    }
}
///1 toolid event mouse baraye maghsad ghale 2 ya ghale ke dobar miferestad . render kardan hamzaman harekat sarbaz ha
///2 tedadi kelid baraye handle kardan mavared tanha yekbar .
///3 taghir tedad sarbaz ha va handle kardan obor az spell ha.
///4 array e az sarbaz ha ke meghdar on be andaze index ast va faghat moghe ke 0 shavad mojaz be harekat ast .
///5 in kar mojeb fasele bein sarbaz ha shode va dar for dar har bar render kardan x y har sarbaz taghir mikond be andaze sorat sarbaz.
void moving_mouse_soliders(int count,struct map Map[],int xm1,int ym1,int xm2,int ym2,struct att_sol attSol[],int X,int Y,int *kk,
                           int ran,int *mahv,int is,Uint32 *color,struct spell majoon[]) {
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
    int xs, ys, xd, yd;
    int id;
    wich_ghale(xm1, ym1, count, Map, &xs, &ys, &is);
    wich_ghale(xm2, ym2, count, Map, &xd, &yd, &id);
    int s = 1;
    int k = 0;
    int tk=0,tedad=0;
    int key3=0,timer=0;
    int sol[Map[is].tedad_sol];
    int x[Map[is].tedad_sol],y[Map[is].tedad_sol];
    int size=Map[is].tedad_sol;
    int Xs,Ys;
    int Is;
    for (int l = 0; l < Map[is].tedad_sol; ++l) {
        sol[l] = l;
        x[l] = Map[is].x;
        y[l] = Map[is].y;
    }
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../pixel.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};
    while (key == 1 && shallexit == SDL_TRUE) {
        if (k == 15) {
            for (int j = 0; j < Map[is].tedad_sol; ++j) {
                if (sol[j] != 0)
                    sol[j]--;
            }
            k = 0;
        }
          /* if (timer == 60) {
               for (int i = 0; i < count; ++i) {
                   if (i!=is && i!=id && Map[i].tedad_sol<100 && Map[i].is_ghale==1)
                       Map[i].tedad_sol++;
               }
               timer = 0;
           }*/
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
        for (int i = 0; i < count; ++i) {
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
        }
      /*  if(zaman==0 && *mahv ==1&& time1>=target_time){
            stringColor(sdlrenderer, 400, 40, majoon[0].string, 0xFF000000);
            filledEllipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
            stringColor(sdlrenderer, X - 25, Y, "spell", 0xFF000000);
            ellipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
        }*/
        int j;
        for (j = 0;j <size;++j) {
            filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
            if (sol[j] == 0) {
                if(x[j]==xs && y[j]==ys ) {
                    while (SDL_PollEvent(&sdlEvent)) {
                        if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
                            SDL_GetMouseState(&Xs, &Ys);
                            Is = is_your_ghale(Xs, Ys, count, Map);
                            if (Is != -1 && attSol[Is].att == 1) {
                                moving_mouse_soliders_2(count, Map, Xs, Ys, attSol, X, Y, kk, ran, mahv, Is, color, is,id, j,x,y,sol,majoon);
                                size = j+1 ;
                                tk=1;
                                break;
                            }
                        }
                    }
                }
                if (tedad == 0 && x[j] == X && y[j] == Y && time1 >= target_time && zaman==0) {
                    key3 = 1;
                    index_spell=is;
                    tedad++;
                }
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
        Map[is].tedad_sol=j+1;
        if(tk==1) {
            break;
        }
        if (x[size - 1] == xd && y[size - 1] == yd) {
            shallexit = SDL_FALSE;
            if (time1 >= target_time && key3 == 1) {
                *kk = 1;
                key = 0;
                *mahv = 0;
                *color = Map[is].color2;
                change_spell_type(count, Map, attSol, index_spell, ran);
            }
            amount_of_soliders(is, id, Map, attSol);
        }

        if (*kk == 1 && index_spell==is) {
            wich_spell(count, Map, attSol, is, ran);
        }

        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(250 / FPS);
        k++;
        timer++;
        if (x[Map[is].tedad_sol - 1] == xd && y[Map[is].tedad_sol - 1] == yd) {
            shallexit = SDL_FALSE;
            break;
        }
    }
}
///1 tedadi kelid baraye handle kardan mavared tanha yekbar .
///2 taghir tedad sarbaz ha va handle kardan obor az spell ha.
///3 array e az sarbaz ha ke meghdar on be andaze index ast va faghat moghe ke 0 shavad mojaz be harekat ast .
///4 in kar mojeb fasele bein sarbaz ha shode va dar for dar har bar render kardan x y har sarbaz taghir mikond be andaze sorat sarbaz.
void majoon_atri(struct spell majoon[],int ran) {
    majoon[0].type=ran;
    if(ran==1){
        strcpy(majoon[0].string,"** spell:: sorat 10x mishe **");
        majoon[0].color=0xFF0000B8;
    }
    else if(ran==2){
        strcpy(majoon[0].string,"** spell:: ghodrat  2x(0.5x) mishe **");
        majoon[0].color=0xFF4B96FF;
    }
    else if(ran==3){
        strcpy(majoon[0].string,"** spell:: ghale tasarof  napazir mishe **");
        majoon[0].color=0xFFC84B2D;
    }
    else if(ran==4){
        strcpy(majoon[0].string,"** spell:: ghodrat hamle azbin mire **");
        majoon[0].color=0xFF004600;
    }
}/// dadan rang be spell va rahnama on ke dar struct spell ast .

void random_spell_xy(int *x,int *y,int n,int m,int xy[][m],int c,struct map Map[]) {
    srand(time(0));
    int ran=rand()%c;
    *x= Map[ran].x;
    *y=Map[ran].y;
}/// toolid konande x , y spell .[ mitavanad ro ghale haye rangi bioftad]
int des_coordinate(int index,int c,struct map Map[],struct att_sol attSol[]) {
    int karan[4]={0,10,20,30};
    srand(time(0));
    int random=rand()%5;///0 1 -->toosi       2 3 4 --> Rangi
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
}/// mokhtasat x y maghsad bot ra midahad . 0 1 40% bara toosi va 2 3 4 60% bara rangi hamle mikonad.
void bot_rendering_2(int count,struct map Map[],int ran,struct att_sol attSol[],int *mahv,int *kk,int is,int id,int Is,
                     Uint32 *colort,int xspell,int yspell,int Xs,int Ys,int index,int sol_bot[],int xb[],int yb[],struct spell majoon[]) {
    SDL_Event sdlEvent;
    int key = 0;
    int Xd, Yd;
    while (SDL_PollEvent(&sdlEvent) || 1) {
        if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&Xd, &Yd);
            key = 1;
            break;
        }
    }
    SDL_bool shallexit = SDL_TRUE;
    SDL_bool shallexit1 = SDL_TRUE;
    SDL_bool shallexit2 = SDL_TRUE;
    int xs, ys, xd, yd; ///karbar
    int Id;
    int j, t;
    wich_ghale(Xs, Ys, count, Map, &xs, &ys, &Is);
    wich_ghale(Xd, Yd, count, Map, &xd, &yd, &Id);
    int xbd=Map[id].x, ybd=Map[id].y;
    int s = 1;
    int k = 0;
    int tedad =0, timer = 0;
    int key3 = 0,key4 = 0;
    int sol[Map[Is].tedad_sol];
    int x[Map[Is].tedad_sol],y[Map[Is].tedad_sol];
    int key_is = 0, key_Is = 0;
    int sizek=Map[Is].tedad_sol,sizeb=Map[is].tedad_sol;
    for (int l = 0; l < Map[Is].tedad_sol; ++l) {
        sol[l] = l;
        x[l] = Map[Is].x;
        y[l] = Map[Is].y;
    }
    int ted = 0, tedb = 0;
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../pixel.bmp");
    SDL_Rect texture_rect ={.x=0, .y=0, .w=tool, .h=arz};

    while (key == 1 && shallexit == SDL_TRUE) {
        if (k == 15) {
            for (int j = 0; j < sizek; ++j) {
                if (sol[j] != 0)
                    sol[j]--;
            }
            for (int j = 0; j < sizeb; ++j) {
                if (sol_bot[j] != 0)
                    sol_bot[j]--;
            }
            k = 0;
        }
       /* if (timer == 60) {
            for (int i = 0; i < count; ++i) {
                if (i!=is && i!=id && i!=Is && i!=Id && Map[i].tedad_sol<100 && Map[i].is_ghale==1)
                    Map[i].tedad_sol++;
            }
            timer = 0;
        }*/
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
        for (int i = 0; i < count; ++i) {
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x, Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
        }
        /*if(zaman==0 && *mahv ==1 && time1>=target_time ){
            stringColor(sdlrenderer, 400, 40, majoon[0].string, 0xFF000000);
            filledEllipseColor(sdlrenderer, xspell, yspell, 30, 20, majoon[0].color);
            stringColor(sdlrenderer, xspell - 25, yspell, "spell", 0xFF000000);
            ellipseColor(sdlrenderer, xspell, yspell, 30, 20, majoon[0].color);
        }*/
        for (j = 0; j < sizek; ++j) {
            filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
            if (sol[j] == 0 && ted == 0) {
                if (tedad == 0 && x[j] == xspell && y[j] == yspell && time1 >= target_time && zaman==0) {
                    key3 = 1;
                    index_spell=Is;
                    tedad++;
                }
                if (x[j] != xd) {
                    if (x[j] > xd) {
                        x[j] -= attSol[Is].speed;
                    } else {
                        x[j] += attSol[Is].speed;
                    }
                }
                if (y[j] != yd) {
                    if (y[j] > yd) {
                        y[j] -= attSol[Is].speed;
                    } else {
                        y[j] += attSol[Is].speed;
                    }
                }
            }
        }
        for( t=0; t<sizeb; ++t){
            filledCircleColor(sdlrenderer, xb[t], yb[t], 5, 0xFF000000);
            if (sol_bot[t] == 0 && tedb == 0) {
                if (tedad == 0 && xb[t] == xspell && yb[t] == yspell && time1 >= target_time && zaman==0) {
                    key4 = 1;
                    index_spell=is;
                    tedad++;
                }
                if (xb[t] != xbd) {
                    if (xb[t] > xbd) {
                        xb[t] -= attSol[is].speed;
                    } else
                        xb[t] += attSol[is].speed;
                }

                if (yb[t] != ybd) {
                    if (yb[t] > ybd) {
                        yb[t] -= attSol[is].speed;
                    } else {
                        yb[t] += attSol[is].speed;
                    }
                }
            }
        }
        barkhord(Map,&sizek,sol,x,y,Is,&sizeb,sol_bot,xb,yb,is);
        if(sizek==0){
            ted=1;
            shallexit1=SDL_FALSE;
        }
        if(sizeb==0){
            tedb=1;
            shallexit2=SDL_FALSE;
        }
        if (ted == 0 && x[sizek - 1] == xd && y[sizek - 1] == yd) {
            shallexit1 = SDL_FALSE;
            ted = 1;
            if (time1 >= target_time && key3 == 1) {
                *kk = 1;
                key = 0;
                *mahv = 0;
                *colort = Map[Is].color2;
                key_Is = 1;
                change_spell_type(count, Map, attSol, index_spell, ran);
            }
            amount_of_soliders(Is, Id, Map, attSol);
        }
        if (ted == 1 && sizek!=0) {
            x[sizek - 1] = xd;
            y[sizek - 1] = yd;
        }
        if (tedb == 0 && xb[sizeb - 1] == xbd && yb[sizeb - 1] == ybd) {
            shallexit2 = SDL_FALSE;
            tedb = 1;
            if (time1 >= target_time && key4 == 1) {
                *kk = 1;
                key = 0;
                *mahv = 0;
                *colort = Map[is].color2;
                key_is = 1;
                change_spell_type(count, Map, attSol, index_spell, ran);
            }
            amount_of_soliders(is, id, Map, attSol);
        }
        if (tedb == 1 && sizeb!=0) {
            xb[sizeb - 1] = xbd;
            yb[sizeb-1] = ybd;
        }
        if (*kk == 1 && key_Is == 1 && index_spell==Is) {
            wich_spell(count, Map, attSol, Is, ran);
            key_Is = 0;
        }
        if (*kk == 1 && key_is == 1 && index_spell==is) {
            wich_spell(count, Map, attSol, is, ran);
            key_is = 0;
        }
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(250 / FPS);
        k++;
        timer++;
        if(shallexit1==SDL_FALSE && shallexit2==SDL_FALSE){
            break;
        }
    }
}
///1 render kardan harekat sarbaz haye bot va karbar (red) .
///2 handle kardan barkhord sarbaz ha .
///3 handle kardan daryaft spell bara karbar ya bot .
///4 handle kardan tedad sarbaz ha baraye bot va karbar .
///5 payan func ba residan hardo bot va karbar be maghsad ya mahv kamel shodan .
void bot_rendering(int X, int Y, int is, int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv,
                   int *kk,Uint32 *colort, int xspell, int yspell,struct spell majoon[]) {
    int id = des_coordinate(is, c, Map, attSol);
    if (id == -1) {
        return;
    }
    SDL_Event sdlEvent;
    int xd = Map[id].x, yd = Map[id].y;
    SDL_bool shallexit = SDL_TRUE;
    int sol[Map[is].tedad_sol];
    int x[Map[is].tedad_sol],y[Map[is].tedad_sol];
    int tedad = 0;
    int key3 = 0;
    int shallexit1=0;
    int att_time = 0, timer=0;
    int j = 0,k=0;
    int Is;
    int Xs, Ys;
    int sizeb=Map[is].tedad_sol;
    for (int l = 0; l < sizeb; ++l) {
        sol[l] = l;
        x[l] = Map[is].x;
        y[l] = Map[is].y;
    }
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../pixel.bmp");
    SDL_Rect texture_rect ={.x=0, .y=0, .w=tool, .h=arz};

    while (shallexit == SDL_TRUE) {
        printf("*\n");
        if (att_time == 15) {
            for (int j = 0; j < sizeb; ++j) {
                if (sol[j] != 0)
                    sol[j]--;
            }
            att_time = 0;
        }
      /*  if (timer == 60) {
            for (int i = 0; i < c; ++i) {
                if (i!=is && i!=id && Map[i].tedad_sol<100 && Map[i].is_ghale==1)
                    Map[i].tedad_sol++;
            }
            timer = 0;
        }*/
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
        for (int i = 0; i < c; ++i) {
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x,
                              Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
        }
             /*  if(zaman==0 && *mahv ==1 && time1>=target_time){
                   stringColor(sdlrenderer, 400, 40, majoon[0].string, 0xFF000000);
                   filledEllipseColor(sdlrenderer, xspell, yspell, 30, 20, majoon[0].color);
                   stringColor(sdlrenderer, xspell - 25, yspell, "spell", 0xFF000000);
                   ellipseColor(sdlrenderer, xspell, yspell, 30, 20, majoon[0].color);
               }*/
        for (j = 0; j < sizeb; ++j) {
            filledCircleColor(sdlrenderer, x[j], y[j], 5, 0xFF000000);
            if (sol[j] == 0) {
                while (SDL_PollEvent(&sdlEvent)) {
                    if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
                        SDL_GetMouseState(&Xs, &Ys);
                        Is = is_your_ghale(Xs, Ys, c, Map);
                        if (Is != -1 && attSol[Is].att == 1) {
                            bot_rendering_2(c, Map, ran, attSol, mahv, kk, is, id, Is, colort, xspell, yspell, Xs,
                                            Ys, j, sol, x, y,majoon);
                            k = 1;
                            break;
                        }
                    }
                }

                if (tedad == 0 && x[j] == xspell && y[j] == yspell && time1 >= target_time && zaman==0) {
                    index_spell=is;
                    key3 = 1;
                    tedad++;
                }
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
        if(k==1){
            break;
        }
        printf("x: %d y:%d\n",x[sizeb-1],y[sizeb-1]);
        if (x[sizeb - 1] == xd && y[sizeb - 1] == yd) {
            printf("omad inja  >>>>\n");
            shallexit1 =1;
            x[sizeb - 1] = xd;
            y[sizeb - 1] = yd;
            amount_of_soliders(is, id, Map, attSol);
            if (time1 >= target_time && key3 == 1) {
                *kk = 1;
                *mahv = 0;
                *colort = Map[is].color2;
                change_spell_type(c, Map, attSol, index_spell, ran);
            }
        }
        if(x[sizeb-1]==0 && y[sizeb-1]==0){
            break;
        }
        if (*kk == 1 && index_spell==is) {
            wich_spell(c, Map, attSol, is, ran);
        }
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(250 / FPS);
        att_time++;
        timer++;
        if (shallexit1==1) {
            printf("***************************************\n");
            shallexit = SDL_FALSE;
            break;
        }
    }
}
///1 handle kardan daryaft spell bara karbar ya bot .
///2 handle kardan tedad sarbaz ha baraye bot va karbar .
///3 payan func ba residan hardo bot va karbar be maghsad ya mahv kamel shodan .
///4 ersal sarbaz tavasot bot.
///5 event mouse baraye ersal sarbaz karbar .
void bot_coordinate(int key, Uint32 color, int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv, int *kk,
                    int *is,Uint32 *colort, int xspell, int yspell,struct spell majoon[]) {
    if (key == 0) {
        return;
    } else {
        int coo[c][3];
        int k = 0;
        for (int i = 0; i < c; ++i) {
            if (Map[i].color1 == color) {
                coo[k][0] = Map[i].x;
                coo[k][1] = Map[i].y;
                coo[k][2] = i;
                k++;
            }
        }
        if (k == 0) {
            return;
        }
        srand(time(0));
        int random = rand() % k;
        *is = coo[random][2];
        if(attSol[coo[random][2]].att==1) {
            bot_rendering(coo[random][0], coo[random][1], coo[random][2], c, Map, attSol, ran, mahv, kk, colort, xspell,
                          yspell, majoon);
        }
    }
}/// daryaft random mokhtasat yek bot hamrang .
void bots_gate(int c, struct map Map[], struct att_sol attSol[], int ran, int *mahv, int *kk, int *is, Uint32 *color,
               int xspell, int yspell,int ted_bot,struct spell majoon[]) {
    srand(time(0));
    if(ted_bot==1){
        bot_coordinate(rand() % 4, 0xFFFF09E1, c, Map, attSol, ran, mahv, kk, is, color, xspell, yspell,majoon); /// blue ,
    }
    else{
        bot_coordinate(rand() % 4, 0xFFFF09E1, c, Map, attSol, ran, mahv, kk, is, color, xspell, yspell,majoon); /// blue ,
        bot_coordinate(rand() % 3, 0xFF00FF00, c, Map, attSol, ran, mahv, kk, is, color, xspell, yspell,majoon); ///green
        bot_coordinate(rand() % 4, 0xFF00FFFF, c, Map, attSol, ran, mahv, kk, is, color, xspell, yspell,majoon); ///yellow
    }
}/// mahal inke aya bot mitavanad hamle konad 1 ya na 0.
void game(int count, struct map Map[], struct att_sol attSol[], int n, int m, int randomxy[][m],int ted_bot) {
    char cmnd;
    int xs, ys, xd, yd;
    int xm1, ym1;
    int xm2, ym2;
    int is, id; /// index ghale mabda va maghsad.
    int isb;/// index shoro ghale bot.
    int result;
    int key2 = 0; /// baraye shoro afzayesh zaman.
    int mahv = 1; /// azbeyn raftan spell.
    int bots_time = 0;
    srand(time(0));
    target_time =rand()%8+9;
    int bt_target = rand() % 10 + 8;
    Uint32 color_ghale_spell;
    Uint32 color_ghale_spell_bot;
    SDL_Event sdlEvent;
    int X, Y;
    random_spell_xy(&X, &Y, 7, 9, randomxy, count, Map);
    int ran =rand() % 4;
    ran++;
    struct spell majoon[1];
    majoon_atri(majoon,ran);
    SDL_bool shallExit = SDL_FALSE;
    SDL_Texture *sdlTexture = menuTexture(sdlrenderer, "../pixel.bmp");
    SDL_Rect texture_rect = {.x=0, .y=0, .w=tool, .h=arz};
    while (shallExit == SDL_FALSE) {
        printf("t:%d & z:%d  &r:%d\n", time1, zaman, ran);
        SDL_SetRenderDrawColor(sdlrenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlrenderer);
        SDL_RenderCopy(sdlrenderer, sdlTexture, NULL, &texture_rect);
///spell handling.
        if (zaman == 30) {
            rest_attri(count, Map, attSol, index_spell, ran);
            key2 = 0;
            zaman = 0;
            time1 = 0;
            target_time =rand()%8+9;
            change_spell_type(count, Map, attSol, index_spell, 0);
            color_ghale_spell = 0xFF000000;
            random_spell_xy(&X, &Y, 7, 9, randomxy, count, Map);
            srand(time(0));
            ran =rand() % 4;
            ran++;
            majoon_atri(majoon,ran);
            mahv = 1;
        }  ///Handling The Time Of Each Spell.

        if (zaman > 0 && zaman < 30) {
            change_spell_type(count, Map, attSol, index_spell, ran);
        }

        for (int i = 0; i < count; ++i) { ///Baraye Render Kardan e Spell Va Map.
            filledCircleColor(sdlrenderer, Map[i].x, Map[i].y, 40, Map[i].color1);
            filledTrigonColor(sdlrenderer, Map[i].x - 10, Map[i].y, Map[i].x + 10, Map[i].y, Map[i].x,
                              Map[i].y + 10,
                              Map[i].color2);
            char c[4];
            sprintf(c, "%d", Map[i].tedad_sol);
            stringColor(sdlrenderer, Map[i].x, Map[i].y - 10, c, 0xFF000000);
            if ( 0<zaman &&  zaman<30 && Map[index_spell].color1 == Map[i].color1) {
                stringColor(sdlrenderer, Map[i].x - 22, Map[i].y, "++", Map[i].color2);
                stringColor(sdlrenderer, Map[i].x + 22, Map[i].y, "++", Map[i].color2);
                stringColor(sdlrenderer, Map[i].x, Map[i].y - 22, "++", Map[i].color2);
                stringColor(sdlrenderer, Map[i].x, Map[i].y + 22, "++", Map[i].color2);
            }
            if (time1 >= target_time && mahv == 1) {
                stringColor(sdlrenderer, 400, 40, majoon[0].string, 0xFF000000);
                filledEllipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
                stringColor(sdlrenderer, X - 25, Y, "spell", 0xFF000000);
                ellipseColor(sdlrenderer, X, Y, 30, 20, majoon[0].color);
            }
        }
        if(bots_time>=bt_target){
            bots_gate(count,Map,attSol,ran,&mahv,&key2,&isb,&color_ghale_spell_bot,X,Y,ted_bot,majoon);
            bots_time=0;
        }
        SDL_RenderPresent(sdlrenderer);
        SDL_Delay(50000 / FPS);
        bots_time++;
///zaman e mandegari har spell
        if (key2 == 1) {
            zaman++;
        }
/// time namayan shodan spell jadid.
        time1++;
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
                    is = is_your_ghale(xm1, ym1, count, Map);
                    if (is != -1 && attSol[is].att == 1) {
                        moving_mouse_soliders(count, Map, xm1, ym1, xm2, ym2, attSol, X, Y, &key2, ran, &mahv, is,
                                              &color_ghale_spell,majoon);
                    }
                    break;
                case SDL_KEYDOWN:
                    cmnd=sdlEvent.key.keysym.sym;
                    break;
            }
            if(cmnd=='m'){
                shallExit=SDL_TRUE;
                break;
            }
        }
/// agar barande moshakhas ast bazi tamom ast.
        result = who_is_winner(count, Map);
        if (result!=0) {
            break;
        }
    }
    show_result(result);
    SDL_Delay(1000);
}
/// func game baraye render kardan map , handle kardan event mouse karbar , handle kardan time spell bara render shodan ,
/// time hamle bot ha , afzayesh tedad sarbaz ha ta 100 , etmam loop while dar sorat barande ya bazande shodan karbar .
