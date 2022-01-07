//
// Created by Aleksandra Ruminska on 10/01/2020.
//

#ifndef PROJECT_NICER_STAGES_H
#define PROJECT_NICER_STAGES_H

#endif //PROJECT_NICER_STAGES_H

void BonusLittleFrog(struct my_frog * frog, struct my_frog * little_frog, int &points, int &bonus, int &caregiver, int &show_bonus, pos * pond);
void BonusBee(struct my_frog * frog, int &points, int &bonus, int &caregiver, int &show_bonus, int &bee_eaten, pos &bee_pos);
void MoveLittleFrog(struct my_frog * little_frog, int &caregiver);
void CheckIfLoaded(SDL_Surface* surface, SDL_Surface *screen, SDL_Texture *scrtex, SDL_Window *window, SDL_Renderer *renderer);
void UpgradeLevel(int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, int &level, int &number_of_lives, int &bee_eaten, double &worldTime2);
void StartOver(struct my_frog *frog, struct my_frog * little_frog, int &quit_game, int &menu, int &bee_eaten, int &number_of_lives,
               int &points, int &level,int &pond1, int &pond2, int &pond3, int &pond4, int &pond5, double &worldTime, double &worldTime2);