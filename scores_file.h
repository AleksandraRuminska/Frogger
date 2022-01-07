//
// Created by Aleksandra Ruminska on 09/01/2020.
//

#ifndef PROJECT_NICER_SCORES_FILE_H
#define PROJECT_NICER_SCORES_FILE_H

#endif //PROJECT_NICER_SCORES_FILE_H

struct scores{
    char nickname[20];
    int points;
};

int Comparator(const void * p, const void * q);
int IfFileExists(char filename[]);
scores * ReadFromFile(char filename[]);
scores * CheckIfBigger(char name[], int points, char filename[]);
int WriteToFile (scores * high_scores, char filename[]);
void ToUpercase(int i, char name[]);