//
//  ui.c
//  cataka
//
//  Created by Davyd Maiboroda on 10/26/18.
//  Copyright © 2018 Davyd Maiboroda. All rights reserved.
//

#include "ui.h"

bool init_ui(UI_obj *ui_obj) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_EnableKeyRepeat(0, 0);
    SDL_WM_SetCaption("Cataka", NULL);
    Mix_Init(0);
    TTF_Init();
    
    ui_obj->buffer = SDL_SetVideoMode(SCREEN_WIDTH, 
                                    SCREEN_HEIGHT, 
                                    BIT_PER_PIXEL, 
                                    SDL_HWSURFACE);
    ui_obj->player = load_image("res/sprite_player.png");
    ui_obj->enemy = load_image("res/cat_fighter_sprite2.png");
    return true;
}

SDL_Surface* load_image(const char *filename) {
    SDL_Surface* load = IMG_Load(filename);
    if (load == NULL) { printf("Error loading: %s", filename); }
    SDL_Surface* image = SDL_DisplayFormatAlpha(load);
    SDL_FreeSurface(load);
    return image;
}

void dest_surface(SDL_Surface* surface) {
    if (surface) { SDL_FreeSurface(surface); }
}

void dest_ui(UI_obj* ui_obj) {
    dest_surface(ui_obj->buffer);
    dest_surface(ui_obj->player);
    dest_surface(ui_obj->enemy);
    SDL_Quit();
}
