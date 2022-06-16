/*
** EPITECH PROJECT, 2022
** draw
** File description:
** draw
*/

#include "my_defender.h"

void draw_2_con(Liste_t *list, sprite_t *sprite, element_t *actuel)
{
    if (actuel->visible == 1) {
        sfRenderWindow_drawSprite(sprite->window, actuel->test_spr, NULL);
        sfSprite_move(actuel->test_spr, actuel->move);
    }
}
