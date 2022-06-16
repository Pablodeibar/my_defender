/*
** EPITECH PROJECT, 2022
** ennemi
** File description:
** ennemi
*/

#include "my_defender.h"

void ennemi_link(Liste_t *list, sfClock *clock, sprite_t *sprite)
{
    float seconds = 0;
    sfTime time;
    int who;

    take_time(clock, sprite);
    if (sprite->second_rand > 5000000 && sprite->pause != 2) {
        who = rand() % 4 + 3;
        add_end_test(list, who);
        sprite->second_rand -= 5000000;
    }
}
