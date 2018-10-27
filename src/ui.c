//
//  ui.c
//  catake
//
//  Created by Davyd Maiboroda on 10/26/18.
//  Copyright © 2018 Davyd Maiboroda. All rights reserved.
//

#include "ui.h"

bool init_ui(Entity *entity) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_EnableKeyRepeat(0, 0);
    SDL_WM_SetCaption("Catake", NULL);
    Mix_Init(0);
    TTF_Init();
    
    entity->buffer = SDL_SetVideoMode(SCREEN_WIDTH, 
                                    SCREEN_HEIGHT, 
                                    BIT_PER_PIXEL, 
                                    SDL_HWSURFACE);
    entity->player = load_image("res/cat_fighter_sprite1.png");
    entity->enemy = load_image("res/cat_fighter_sprite2.png");
    return true;
}

SDL_Surface* load_image(const char *filename) {
    SDL_Surface* load = IMG_Load(filename);
    if (load == NULL) { printf("Error loading: %s", filename); }
    SDL_Surface* image = SDL_DisplayFormatAlpha(load);
    SDL_FreeSurface(load);
    return image;
}

void dest_ui(Entity* entity) {
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}
