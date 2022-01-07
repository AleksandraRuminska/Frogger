//
// Created by Aleksandra Ruminska on 10/01/2020.
//
#include<math.h>
#include<stdio.h>
#include<SDL.h>
#include<SDL_main.h>

//extern "C" {
//#include"SDL2-2.0.10/include/SDL.h"
//#include"SDL2-2.0.10/include/SDL_main.h"
//}

#include "draw.h"
#include "colission.h"
#include "scores_file.h"


//checks if little frog was set in the pond
void BonusLittleFrog(struct my_frog * frog, struct my_frog * little_frog, int &points, int &bonus, int &caregiver, int &show_bonus, pos * pond){
    if (frog->frog_pos.y > 45 && frog->frog_pos.y < 85) {
        if (little_frog->frog_pos.y + 5 == frog->frog_pos.y){
            for (int i=0; i<5; i++){
                if (little_frog->frog_pos.x >= pond[i].x-BUILD_BLOCK_SIZE/2 && little_frog->frog_pos.x <= pond[i].x+BUILD_BLOCK_SIZE/2) {
                    bonus += 200;
                    points += 200;
                    show_bonus = 1;
                }
            }
            caregiver = 0;
        }
    }
}

//checks if frog ate a bee
void BonusBee(struct my_frog * frog, int &points, int &bonus, int &caregiver, int &show_bonus, int &bee_eaten, pos &bee_pos){

    if ((frog->frog_pos.x < (bee_pos.x + BUILD_BLOCK_SIZE/2)) && (frog->frog_pos.x > (bee_pos.x - BUILD_BLOCK_SIZE/2))) {
        if (frog->frog_pos.y < 85 && frog->frog_pos.y > 45) {
            bee_eaten = 1;
            bonus += 200;
            points += 200;
            show_bonus = 1;
        }
    }
}

//moves little frog back to second row
void MoveLittleFrog(struct my_frog * little_frog, int &caregiver){
    if (little_frog->frog_pos.y != 420) {
        if (caregiver == 0) {
            little_frog->frog_pos.x = SCREEN_WIDTH/2;
            little_frog->frog_pos.y = 420;
        }
    }
}

//checks if bmp was loaded properly
void CheckIfLoaded(SDL_Surface* surface, SDL_Surface *screen, SDL_Texture *scrtex, SDL_Window *window, SDL_Renderer *renderer){
    if(surface == NULL) {
        printf("SDL_LoadBMP error: %s\n", SDL_GetError());
        SDL_FreeSurface(screen);
        SDL_DestroyTexture(scrtex);
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
}

//changes level to higher one
void UpgradeLevel(int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, int &level, int &number_of_lives, int &bee_eaten, double &worldTime2){
    if ((pond1 == 1) && (pond2 == 1) && (pond3 == 1) && (pond4 == 1) && (pond5 == 1)) {
        level++;
        pond1 = 0;
        pond2 = 0;
        pond3 = 0;
        pond4 = 0;
        pond5 = 0;
        worldTime2 = 0;
        bee_eaten = 0;
        while (number_of_lives < 3) {
            number_of_lives++;
        }
    }
}

//sets main variables to its beginning values
void StartOver(struct my_frog *frog, struct my_frog * little_frog, int &quit_game, int &menu, int &bee_eaten, int &number_of_lives,
               int &points, int &level,int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, double &worldTime, double &worldTime2){
    quit_game = 0;
    menu = 1;
    bee_eaten = 0;
    number_of_lives = 3;
    points = 0;
    frog->frog_pos.x = SCREEN_WIDTH / 2;
    frog->frog_pos.y = SCREEN_HEIGHT - 15;
    little_frog->frog_pos.x = 300;
    little_frog->frog_pos.y = 420;
    level = 1;
    pond1 = 0;
    pond2 = 0;
    pond3 = 0;
    pond4 = 0;
    pond5 = 0;
    worldTime=0;
    worldTime2=0;
}
