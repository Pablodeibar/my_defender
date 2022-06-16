/*
** EPITECH PROJECT, 2022
** inisprite
** File description:
** inisprite
*/

#include "my_defender.h"

void initi_sprit_2(struct sprite_s *sprite)
{
    sfVector2f pos_coin = {2, 10};
    char *coin = "assets/images/left/coin.png";

    sprite->second_en = 0;
    sprite->second_coins = 0;
    sprite->second_rand = 0;
    sprite->pause = 0;
    sprite->coin_s = sfSprite_create();
    sprite->coin_t = sfTexture_createFromFile(coin, NULL);
    sfSprite_setTexture(sprite->coin_s, sprite->coin_t, sfFalse);
    sfSprite_setPosition(sprite->coin_s, pos_coin);
    sprite->map_s = sfSprite_create();
    sprite->map_t = sfTexture_createFromFile("assets/images/desert.png", NULL);
    sfSprite_setTexture(sprite->map_s, sprite->map_t, sfFalse);
}

void initi_sprit(struct sprite_s *sprite, scene_t *scene)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    scene->text.font = sfFont_createFromFile("assets/font/font.otf");
    init_coins(scene);
    initi_sprit_2(sprite);
    sprite->music_back = sfMusic_createFromFile("assets/music_sounds/mus.ogg");
    music(sprite);
    ini_pause(scene);
    ini_shop(scene, sprite);
    sprite->clock = sfClock_create();
    init_life(scene, sprite, sprite->clock);
    sprite->loose = 0;
    sprite->rect_over = rect;
    sprite->end_spr = sfSprite_create();
    sprite->end_tex = sfTexture_createFromFile("assets/images/over.png", NULL);
    sfSprite_setTexture(sprite->end_spr, sprite->end_tex, sfFalse);
    sfSprite_setTextureRect(sprite->end_spr, sprite->rect_over);
}
