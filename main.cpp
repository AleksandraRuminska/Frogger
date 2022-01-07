#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<SDL.h>
#include<SDL_main.h>

//extern "C" {
//#include "SDL2-2.0.10/include/SDL.h"
//#include "SDL2-2.0.10/include/SDL_main.h"
//}


#include "draw.h"
#include "colission.h"
#include "scores_file.h"
#include "stages.h"
#include "stages.h"


// main
//#ifdef __cplusplus
//extern "C"
//#endif

int main(int argc, char **argv) {

    int t1, t2, quit, frames, rc;
    double delta, worldTime, worldTime2, fpsTimer, fps;
    SDL_Event event;
    SDL_Surface *screen, *charset;
    struct my_frog frog;
    struct my_frog little_frog;
    SDL_Surface *background;
    SDL_Texture *scrtex;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *frog_sit;
    SDL_Surface *frog_jump;
    SDL_Surface *frog_sit_right;
    SDL_Surface *frog_jump_right;
    SDL_Surface *frog_sit_left;
    SDL_Surface *frog_jump_left;
    SDL_Surface *frog_sit_down;
    SDL_Surface *frog_jump_down;
    SDL_Surface *froggy;
    SDL_Surface *little_frog_sit;
    SDL_Surface *little_frog_jump;
    SDL_Surface *little_frog_sit_right;
    SDL_Surface *little_frog_jump_right;
    SDL_Surface *little_frog_sit_left;
    SDL_Surface *little_frog_jump_left;
    SDL_Surface *little_frog_sit_down;
    SDL_Surface *little_frog_jump_down;
    SDL_Surface *bee;
    SDL_Surface *car;
    SDL_Surface *car2;
    SDL_Surface *car2_normal;
    SDL_Surface *car2_tyres;
    SDL_Surface *lorry;
    SDL_Surface *turtle;
    SDL_Surface *turtle2;
    SDL_Surface *turtle_up;
    SDL_Surface *turtle_down;
    SDL_Surface *log;
    SDL_Surface *heart;
    SDL_Surface *racer;
    SDL_Surface *end;
    SDL_Surface *crocodile;
    SDL_Surface *crocodile_open;
    SDL_Surface *crocodile_closed;
    SDL_Surface *head_croc;
    SDL_Surface *snake;
    SDL_Surface *dog;
    float time;
    int number_of_lives = 3;
    int pause = 0;
    int points = 0;
    int bee_eaten = 0;
    int caregiver = 0;
    int quit_game = 0;
    int pond1 = 0;
    int pond2 = 0;
    int pond3 = 0;
    int pond4 = 0;
    int pond5 = 0;
    int level = 1;
    int number = 0;
    int menu = 1;
    int height = 190;
    int bonus=0;
    int show_bonus=0;
    int draw_dog=1;
    char name[20];
    char filename[]="high_scores.txt";
    scores high_scores[10];
    scores * record_scores = NULL;
    scores *records = NULL;
    int active_results_list=0;

    time = SDL_GetTicks();

    pos lorry_pos[9];
    pos turtle_pos[24];
    pos log_pos[16];
    pos heart_pos[3];
    pos car_pos[6];
    pos bee_pos;
    pos dog_pos;
    pos headcroc_pos;
    pos end_pos;

    dog_pos.x = 220;
    dog_pos.y = 220;

    end_pos.x = SCREEN_WIDTH/2;
    end_pos.y = 140;

    int no_of_turtles = 24;
    int no_of_hearts = 3;
    int no_of_lorries = 9;
    int no_of_cars = 6;
    int no_of_logs = 16;


    lorry_pos[0].x=10;
    lorry_pos[0].y=20;

    pos pond[5];


    for (int i=0; i<5; i++){
        pond[i].y=BUILD_BLOCK_SIZE+BUILD_BLOCK_SIZE/2;
        pond[i].x = BUILD_BLOCK_SIZE+BUILD_BLOCK_SIZE/2 + 3*BUILD_BLOCK_SIZE*i;
    }


    for( int ii=0 ; ii< no_of_turtles; ii++){
        if (ii < no_of_turtles/2){
          turtle_pos[ii].y = 140;
        } else {
          turtle_pos[ii].y = 220;
        }
    }


    turtle_pos[0].x = -500;
    turtle_pos[1].x = -540;
    turtle_pos[2].x = 110;
    turtle_pos[3].x = 460;
    turtle_pos[4].x = 500;
    turtle_pos[5].x = 540;
    turtle_pos[6].x = 820;
    turtle_pos[7].x = 860;
    turtle_pos[8].x = 900;
    turtle_pos[9].x = 990;
    turtle_pos[10].x = 1030;
    turtle_pos[11].x = 1070;

    turtle_pos[12].x = 110;
    turtle_pos[13].x = 150;
    turtle_pos[14].x = 190;
    turtle_pos[15].x = 930;
    turtle_pos[16].x = 970;
    turtle_pos[17].x = 1010;
    turtle_pos[18].x = 670;
    turtle_pos[19].x = 710;
    turtle_pos[20].x = 750;
    turtle_pos[21].x = 320;
    turtle_pos[22].x = 360;
    turtle_pos[23].x = 400;


    for(int ii=0, j=550; ii< no_of_hearts; ii++, j -= BUILD_BLOCK_SIZE){
        heart_pos[ii].y = 15;
        heart_pos[ii].x = j;

    }


   for( int ii=0 ; ii< no_of_lorries; ii++){
        if (ii < 6){
          lorry_pos[ii].y = 300;
        } else {
          lorry_pos[ii].y = 340;
        }
    }
     lorry_pos[0].x = -20;
     lorry_pos[1].x = 480;
     lorry_pos[2].x = 150;
     lorry_pos[3].x = 730;
     lorry_pos[4].x = 1100;
     lorry_pos[5].x = -600;
     lorry_pos[6].x = 270;
     lorry_pos[7].x = -200;
     lorry_pos[8].x = 880;


    for( int ii=0 ; ii< no_of_cars; ii++){
        if (ii < no_of_cars/2){
          car_pos[ii].y = 380;
        } else {
          car_pos[ii].y = 420;
        }
    }

     car_pos[0].x = 400;
     car_pos[1].x = 280;
     car_pos[2].x = 730;
     car_pos[3].x = -200;
     car_pos[4].x = 0;
     car_pos[4].x = 180;


    for( int ii=0 ; ii< no_of_logs; ii++){
        if (ii < no_of_logs/2){
          log_pos[ii].y = 100;
        } else {
          log_pos[ii].y = 180;
        }
    }

     log_pos[0].x = 0;
     log_pos[1].x = 150;
     log_pos[2].x = 240;
     log_pos[3].x = 450;
     log_pos[4].x = 650;
     log_pos[5].x = 740;
     log_pos[6].x = 950;
     log_pos[7].x = 1100;

     log_pos[8].x = 100;
     log_pos[9].x = 270;
     log_pos[10].x = 390;
     log_pos[11].x = 520;
     log_pos[12].x = 670;
     log_pos[13].x = 760;
     log_pos[14].x = 900;
     log_pos[15].x = 1050;


//little frog
    little_frog.frog_pos.x = SCREEN_WIDTH/2;
    little_frog.frog_pos.y = 420;

    for (int i=0; i<20; i++){
        name[i]='\0';
    }

    if (IfFileExists(filename)==1){

    } else{
        for (int i=0; i<10; i++){
            high_scores[i].points=0;
            strcpy(high_scores[i].nickname, "-");
        }
        WriteToFile(high_scores, filename);
    }


    BeeAndCrocLottery(&bee_pos);
    BeeAndCrocLottery(&headcroc_pos);

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return 1;
    }
    // fullscreen mode
//	rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
//	                                 &window, &renderer);

    rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE,
                                     &window, &renderer);
    if(rc != 0) {
        SDL_Quit();
        printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
        return 1;
    };

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_SetWindowTitle(window, "Frogger");

    screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
                                  0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

    scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_ShowCursor(SDL_DISABLE);

    background = SDL_LoadBMP("resources/tlo2.bmp");
    CheckIfLoaded(background, screen, scrtex, window, renderer);

       SDL_SetColorKey(background, true, 0x000000);

    charset = SDL_LoadBMP("resources/cs8x8.bmp");
    CheckIfLoaded(charset, screen, scrtex, window, renderer);

    SDL_SetColorKey(charset, true, 0x000000);
    car = SDL_LoadBMP("resources/car.bmp");
    CheckIfLoaded(car, screen, scrtex, window, renderer);

    car2_normal = SDL_LoadBMP("resources/car1.bmp");
    CheckIfLoaded(car2_normal, screen, scrtex, window, renderer);

    car2_tyres = SDL_LoadBMP("resources/car1_tyres.bmp");
    CheckIfLoaded(car2_tyres, screen, scrtex, window, renderer);
    car2 = car2_normal;

    lorry = SDL_LoadBMP("resources/lorry.bmp");
    CheckIfLoaded(lorry, screen, scrtex, window, renderer);

    log = SDL_LoadBMP("resources/log1.bmp");
    CheckIfLoaded(log, screen, scrtex, window, renderer);

    turtle_up = SDL_LoadBMP("resources/turtle.bmp");
    CheckIfLoaded(turtle_up, screen, scrtex, window, renderer);

    turtle_down = SDL_LoadBMP("resources/turtle_down.bmp");
    CheckIfLoaded(turtle_down, screen, scrtex, window, renderer);

    turtle = turtle_up;
    turtle2 = turtle_up;

    heart = SDL_LoadBMP("resources/heart.bmp");
    CheckIfLoaded(heart, screen, scrtex, window, renderer);

    racer = SDL_LoadBMP("resources/racer.bmp");
    CheckIfLoaded(racer, screen, scrtex, window, renderer);

    end = SDL_LoadBMP("resources/gameover.bmp");
    CheckIfLoaded(end, screen, scrtex, window, renderer);

    bee = SDL_LoadBMP("resources/bee.bmp");
    CheckIfLoaded(bee, screen, scrtex, window, renderer);

    snake = SDL_LoadBMP("resources/snake.bmp");
    CheckIfLoaded(snake, screen, scrtex, window, renderer);

    head_croc = SDL_LoadBMP("resources/crocodile3.bmp");
    CheckIfLoaded(head_croc, screen, scrtex, window, renderer);

    dog = SDL_LoadBMP("resources/dog.bmp");
    CheckIfLoaded(dog, screen, scrtex, window, renderer);

    crocodile_closed = SDL_LoadBMP("resources/crocodile1.bmp");
    CheckIfLoaded(crocodile_closed, screen, scrtex, window, renderer);

    crocodile_open = SDL_LoadBMP("resources/crocodile2.bmp");
    CheckIfLoaded(crocodile_open, screen, scrtex, window, renderer);
    crocodile = crocodile_closed;

    frog.frog_pos.x = SCREEN_WIDTH/2;
    frog.frog_pos.y = SCREEN_HEIGHT-15;

    frog_sit = SDL_LoadBMP("resources/frog_sit_good.bmp");
    CheckIfLoaded(frog_sit, screen, scrtex, window, renderer);
    frog_jump = SDL_LoadBMP("resources/frog_jump.bmp");
    CheckIfLoaded(frog_jump, screen, scrtex, window, renderer);
    frog_sit_right = SDL_LoadBMP("resources/frog_sit_right.bmp");
    CheckIfLoaded(frog_sit_right, screen, scrtex, window, renderer);
    frog_jump_right = SDL_LoadBMP("resources/frog_jump_right.bmp");
    CheckIfLoaded(frog_jump_right, screen, scrtex, window, renderer);
    frog_sit_left = SDL_LoadBMP("resources/frog_sit_left.bmp");
    CheckIfLoaded(frog_sit_left, screen, scrtex, window, renderer);
    frog_jump_left = SDL_LoadBMP("resources/frog_jump_left.bmp");
    CheckIfLoaded(frog_jump_left, screen, scrtex, window, renderer);
    frog_sit_down = SDL_LoadBMP("resources/frog_sit_down.bmp");
    CheckIfLoaded(frog_sit_down, screen, scrtex, window, renderer);
    frog_jump_down = SDL_LoadBMP("resources/frog_jump_down.bmp");
    CheckIfLoaded(frog_jump_down, screen, scrtex, window, renderer);


    little_frog_sit = SDL_LoadBMP("resources/little_frog.bmp");
    CheckIfLoaded(little_frog_sit, screen, scrtex, window, renderer);
    little_frog_jump = SDL_LoadBMP("resources/little_frog_jump.bmp");
    CheckIfLoaded(little_frog_jump, screen, scrtex, window, renderer);
    little_frog_sit_right = SDL_LoadBMP("resources/little_frog-right.bmp");
    CheckIfLoaded(little_frog_sit_right, screen, scrtex, window, renderer);
    little_frog_jump_right = SDL_LoadBMP("resources/little_frog_jump_right.bmp");
    CheckIfLoaded(little_frog_jump_right, screen, scrtex, window, renderer);
    little_frog_sit_left = SDL_LoadBMP("resources/little_frog-left.bmp");
    CheckIfLoaded(little_frog_sit_left, screen, scrtex, window, renderer);
    little_frog_jump_left = SDL_LoadBMP("resources/little_frog_left.bmp");
    CheckIfLoaded(little_frog_jump_left, screen, scrtex, window, renderer);
    little_frog_sit_down = SDL_LoadBMP("resources/little_frog-down.bmp");
    CheckIfLoaded(little_frog_sit_down, screen, scrtex, window, renderer);
    little_frog_jump_down = SDL_LoadBMP("resources/little_frog_jump_down.bmp");
    CheckIfLoaded(little_frog_jump_down, screen, scrtex, window, renderer);
    froggy = SDL_LoadBMP("resources/froggy.bmp");
    CheckIfLoaded(froggy, screen, scrtex, window, renderer);

    little_frog.frog = little_frog_sit;

    frog.frog = frog_sit;

    char text[128];
    int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
    int zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
    int czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
    int niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
    t1 = SDL_GetTicks();

    frames = 0;
    fpsTimer = 0;
    fps = 0;
    quit = 0;
    worldTime = 0;
    worldTime2 = 0;

    int j=0;

    while(!quit) {
        t2 = SDL_GetTicks();

        // SDL_Delay(100); //because of different speed on diferent computers

        // here t2-t1 is the time in milliseconds since
        // the last screen was drawn
        // delta is the same time in seconds

        if (pause % 2 == 0) {
            delta = (t2 - t1) * 0.001;
            t1 = t2;
            worldTime += delta;
            worldTime2 += delta;
        }

        if (menu == 0) {
//main game
            if( active_results_list==1){
                if(records != NULL) {
                    free(records);
                    records=NULL;
                    active_results_list=0;
                }
            }

            SDL_FillRect(screen, NULL, czarny);

            pos bkground;
            bkground.x = SCREEN_WIDTH / 2;
            bkground.y = SCREEN_HEIGHT / 2;
            DrawSurface(screen, background, bkground.x, bkground.y);

            if (pause == 0) {
                if ((int) time % 5 == 0) {
                    turtle2 = turtle_down;
                } else {
                    turtle2 = turtle_up;
                }
            }

            JumpingLittleFrog(&little_frog, pause, number, caregiver, little_frog_jump_right, little_frog_jump_left);

            for(int aa=0; aa<no_of_lorries; aa++){
                DrawSurface(screen, lorry, lorry_pos[aa].x, lorry_pos[aa].y);
            }

            if (level < 2) {
                DrawSurface(screen, car, car_pos[0].x, car_pos[0].y);
                DrawSurface(screen, car2, car_pos[1].x, car_pos[1].y);
                DrawSurface(screen, car, car_pos[2].x, car_pos[2].y);
            } else {
                DrawSurface(screen, racer, car_pos[0].x, car_pos[0].y);
                DrawSurface(screen, racer, car_pos[1].x, car_pos[1].y);
                DrawSurface(screen, racer, car_pos[2].x, car_pos[2].y);
            }

            DrawSurface(screen, car, car_pos[3].x, car_pos[3].y);
            DrawSurface(screen, car2, car_pos[4].x, car_pos[4].y);
            DrawSurface(screen, car2, car_pos[5].x, car_pos[5].y);

            DrawSurface(screen, log, log_pos[0].x, log_pos[0].y);
            DrawSurface(screen, log, log_pos[1].x, log_pos[1].y);

            if (level == 1) {
                DrawSurface(screen, log, log_pos[2].x, log_pos[2].y);
                DrawSurface(screen, log, log_pos[5].x, log_pos[5].y);
                DrawSurface(screen, log, log_pos[10].x, log_pos[10].y);
                DrawSurface(screen, log, log_pos[14].x, log_pos[14].y);
            } else {
                DrawSurface(screen, crocodile, log_pos[2].x, log_pos[2].y);
                DrawSurface(screen, crocodile, log_pos[5].x, log_pos[5].y);
                DrawSurface(screen, crocodile, log_pos[10].x, log_pos[10].y);
                DrawSurface(screen, crocodile, log_pos[14].x, log_pos[14].y);
            }

            if (level < 4) {
                DrawSurface(screen, log, log_pos[3].x, log_pos[3].y);
                DrawSurface(screen, log, log_pos[4].x, log_pos[4].y);
                DrawSurface(screen, log, log_pos[6].x, log_pos[6].y);
                DrawSurface(screen, log, log_pos[7].x, log_pos[7].y);
            } else {
                DrawSurface(screen, crocodile, log_pos[3].x, log_pos[3].y);
                DrawSurface(screen, crocodile, log_pos[4].x, log_pos[4].y);
                DrawSurface(screen, crocodile, log_pos[6].x, log_pos[6].y);
                DrawSurface(screen, crocodile, log_pos[7].x, log_pos[7].y);
            }

            for(int aa=8; aa<no_of_logs; aa++){
                if (aa!=10 && aa!=14) {
                    DrawSurface(screen, log, log_pos[aa].x, log_pos[aa].y);
                }
            }

            DrawSurface(screen, turtle2, turtle_pos[0].x, turtle_pos[0].y);
            DrawSurface(screen, turtle2, turtle_pos[2].x, turtle_pos[2].y);
            DrawSurface(screen, turtle2, turtle_pos[3].x, turtle_pos[3].y);
            DrawSurface(screen, turtle2, turtle_pos[7].x, turtle_pos[7].y);
            DrawSurface(screen, turtle2, turtle_pos[11].x, turtle_pos[11].y);
            DrawSurface(screen, turtle2, turtle_pos[13].x, turtle_pos[13].y);
            DrawSurface(screen, turtle2, turtle_pos[14].x, turtle_pos[14].y);
            DrawSurface(screen, turtle2, turtle_pos[17].x, turtle_pos[17].y);

            DrawSurface(screen, turtle, turtle_pos[1].x, turtle_pos[1].y);

            DrawSurface(screen, turtle, turtle_pos[4].x, turtle_pos[4].y);

            for (int i=8; i<11; i+=2){
                DrawSurface(screen, turtle, turtle_pos[i].x, turtle_pos[i].y);
            }

            DrawSurface(screen, turtle, turtle_pos[12].x, turtle_pos[12].y);
            DrawSurface(screen, turtle, turtle_pos[15].x, turtle_pos[15].y);
            DrawSurface(screen, turtle, turtle_pos[16].x, turtle_pos[16].y);

            for (int i=18; i<24; i++){
                DrawSurface(screen, turtle, turtle_pos[i].x, turtle_pos[i].y);
            }

            if (level < 4) {
                DrawSurface(screen, turtle, turtle_pos[5].x, turtle_pos[5].y);
                DrawSurface(screen, turtle, turtle_pos[6].x, turtle_pos[6].y);
                DrawSurface(screen, turtle, turtle_pos[9].x, turtle_pos[9].y);
                DrawSurface(screen, turtle, turtle_pos[19].x, turtle_pos[19].y);
                DrawSurface(screen, turtle, turtle_pos[20].x, turtle_pos[20].y);
            } else {
                DrawSurface(screen, turtle2, turtle_pos[5].x, turtle_pos[5].y);
                DrawSurface(screen, turtle2, turtle_pos[6].x, turtle_pos[6].y);
                DrawSurface(screen, turtle2, turtle_pos[9].x, turtle_pos[9].y);
                DrawSurface(screen, turtle2, turtle_pos[19].x, turtle_pos[19].y);
                DrawSurface(screen, turtle2, turtle_pos[20].x, turtle_pos[20].y);
            }

            if (level > 2) {
                DrawSurface(screen, snake, log_pos[1].x, log_pos[1].y);
                DrawSurface(screen, snake, log_pos[8].x, log_pos[8].y);
                DrawSurface(screen, snake, log_pos[12].x, log_pos[12].y);
                if (draw_dog==1) {
                    DrawSurface(screen, dog, dog_pos.x, dog_pos.y);
                } else {
                    if (frog.frog_pos.x == dog_pos.x && frog.frog_pos.y == dog_pos.y + 5) {
                        number_of_lives--;
                        frog.frog_pos.x = SCREEN_WIDTH / 2;
                        frog.frog_pos.y = SCREEN_HEIGHT - 15;
                    }
                }
            }

            if (level > 4) {
                DrawSurface(screen, snake, log_pos[0].x, log_pos[0].y);
                DrawSurface(screen, snake, log_pos[11].x, log_pos[11].y);
            }

            if (number_of_lives > 0) {
                DrawSurface(screen, little_frog.frog, little_frog.frog_pos.x, little_frog.frog_pos.y);
                DrawSurface(screen, frog.frog, frog.frog_pos.x, frog.frog_pos.y);

            } else {
                DrawSurface(screen, end, end_pos.x, end_pos.y);
                DrawRectangle(screen, 160, 320, 280, 40, niebieski, czerwony);
                sprintf(text, "QUIT GAME? Y/N");
                DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 340, text, charset);
            }

            if (number_of_lives == 0) {
                sprintf(text, "Enter your name:");
                DrawRectangle(screen, 200, 200, 200, 80, czerwony, niebieski);
                DrawString(screen, 220, 220, text, charset);

                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
                        case SDL_KEYDOWN:
                            if (j != 19 && (((int) event.key.keysym.sym >= 65 && (int) event.key.keysym.sym <= 122) ||
                                            ((int) event.key.keysym.sym >= 48 && (int) event.key.keysym.sym <= 57))) {
                                name[j] = event.key.keysym.sym;
                                ToUpercase(j, name);
                                j++;
                                sprintf(text, "%s", name);
                            } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                name[--j] = '\0';
                            } if (event.key.keysym.sym == SDLK_RETURN) {

                                record_scores = ReadFromFile(filename);
                                qsort(record_scores, 10, sizeof(scores), Comparator);
                                WriteToFile(record_scores, filename);

                                    free(record_scores);
                                    record_scores = NULL;


                                record_scores = CheckIfBigger(name, points, filename);
                                WriteToFile(record_scores, filename);
                                free(record_scores);

                                StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                                menu = 1;
                            }
                            if (event.key.keysym.sym == SDLK_y) {
                                quit = 1;
                            }
                            if (event.key.keysym.sym == SDLK_n) {
                                StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                                menu = 1;
                            }
                            break;
                        case SDL_KEYUP:
                            break;
                        case SDL_QUIT:
                            quit = 1;
                            break;
                        default:
                            break;
                    }
                }
                DrawRectangle(screen, 210, 240, 180, 20, czerwony, czerwony);
                DrawString(screen, 230, 250, name, charset);
            }

            if (pause % 2 == 0) {
                fpsTimer += delta;
                if (fpsTimer > 0.5) {
                    fps = frames * 4;
                    frames = 0;
                    fpsTimer -= 0.5;
                }
                time = worldTime2;
            }

            if ((50 - time) > 10) {
                DrawRectangle(screen, 500, 450, 50 - time, BUILD_BLOCK_SIZE/2, czarny, zielony);
            } else {
                if (time >= 50.0) {
                    frog.frog_pos.x= SCREEN_WIDTH / 2;
                    frog.frog_pos.y = SCREEN_HEIGHT - 15;
                    number_of_lives--;
                    caregiver = 0;
                    worldTime2 = 0;

                } else {
                    DrawRectangle(screen, 500, 450, 50 - time, BUILD_BLOCK_SIZE/2, czarny, czerwony);
                }
            }
            DrawRectangle(screen, 0, 0, SCREEN_WIDTH, BUILD_BLOCK_SIZE, czerwony, niebieski);
            sprintf(text, "Time = %.1lf s  %.0lf frames / sec", worldTime, fps);
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
            sprintf(text, "Esc - exit, \030 - go up, \031 - go down, \032 - go left, \033 - go right");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 28, text, charset);

            if (pause % 2 == 1) {
                DrawRectangle(screen, 160, 220, 280, BUILD_BLOCK_SIZE, niebieski, czerwony);
                sprintf(text, "PAUSED");
                DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 240, text, charset);
            }

            if (quit_game == 1) {
                DrawRectangle(screen, 160, 220, 280, BUILD_BLOCK_SIZE, niebieski, czerwony);
                sprintf(text, "QUIT GAME? Y/N");
                DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 240, text, charset);
            }

            DrawRectangle(screen, BUILD_BLOCK_SIZE/2, 450, 120, BUILD_BLOCK_SIZE/2, niebieski, czerwony);
            sprintf(text, "POINTS:  %d", points);
            DrawString(screen, 30, 455, text, charset);

            if (frog.frog_pos.y == SCREEN_HEIGHT - 15 && frog.frog_pos.x == SCREEN_WIDTH / 2) {
                if (number_of_lives > 0) {
                    if (bonus != 0) {
                        if ((caregiver == 0 || bee_eaten == 1) && show_bonus == 1) {
                            DrawRectangle(screen, screen->w / 2 - strlen(text) * 8 / 2, 220, 100, 40, czarny, czarny);
                            sprintf(text, "%d", bonus);
                            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 240, text, charset);
                        }
                    }
                }
            } else {
                show_bonus = 0;
            }

            if (frog.frog_pos.y == SCREEN_HEIGHT - (BUILD_BLOCK_SIZE + 15)) {
                bonus = 0;
            }

            if (number_of_lives == 3) {
                DrawSurface(screen, heart, heart_pos[2].x, heart_pos[2].y);
            }
            if (number_of_lives > 1) {
                DrawSurface(screen, heart, heart_pos[1].x, heart_pos[1].y);
            }
            if (number_of_lives > 0) {
                DrawSurface(screen, heart, heart_pos[0].x, heart_pos[0].y);
            }

            if (bee_eaten == 0) {
                DrawSurface(screen, bee, bee_pos.x, bee_pos.y);
            }

            if (level > 1) {
                DrawSurface(screen, head_croc, headcroc_pos.x, headcroc_pos.y);
            }

            if (pond1 == 1) {
                DrawSurface(screen, froggy, pond[0].x, pond[0].y);
            }
            if (pond2 == 1) {
                DrawSurface(screen, froggy, pond[1].x, pond[1].y);
            }
            if (pond3 == 1) {
                DrawSurface(screen, froggy, pond[2].x, pond[2].y);
            }
            if (pond4 == 1) {
                DrawSurface(screen, froggy, pond[3].x, pond[3].y);
            }
            if (pond5 == 1) {
                DrawSurface(screen, froggy, pond[4].x, pond[4].y);
            }

            UpgradeLevel(pond1, pond2, pond3, pond4, pond5, level, number_of_lives, bee_eaten, worldTime2);

            if (frog.frog_pos.x == little_frog.frog_pos.x && frog.frog_pos.y == little_frog.frog_pos.y + 5) {
                caregiver = 1;
            }

            SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, scrtex, NULL, NULL);
            SDL_RenderPresent(renderer);

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
                        else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
                            points += 10;
                            if (pause % 2 == 0) {
                                frog.frog = frog_jump;
                                frog.frog_pos.y -= BUILD_BLOCK_SIZE;
                                if (caregiver == 1) {
                                    little_frog.frog = little_frog_jump;
                                    little_frog.frog_pos.y -= BUILD_BLOCK_SIZE;
                                }
                            }
                        } else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
                            if (pause % 2 == 0) {
                                frog.frog = frog_jump_down;
                                frog.frog_pos.y += BUILD_BLOCK_SIZE;
                                if (caregiver == 1) {
                                    little_frog.frog = little_frog_jump_down;
                                    little_frog.frog_pos.y += BUILD_BLOCK_SIZE;
                                }
                            }
                        } else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
                            if (pause % 2 == 0) {
                                frog.frog = frog_jump_right;
                                frog.frog_pos.x += BUILD_BLOCK_SIZE;
                                if (caregiver == 1) {
                                    little_frog.frog = little_frog_jump_right;
                                    little_frog.frog_pos.x += BUILD_BLOCK_SIZE;
                                }
                            }

                        } else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
                            if (pause % 2 == 0) {
                                frog.frog = frog_jump_left;
                                frog.frog_pos.x -= BUILD_BLOCK_SIZE;
                                if (caregiver == 1) {
                                    little_frog.frog = little_frog_jump_left;
                                    little_frog.frog_pos.x -= BUILD_BLOCK_SIZE;
                                }
                            }
                        } else if (event.key.keysym.sym == SDLK_p) {
                            if (pause == 1){
                                pause = 0;
                            } else {
                                pause = 1;
                            }
                        } else if (event.key.keysym.sym == SDLK_q) {
                            quit_game = 1;
                        } else if (event.key.keysym.sym == SDLK_y) {
                            if (number_of_lives == 0) {
                                quit = 1;
                            }
                            if (quit_game == 1) {
                                StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                            }
                        } else if (event.key.keysym.sym == SDLK_n) {
                            if (number_of_lives == 0) {
                                StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                            }
                            if (quit_game == 1) {
                                quit_game = 0;
                            }
                        }
                        break;
                    case SDL_KEYUP:
                        if (frog.frog == frog_jump) {
                            frog.frog = frog_sit;
                            little_frog.frog = little_frog_sit;
                        }
                        if (frog.frog == frog_jump_right) {
                            frog.frog = frog_sit_right;
                            little_frog.frog = little_frog_sit_right;
                        }
                        if (frog.frog == frog_jump_left) {
                            frog.frog = frog_sit_left;
                            little_frog.frog = little_frog_sit_left;
                        }
                        if (frog.frog == frog_jump_down) {
                            frog.frog = frog_sit_down;
                            little_frog.frog = little_frog_sit_down;
                        }
                        break;
                    case SDL_QUIT:
                        quit = 1;
                        break;
                }
            }
            frames++;

        if (level>2) {
            CheckDogOnLog(dog_pos, log_pos, no_of_logs, draw_dog);
        }

        if (level>1) {
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[2], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[5], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[10], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[14], number_of_lives, pause);
        }

        if (level > 3) {
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[3], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[4], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[6], number_of_lives, pause);
            CheckPositionOnCroc(&frog, &little_frog, &log_pos[7], number_of_lives, pause);
        }

        if (level>2) {
            CheckPositionOnSnake(&frog, &little_frog, &log_pos[1], number_of_lives, pause);
            CheckPositionOnSnake(&frog, &little_frog, &log_pos[8], number_of_lives, pause);
            CheckPositionOnSnake(&frog, &little_frog, &log_pos[12], number_of_lives, pause);
        }

        if (level > 4) {
            CheckPositionOnSnake(&frog, &little_frog, &log_pos[0], number_of_lives, pause);
            CheckPositionOnSnake(&frog, &little_frog, &log_pos[11], number_of_lives, pause);
        }

        for (int i=0; i<no_of_lorries; i++){
            ChangePosition(&frog, &little_frog, &lorry_pos[i], number_of_lives, 0, pause, level, caregiver,
                    0, 0);
        }

        if (level < 2) {
            for (int i=0; i<3; i++){
                ChangePosition(&frog, &little_frog, &car_pos[i], number_of_lives, 4, pause, level, caregiver,
                               0, 0);
            }

        } else {

            ChangePositionRacer(car_pos, pause);
        }

        for (int i=3; i<6; i++){
            ChangePosition(&frog, &little_frog, &car_pos[i], number_of_lives, 4, pause, level, caregiver,
                           0, 0);
        }

        if (level > 1) {
            ChangePosition(&frog, &little_frog, &log_pos[2], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[5], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[10], number_of_lives, 3, pause, level,
                           caregiver, 1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[14], number_of_lives, 3, pause, level,
                           caregiver, 1, 0);
        } else {
            ChangePosition(&frog, &little_frog, &log_pos[2], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[5], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[10], number_of_lives, 3, pause, level,
                           caregiver, 0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[14], number_of_lives, 3, pause, level,
                           caregiver, 0, 0);
        }

        if (level > 2) {
            ChangePosition(&frog, &little_frog, &log_pos[1], number_of_lives, 2, pause, level, caregiver,
                           0, 1);
            ChangePosition(&frog, &little_frog, &log_pos[8], number_of_lives, 3, pause, level, caregiver,
                           0, 1);
            ChangePosition(&frog, &little_frog, &log_pos[12], number_of_lives, 3, pause, level,
                           caregiver, 0, 1);

        } else {
            ChangePosition(&frog, &little_frog, &log_pos[1], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[8], number_of_lives, 3, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[12], number_of_lives, 3, pause, level,
                           caregiver, 0, 0);
        }

        if (level > 3) {
            ChangePosition(&frog, &little_frog, &log_pos[0], number_of_lives, 2, pause, level, caregiver,
                           0, 1);
            ChangePosition(&frog, &little_frog, &log_pos[11], number_of_lives, 3, pause, level,
                           caregiver, 0, 1);
            ChangePosition(&frog, &little_frog, &log_pos[3], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[4], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[6], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
            ChangePosition(&frog, &little_frog, &log_pos[7], number_of_lives, 2, pause, level, caregiver,
                           1, 0);
        } else {
            ChangePosition(&frog, &little_frog, &log_pos[0], number_of_lives, 2, pause, level, caregiver,
                                 0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[11], number_of_lives, 3, pause, level,
                           caregiver, 0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[3], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[4], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[6], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
            ChangePosition(&frog, &little_frog, &log_pos[7], number_of_lives, 2, pause, level, caregiver,
                           0, 0);
        }

        ChangePosition(&frog, &little_frog, &log_pos[9], number_of_lives, 3, pause, level, caregiver,
                       0, 0);
        ChangePosition(&frog, &little_frog, &log_pos[13], number_of_lives, 3, pause, level, caregiver,
                       0, 0);
        ChangePosition(&frog, &little_frog, &log_pos[15], number_of_lives, 3, pause, level, caregiver,
                       0, 0);
        number++;


            if (pause % 2 == 0 && (int) time % 5 == 0 && number % 10 == 0) {
                if (crocodile == crocodile_closed) {
                    crocodile = crocodile_open;
                } else {
                    crocodile = crocodile_closed;
                }
            }

            if (pause % 2 == 0) {
                if (car2 == car2_normal) {
                    car2 = car2_tyres;
                } else {
                    car2 = car2_normal;
                }
            }

            if (turtle2 == turtle_up) {
                ChangePosition(&frog, &little_frog, &turtle_pos[0], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
                ChangePosition(&frog, &little_frog, &turtle_pos[2], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
                ChangePosition(&frog, &little_frog, &turtle_pos[3], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);

                ChangePosition(&frog, &little_frog, &turtle_pos[7], number_of_lives, 1, pause, level,
                                   caregiver, 0, 0);

                for (int i=11; i<14; i+=2 ){
                    ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                                   caregiver, 0, 0);
                }

                ChangePosition(&frog, &little_frog, &turtle_pos[14], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
                ChangePosition(&frog, &little_frog, &turtle_pos[17], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);

                if (level >= 4){
                    for (int i=5; i<7; i++ ){
                        ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                                       caregiver, 0, 0);
                    }

                    ChangePosition(&frog, &little_frog, &turtle_pos[9], number_of_lives, 1, pause, level,
                                   caregiver, 0, 0);

                    for (int i=19; i<21; i++ ){
                        ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                                       caregiver, 0, 0);
                    }
                }
            }

            ChangePosition(&frog, &little_frog, &turtle_pos[1], number_of_lives, 1, pause, level,
                           caregiver, 0, 0);
            ChangePosition(&frog, &little_frog, &turtle_pos[4], number_of_lives, 1, pause, level,
                           caregiver, 0, 0);

            for (int i=8; i<13; i+=2 ){
                ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
            }

            for (int i=15; i<17; i++ ){
                ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
            }

            ChangePosition(&frog, &little_frog, &turtle_pos[18], number_of_lives, 1, pause, level,
                           caregiver, 0, 0);

            for (int i=21; i<24; i++ ){
                ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);
            }

            if (level < 4){
                for (int i=5; i<7; i++ ){
                    ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                                   caregiver, 0, 0);
                }
                ChangePosition(&frog, &little_frog, &turtle_pos[9], number_of_lives, 1, pause, level,
                               caregiver, 0, 0);

                for (int i=19; i<21; i++ ){
                    ChangePosition(&frog, &little_frog, &turtle_pos[i], number_of_lives, 1, pause, level,
                                   caregiver, 0, 0);
                }
            }


            if (turtle2 == turtle_down) {
                if (pause == 0) {
                    TurtleDrown(&frog, &little_frog, &turtle_pos[0], number_of_lives, level);
                    for (int i = 2; i < 4; i++) {
                        TurtleDrown(&frog, &little_frog, &turtle_pos[i], number_of_lives, level);
                    }
                        TurtleDrown(&frog, &little_frog, &turtle_pos[7], number_of_lives, level);

                    for (int i = 11; i < 14; i += 2) {
                        TurtleDrown(&frog, &little_frog, &turtle_pos[i], number_of_lives, level);
                    }
                    TurtleDrown(&frog, &little_frog, &turtle_pos[14], number_of_lives, level);
                    TurtleDrown(&frog, &little_frog, &turtle_pos[17], number_of_lives, level);

                    if (level >= 4 ){
                        for (int i = 5; i < 7; i++) {
                            TurtleDrown(&frog, &little_frog, &turtle_pos[i], number_of_lives, level);
                        }
                        TurtleDrown(&frog, &little_frog, &turtle_pos[9], number_of_lives, level);

                        for (int i = 19; i < 21; i++) {
                            TurtleDrown(&frog, &little_frog, &turtle_pos[i], number_of_lives, level);
                        }
                    }
                }
            }

            if (pause == 0) {
                if (dog_pos.y >= 100) {
                    if (level > 2) {
                        ChangePosition(&frog, &little_frog, &dog_pos, number_of_lives, 1, pause, level,
                                       caregiver, 0, 0);
                    }
                    ChangePosDogY(&dog_pos, level);
                } else {
                    dog_pos.x = 220;
                    dog_pos.y = 220;
                }
            }

            CheckIfNotScreen(&frog, number_of_lives, worldTime2, caregiver);

            BonusLittleFrog(&frog, &little_frog, points, bonus, caregiver, show_bonus, pond);

            MoveLittleFrog(&little_frog, caregiver);

            if (level > 1) {
                if (pause == 0) {
                    if (number % 300 == 0) {
                        BeeAndCrocLottery(&headcroc_pos);
                    }
                }
            }
//kolizje
//cars
            CheckColission(&frog, &car_pos[0], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &car_pos[1], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &car_pos[2], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &car_pos[3], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &car_pos[4], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &car_pos[5], number_of_lives, caregiver, worldTime2, 0);
//logs
            CheckIfNotLog(&frog, log_pos, number_of_lives, caregiver, worldTime2, no_of_logs);
//lorries
            CheckColission(&frog, &lorry_pos[0], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[1], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[2], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[3], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[4], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[5], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[6], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[7], number_of_lives, caregiver, worldTime2, 0);
            CheckColission(&frog, &lorry_pos[8], number_of_lives, caregiver, worldTime2, 0);

// turtles

            CheckIfNotTurtle(& frog, turtle_pos, number_of_lives, caregiver, worldTime2, no_of_turtles);
//crocodiles in the pond

            if (level > 1) {
                EatenByCrocodile(&frog, &headcroc_pos, number_of_lives, caregiver, worldTime2);
            }

            BonusBee(&frog, points, bonus, caregiver, show_bonus, bee_eaten, bee_pos);

            BlockPond(&frog, number_of_lives, pond1, pond2, pond3, pond4, pond5, pond, worldTime2, points);

            if (worldTime2 == 30){
                draw_dog = 1;
            }

        } else if (menu == 1) {
//displaying menu

            if(active_results_list==1){
                if(records != NULL) {
                    free(records);
                    records=NULL;
                    active_results_list=0;
                }
            }
            SDL_FillRect(screen, NULL, czarny);
            DrawRectangle(screen, BUILD_BLOCK_SIZE/2, BUILD_BLOCK_SIZE/2, SCREEN_WIDTH - BUILD_BLOCK_SIZE, SCREEN_HEIGHT - BUILD_BLOCK_SIZE, czerwony, niebieski);
            DrawRectangle(screen, screen->w / 2 - strlen(text) * 8 / 2 - 2*BUILD_BLOCK_SIZE, height, 200, BUILD_BLOCK_SIZE/2, czerwony, czerwony);

            sprintf(text, "FROGGER");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 30, text, charset);
            sprintf(text, "Play");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 200, text, charset);
            sprintf(text, "Table of records");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 250, text, charset);
            sprintf(text, "Quit");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 300, text, charset);

            SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, scrtex, NULL, NULL);
            SDL_RenderPresent(renderer);

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
                        else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
                            if (height <= 290 && height > 190) {
                                height -= BUILD_BLOCK_SIZE + 10;
                            }
                        }
                        else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
                                if (height < 290 && height >= 190) {
                                    height += BUILD_BLOCK_SIZE + 10;
                                }
                            }
                        else if (event.key.keysym.sym == SDLK_RETURN) {
                            if (height == 190) {
                                StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                                menu = 0;
                            } else if (height == 240){
                                menu = 2;
                            } else if (height == 290) {
                                quit = 1;
                            }
                        }
                        break;
                    case SDL_KEYUP:
                        break;
                    case SDL_QUIT:
                        quit = 1;
                        break;
                }
            }
            frames++;
        } else if(menu == 2){
// displaying list of highest scores

            SDL_FillRect(screen, NULL, czarny);
            DrawRectangle(screen, BUILD_BLOCK_SIZE/2, BUILD_BLOCK_SIZE/2, SCREEN_WIDTH - BUILD_BLOCK_SIZE, SCREEN_HEIGHT - BUILD_BLOCK_SIZE, czerwony, niebieski);
            sprintf(text, "TABLE OF RECORDS");
            DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, BUILD_BLOCK_SIZE, text, charset);

            if( active_results_list==0){
                records = ReadFromFile(filename);
                active_results_list=1;
            }

            if(records == NULL){
                sprintf(text, "There was a problem with loading a file");
                DrawString(screen, 200, 100 + BUILD_BLOCK_SIZE/2, text, charset);
            }

            for (int i=0; i<10; i++) {
                sprintf(text, "%d)", i + 1);
                DrawString(screen, 200, 100 + BUILD_BLOCK_SIZE/2 * i, text, charset);
                sprintf(text, "%s", records[i].nickname);
                DrawString(screen, 230, 100 + BUILD_BLOCK_SIZE/2 * i, text, charset);
                sprintf(text, " %d", records[i].points);
                DrawString(screen, 350, 100 + BUILD_BLOCK_SIZE/2 * i, text, charset);
            }
            sprintf(text, "Press q to go back to menu");
            DrawString(screen, 200, SCREEN_HEIGHT - BUILD_BLOCK_SIZE, text, charset);


            SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, scrtex, NULL, NULL);
            SDL_RenderPresent(renderer);

            while(SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_KEYDOWN:
                        if(event.key.keysym.sym == SDLK_ESCAPE) {
                            quit = 1;
                        }
                        if(event.key.keysym.sym == SDLK_q) {
                            StartOver(&frog, &little_frog, quit_game, menu, bee_eaten, number_of_lives, points, level, pond1, pond2, pond3, pond4, pond5, worldTime, worldTime2);
                            menu = 1;
                        }
                        break;
                    case SDL_KEYUP:
                        break;
                    case SDL_QUIT:
                        quit = 1;
                        break;
                }
            }
            frames++;
        }
    }


    SDL_FreeSurface(charset);
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(frog.frog);
    SDL_FreeSurface(little_frog.frog);
    SDL_FreeSurface(froggy);
    SDL_FreeSurface(bee);
    SDL_FreeSurface(car);
    SDL_FreeSurface(car2);
    SDL_FreeSurface(lorry);
    SDL_FreeSurface(turtle);
    SDL_FreeSurface(log);
    SDL_FreeSurface(heart);
    SDL_FreeSurface(racer);
    SDL_FreeSurface(end);
    SDL_FreeSurface(crocodile);
    SDL_FreeSurface(head_croc);
    SDL_FreeSurface(snake);
    SDL_FreeSurface(dog);
    SDL_DestroyTexture(scrtex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);



    SDL_Quit();
    return 0;
}
