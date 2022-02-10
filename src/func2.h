//
// Created by AMIRHOSSEIN on 2/10/2022.
//

/// function haye marboot be kar ba file, natije ,menu ha va logic haye gheir bazi dar inja ast .


#ifndef MAIN_C_FUNC2_H
#define MAIN_C_FUNC2_H
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#include<string.h>
#include "global.h"
#include"func.h"

int min(int x,int y);
void copy_in_array(struct fdata *head,char name[][20],int scores[],int count);/// baraye sort kardan asami va score ha dar array rikhte shod.
void save_in_file(struct fdata *head);/// zakhire asami va score ha dar file txt.
void sort_scores(struct fdata *head,int scores[],char name[][20],int count);/// ba estefade az bubble sort , list ra az bala ta paien moratab mikonam.
void free_the_list(struct fdata *head);/// free kardan link list.
void show_leaderboard(struct fdata *head,int count); /// showing leaderboard va kelid 'm' baraye bargasht be menu va save kardan asami va scores .
void is_player_rep(struct fdata *head,int count); /// handle kardan esm tekrari va update kardan on dar sorat tekrar.
void add_at_tail(struct fdata *head,char n[],int x); /// afzodan motavaye file be akhar linkedlist.
SDL_Texture *menuTexture(SDL_Renderer *sdlRenderer, char *image_path); /// baraye load kardan png moshabe code kargah.
void first_menu(); /// baraye safhe aval ke moshahede mishavad , event keyboard baraye daryaft esm karbar .
int menu(int *choice); /// menu 2 , daraye tip rooz :) , namayesh esm , va event mouse baraye entekhab bakhsh morede nazar.
int choosing_the_map(int *ch); /// entekhab map moshakhas 3 ta map , event mouse baraye click .
void take_from_file();//// asami va score ha az file kharej shode va dar linkedlist zakhire mishavad .
int who_is_winner(int count,struct map Map[]);/// taeen inke ma (red) barande im ya bazande .
void show_result(int x);/// neshoon mide bordi ya bakhti . ba m vared menu mishi .

#endif //MAIN_C_FUNC2_H
