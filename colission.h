//
// Created by Aleksandra Ruminska on 07/01/2020.
//

#ifndef PROJECT_NICER_COLISSION_H
#define PROJECT_NICER_COLISSION_H

#endif //PROJECT_NICER_COLISSION_H


#define SCREEN_WIDTH	600
#define SCREEN_HEIGHT	480

struct position {
    float x;
    float y;
};
typedef position pos;

struct my_frog {
    SDL_Surface *frog;
    pos frog_pos;
};

void CheckColission (struct my_frog * frog, pos *epos, int &lives, int &caregiver, double &worldTime2, int crocodile);
void CheckIfNotTurtle(struct my_frog * frog, pos epos[], int &lives, int &caregiver, double &worldTime2, int no_of_turtles);
void CheckIfNotLog(struct my_frog * frog, pos epos[], int &lives, int &caregiver, double &worldTime2, int no_of_logs);

void TurtleDrown(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &number_of_lives, int level);

void CheckPositionOnCroc(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int paused);
void CheckPositionOnSnake(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int paused);

void ChangePosition(struct my_frog * frog, struct my_frog * little_frog, pos * epos, int &lives, int type, int paused, int level, int caregiver, int crocodile, int snake);
void ChangePositionRacer(pos car_pos[], int pause);
void ChangePosDogY(pos * dog_pos, int level);
void BeeAndCrocLottery(pos * pos);

int CheckIfPond(struct my_frog * frog,  pos epos1, int &lives, double &worldTime2);

void BlockPond(struct my_frog * frog, int &number_of_lives, int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, pos pond[5], double &worldTime2, int &points);

void CheckDogOnLog(pos dog, pos log[], int no_of_logs, int &draw_dog);
void EatenByCrocodile(struct my_frog * frog, pos * epos, int &lives, int &caregiver, double &worldTime2);
void CheckIfNotScreen(struct my_frog * frog, int &number_of_lives, double &worldTime2, int &caregiver);
void JumpingLittleFrog(struct my_frog * little_frog, int pause, int number, int caregiver, SDL_Surface * little_frog_jump_right, SDL_Surface * little_frog_jump_left);