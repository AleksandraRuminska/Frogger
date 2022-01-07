//
// Created by Aleksandra Ruminska on 07/01/2020.
//

#ifndef PROJECT_NICER_DRAW_H
#define PROJECT_NICER_DRAW_H

#endif //PROJECT_NICER_DRAW_H
#define BUILD_BLOCK_SIZE 40

void DrawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset);
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, float cordsx, float cordsy);
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color);
void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color);
void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);