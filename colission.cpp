//
// Created by Aleksandra Ruminska on 07/01/2020.
//

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<SDL.h>
#include<SDL_main.h>
//
//extern "C" {
//#include"SDL2-2.0.10/include/SDL.h"
//#include"SDL2-2.0.10/include/SDL_main.h"
//}

#include "draw.h"
#include "colission.h"

//checks colision of frog and some other surfaces like cars and lorries
void CheckColission (struct my_frog * frog, pos *epos, int &lives, int &caregiver, double &worldTime2, int crocodile) {

    if (crocodile == 1) {
        if ((frog->frog_pos.x == epos->x) && (frog->frog_pos.y == epos->y + 5)) {
            lives--;
            worldTime2 = 0;
            caregiver = 0;
            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
        }
    }else {
        if ((frog->frog_pos.x == epos->x) && (frog->frog_pos.y == epos->y + 5)) {
            lives--;
            worldTime2 = 0;
            caregiver = 0;
            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
        } else {
            if ((frog->frog_pos.x == epos->x - 30) && (frog->frog_pos.y == epos->y + 5)) {
                lives--;
                worldTime2 = 0;
                caregiver = 0;
                frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
                frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
            } else {
                if ((frog->frog_pos.x == epos->x + 30) && (frog->frog_pos.y == epos->y + 5)) {
                    lives--;
                    worldTime2 = 0;
                    caregiver = 0;
                    frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
                    frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
                }
            }
        }
    }
}

//checks if frog is not on the turtle, so that is in water
void CheckIfNotTurtle(struct my_frog * frog, pos epos[], int &lives, int &caregiver, double &worldTime2, int no_of_turtles){
    if ((frog->frog_pos.y > 120 && frog->frog_pos.y < 160) || (frog->frog_pos.y > 200 && frog->frog_pos.y < 240)) {
        int notturtle = 1;
        for(int i=0; i<no_of_turtles; i++){
            if (!(frog->frog_pos.x> epos[i].x-BUILD_BLOCK_SIZE/2 && frog->frog_pos.x < epos[i].x+BUILD_BLOCK_SIZE/2)){

            }else {
                notturtle = 0;
                break;
            }

        }//for

        if (notturtle==1){
            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
            lives--;
            worldTime2=0;
            caregiver = 0;
        }
    }
}

//checks if frog is not on a log, so that is in water
void CheckIfNotLog(struct my_frog * frog, pos epos[], int &lives, int &caregiver, double &worldTime2, int no_of_logs){
    if ((frog->frog_pos.y > 80 && frog->frog_pos.y < 120) || (frog->frog_pos.y > 160 && frog->frog_pos.y < 200)) {
        int notlog = 1;
        for(int i=0; i<no_of_logs; i++){
            if (!(frog->frog_pos.x> epos[i].x-BUILD_BLOCK_SIZE && frog->frog_pos.x < epos[i].x+BUILD_BLOCK_SIZE)){

            }else {
                notlog = 0;
                break;
            }

        }

        if (notlog==1){
            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
            lives--;
            worldTime2=0;
            caregiver = 0;
        }

    }
}

//checks if frog is on a turtle that is currently under water
void TurtleDrown(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &number_of_lives, int level) {
    if(epos->x <= 2*SCREEN_WIDTH) {
        if (level < 4) {
            epos->x += 0.5;
        } else {
            epos->x += 1.0;
        }
        if (frog->frog_pos.y == epos->y+5 && frog->frog_pos.x == epos->x ) {

            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
            number_of_lives--;
            little_frog->frog_pos.x = SCREEN_WIDTH / 2;
            little_frog->frog_pos.y = 420;

        }
    } else {
        epos->x  = 0;
    }
}

//checks if frog is on the crocodile head
void CheckPositionOnCroc(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int paused){
    if (paused % 2 == 0) {
        if (frog->frog_pos.y == epos->y + 5 && (frog->frog_pos.x > epos->x && frog->frog_pos.x <= epos->x + 40)) {
            frog->frog_pos.x = SCREEN_WIDTH / 2;
            frog->frog_pos.y = SCREEN_HEIGHT - 15;
            lives--;
            little_frog->frog_pos.x = SCREEN_WIDTH / 2;
            little_frog->frog_pos.y = 420;
        }
    }
}

//checks if frog is on the snake's head
void CheckPositionOnSnake(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int paused){
    if (paused % 2 == 0) {
        if (frog->frog_pos.y == epos->y + 5 && (frog->frog_pos.x >= epos->x-40 && frog->frog_pos.x <= epos->x)) {
            frog->frog_pos.x = SCREEN_WIDTH / 2;
            frog->frog_pos.y = SCREEN_HEIGHT - 15;
            lives--;
            little_frog->frog_pos.x = SCREEN_WIDTH / 2;
            little_frog->frog_pos.y = 420;
        }
    }
}

//moves objects through screen
void ChangePosition(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int type, int paused, int level, int caregiver, int crocodile, int snake){

    int pos_lengthx1;
    int pos_lengthx2;
    if (type==3 || type == 2) {
        if (crocodile==0 && snake==0) {
            pos_lengthx1 = 40;
            pos_lengthx2 = 40;
        } else {
            if (crocodile==1) {
                pos_lengthx1 = 40;
                pos_lengthx2 = 10;
            } else {
                if (snake==1){
                    pos_lengthx1 = 20;
                    pos_lengthx2 = 40;
                }
            }
        }
    } else {
        pos_lengthx1 = 20;
        pos_lengthx2 = 20;
    }

    if (paused % 2 == 0) {
        if (type == 0) {
            if (epos->x <= 2 * SCREEN_WIDTH) {
                if (level < 4) {
                    epos->x += 1;
                } else{
                    epos->x += 1.25;
                }
            } else {
                epos->x = 0;
            }
        } else if (type == 4) {
            if (epos->x <= 2 * SCREEN_WIDTH) {
                if (level < 4) {
                    epos->x += 0.5;
                } else{
                    epos->x += 1.0;
                }
            } else {
                epos->x = 0;
            }
        } else {
            if (epos->x <= 2 * SCREEN_WIDTH) {
                if (type == 1) {
                    if (level < 4) {
                        epos->x += 0.5;
                    } else {
                        epos->x += 1.0;
                    }
                } else  if (type == 3){
                    if (level < 4) {
                        epos->x += 0.5;
                    } else {
                        epos->x += 1.0;
                    }
                } else {
                    if (level < 4) {
                        epos->x += 1;
                    } else {
                        epos->x += 1.25;
                    }
                }
                if (frog->frog_pos.y == epos->y + 5 && (frog->frog_pos.x >= epos->x - pos_lengthx1 && frog->frog_pos.x<= epos->x + pos_lengthx2)) {

                    if (type == 1) {
                        if (level < 4) {
                            frog->frog_pos.x += 0.5;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 0.5;
                            }
                        } else {
                            frog->frog_pos.x += 1.0;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 1.0;
                            }
                        }
                    } else if (type == 3){
                        if (level < 4) {
                            frog->frog_pos.x += 0.5;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 0.5;
                            }
                        } else {
                            frog->frog_pos.x += 1.0;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 1.0;
                            }
                        }
                    } else {
                        if (level < 4) {
                            frog->frog_pos.x += 1;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 1;
                            }
                        } else {
                            frog->frog_pos.x += 1.25;
                            if (caregiver==1) {
                                little_frog->frog_pos.x += 1.25;
                            }
                        }
                    }
                }
            } else {
                epos->x = 0;
            }
        }
    }
}

//moves cars that are currently racers (above 1 level)
void ChangePositionRacer(pos car_pos[], int pause){
    if (pause == 0) {
        if (car_pos[2].x <= 2 * SCREEN_WIDTH) {
            car_pos[2].x += 2.0;
        } else {
            car_pos[2].x = 0;
        }
        if (car_pos[1].x <= 2 * SCREEN_WIDTH) {
            car_pos[1].x += 2.0;
        } else {
            car_pos[1].x = 0;
        }
        if (car_pos[0].x <= 2 * SCREEN_WIDTH) {
            car_pos[0].x += 2.0;
        } else {
            car_pos[0].x = 0;
        }
    }
}

//moves dog (above level 2)
void ChangePosDogY(pos * dog_pos, int level){
    if (level < 4) {
        dog_pos->y -= 0.5;
    } else {
        dog_pos->y -= 1;
    }
}

//choosing the position of bee and crocodile heads (from level 2)
void BeeAndCrocLottery(pos * pos){
    int tab[5]= {40, 160, 280, 400, 520};

    srand(time(0));

    pos->x =  tab[(rand() % 5)] + 20;

    pos->y = 60;
}

//check if frog is in one of five ponds
int CheckIfPond(struct my_frog * frog,  pos epos1, int &lives, double &worldTime2){
    int pond=0;

    if (frog->frog_pos.y < 85 && frog->frog_pos.y > 45){

        if(frog->frog_pos.x< epos1.x+20 && frog->frog_pos.x > epos1.x-20) {

            frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
            frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
            pond=1;
            return pond;
        }
    }
    return pond;
}

//blocks pond to which the frog jumped into
void BlockPond(struct my_frog * frog, int &number_of_lives, int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, pos pond[5], double &worldTime2, int &points){
    if (frog->frog_pos.y>45 && frog->frog_pos.y<85){

        if(CheckIfPond(frog, pond[0], number_of_lives, worldTime2)==0) {
            if (CheckIfPond(frog, pond[1], number_of_lives, worldTime2) == 0) {
                if (CheckIfPond(frog, pond[2], number_of_lives, worldTime2) == 0) {
                    if (CheckIfPond(frog, pond[3], number_of_lives, worldTime2) == 0) {
                        if (CheckIfPond(frog, pond[4], number_of_lives, worldTime2) == 0) {
                            number_of_lives--;

                        } else {
                            if (pond5==1){
                                number_of_lives--;
                            } else {
                                pond5 = 1;
                                points += (10 * (50 - (int) worldTime2) + 50);
                            }
                        }
                    } else{
                        if (pond4==1){
                            number_of_lives--;
                        } else {
                            pond4 = 1;
                            points += (10 * (50 - (int) worldTime2) + 50);
                        }
                    }
                } else{
                    if (pond3==1){
                        number_of_lives--;
                    } else {
                        pond3 = 1;
                        points += (10 * (50 - (int) worldTime2) + 50);
                    }
                }
            } else {
                if (pond2==1){
                    number_of_lives--;
                } else {
                    pond2 = 1;
                    points += (10 * (50 - (int) worldTime2) + 50);
                }
            }
        } else {
            if (pond1==1){
                number_of_lives--;
            } else {
                pond1 = 1;
                points += (10 * (50 - (int) worldTime2) + 50);
            }
        }

        frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
        frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
        worldTime2=0;
    }
}

//check if position of dog is equal to position of log
void CheckDogOnLog(pos dog, pos log[], int no_of_logs, int &draw_dog){
    for (int i=0; i<no_of_logs; i++) {
        if (dog.y == log[i].y) {
            if (dog.x >= log[i].x - 40 && dog.x <= log[i].x + 40) {
                draw_dog = 0;
            }
        }
    }
}

//checks if frog jumped to the pond where currently is crocodile's head
void EatenByCrocodile(struct my_frog * frog, pos * epos, int &lives, int &caregiver, double &worldTime2){
    if (frog->frog_pos.y == epos->y+5){
        if (frog->frog_pos.x >= epos->x-20 && frog->frog_pos.x <= epos->x+20){
            frog->frog_pos.x = SCREEN_WIDTH/2;
            frog->frog_pos.y = SCREEN_HEIGHT-15;
            lives--;
            caregiver = 0;
            worldTime2 = 0;
        }
    }
}

//checks if frog's position is lower or bigger than screen size
void CheckIfNotScreen(struct my_frog * frog, int &number_of_lives, double &worldTime2, int &caregiver){
    if (frog->frog_pos.x < 0 || frog->frog_pos.x > SCREEN_WIDTH) {
        number_of_lives--;
        worldTime2 = 0;
        caregiver = 0;
        frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
        frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;

    } else if (frog->frog_pos.y < 0 || frog->frog_pos.y > SCREEN_HEIGHT) {
        number_of_lives--;
        worldTime2 = 0;
        caregiver = 0;
        frog->frog_pos.x = (float) SCREEN_WIDTH / 2;
        frog->frog_pos.y = (float) SCREEN_HEIGHT - 15;
    }
}

//choose where little frog jumps when it is in the second row
void JumpingLittleFrog(struct my_frog * little_frog, int pause, int number, int caregiver, SDL_Surface * little_frog_jump_right, SDL_Surface * little_frog_jump_left){
    if (pause == 0) {
        if (caregiver == 0) {
            if (little_frog->frog_pos.x >= 40 && little_frog->frog_pos.x<= 560) {
                if (number % 75 == 0 && number % 125 != 0 && number % 50 != 0) {
                    little_frog->frog = little_frog_jump_right;
                    little_frog->frog_pos.x += BUILD_BLOCK_SIZE;
                } else {
                    if (number % 125 == 0 && number % 50 == 0) {
                        little_frog->frog = little_frog_jump_left;
                        little_frog->frog_pos.x -= BUILD_BLOCK_SIZE;
                    }
                }
            } else {
                little_frog->frog_pos.x = SCREEN_WIDTH / 2;
            }

        }
    }
}
