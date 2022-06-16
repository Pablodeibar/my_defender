/*
** EPITECH PROJECT, 2022
** life.c
** File description:
** life
*/

#include "my_defender.h"

void init_life(scene_t *scen, sprite_t *sprite, sfClock *clock)
{
    sfVector2f pos_life = {170, 5};
    sfIntRect rect = {0, 0, 275, 55};
    char *life = "assets/images/life.png";

    sprite->rect_life = rect;
    scen->sprite.life_spr = sfSprite_create();
    scen->sprite.life_tex = sfTexture_createFromFile(life, NULL);
    sfSprite_setTexture(scen->sprite.life_spr, scen->sprite.life_tex, sfFalse);
    sfSprite_setPosition(scen->sprite.life_spr , pos_life);
    sfSprite_setTextureRect(scen->sprite.life_spr, sprite->rect_life);
}

void change_rect_life(sprite_t *sprite)
{
    take_time(sprite->clock, sprite);
    if (sprite->second_rand > 2000000) {
        sprite->rect_life.width -= 55;
        sprite->loose++;
        sprite->second_rand -= 2000000;
    }
}

void verif_life(Liste_t *list, sprite_t *sprite)
{
    element_t *actuel = list->premier;
    int i = 1;

    actuel = list->premier->suivant;
    while (actuel != NULL) {
        if (actuel->who == 8 && sfSprite_getPosition(actuel->test_spr).x >
        1920)
            sup_el(list, i);
        if (sfSprite_getPosition(actuel->test_spr).x < 255 &&
            actuel->who > 2 && actuel->who < 7)
            change_rect_life(sprite);
        actuel = actuel->suivant;
        i++;
    }
    if (sprite->loose == 5 || sprite->loose > 5)
        sprite->pause = 2;
}
