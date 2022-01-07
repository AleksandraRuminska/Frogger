
//
// Created by Aleksandra Ruminska on 09/01/2020.
//

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL.h>
#include<SDL_main.h>

//extern "C" {
//#include"SDL2-2.0.10/include/SDL.h"
//#include"SDL2-2.0.10/include/SDL_main.h"
//}

#include "draw.h"
#include "colission.h"
#include "scores_file.h"

//compares values
int Comparator(const void * p, const void * q){
    int l = ((scores *)p)->points;
    int r = ((scores *)q)->points;
    return (r - l);
}


//checks if file of a given name exists
int IfFileExists(char filename[]){
    FILE * file;
    if ((file = fopen(filename, "r"))!= NULL){
        fclose(file);
        return 1;
    } else{
        return 0;
    }
}

//reads the content of the file
scores * ReadFromFile(char filename[]){
    scores * high_scores = (scores*)malloc(10*sizeof(scores));
    FILE * file = fopen(filename, "r");

    if(file==NULL){
        return NULL;
    }

    fread(high_scores, sizeof(scores), 10, file);
    return high_scores;
}

//compares new collected points with the smallest value in the file
scores * CheckIfBigger(char name[], int points, char filename[]){
    scores * records;
    records = ReadFromFile(filename);
    if(points > records[9].points){
        records[9].points = points;
        strcpy(records[9].nickname, name);
    }

    qsort(records, 10, sizeof(scores), Comparator);
    return records;
}

//writes points and name to the file
int WriteToFile (scores * high_scores, char filename[]){
    FILE * file;
    int written = -1;

    file = fopen(filename, "w+");
    if(file==NULL){
        return written;
    }
    fwrite(high_scores, sizeof(scores), 10, file);

    fclose(file);
    return (10*sizeof(scores));

}

//changes lowercase letters to uppercase
void ToUpercase(int i, char name[]){
    if(name[i] >= 'a' && name[i]<='z'){
        name[i] -= 32;
    }
}
