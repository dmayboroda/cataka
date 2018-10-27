//
//  ui.h
//  cataka
//
//  Created by Davyd Maiboroda on 10/26/18.
//  Copyright © 2018 Davyd Maiboroda. All rights reserved.
//

#ifndef ui_h
#define ui_h

#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BIT_PER_PIXEL 32

typedef struct {
    SDL_Surface *buffer;
    SDL_Surface *tile;
    SDL_Surface *item;
    SDL_Surface *enemy;
    SDL_Surface *player;
} Entity;

bool init_ui(Entity *entity);
SDL_Surface* load_image(const char *filename);
void dest_ui(Entity *entity);

#define check_surface(entity)((entity) == NULL ? false : true)
#endif /* ui_h */
