/*
** EPITECH PROJECT, 2022
** clock
** File description:
** clock
*/

#include "../../include/my_defender.h"

void take_time(sfClock *clock, sprite_t *sprite)
{
    sfTime currElapsedTime = sfClock_getElapsedTime(clock);

    if (sprite->pause == 0 || sprite->pause == 2) {
        sfClock_restart(clock);
        sprite->second_en += currElapsedTime.microseconds;
        sprite->second_coins += currElapsedTime.microseconds;
        sprite->second_rand += currElapsedTime.microseconds;
    }
}

void move_list(Liste_t *list, sfClock *clock, sprite_t *sprite)
{
    element_t *actuel = list->premier;
    int x;

    actuel = list->premier->suivant;
    take_time(clock, sprite);
    if (sprite->second_en > 150000) {
        while (actuel != NULL) {
            move_link(&actuel->rect, actuel);
            actuel = actuel->suivant;
        }
        sprite->second_en -= 150000;
    }
}

void clock(sfClock *clock, sprite_t *sprite, Liste_t *list)
{
    if (list->premier->need == 1) {
        move_list(list, clock, sprite);
    }
}
