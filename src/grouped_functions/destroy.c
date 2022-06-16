/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroy
*/

#include "my_defender.h"

void destroy(sprite_t *sprite, scene_t *scene)
{
    return;
}

void destroy_game(sprite_t *sprite, Liste_t *list, scene_t *scene)
{
    element_t *actuel = list->premier;

    sfRectangleShape_destroy(scene->button.shop_1);
    sfRectangleShape_destroy(scene->button.shop_2);
    sfSprite_destroy(sprite->mor_shop_spr);
    sfSprite_destroy(sprite->rig_shop_spr);
    sfSprite_destroy(sprite->coin_s);
    sfSprite_destroy(sprite->map_s);
    sfClock_destroy(sprite->clock);
    sfMusic_destroy(sprite->music_back);
    sfText_destroy(scene->text.coins);
    sfSound_destroy(scene->sprite.start);
    sfSound_destroy(scene->sprite.not_enought);
    while (actuel != NULL) {
        sfSprite_destroy(actuel->test_spr);
        actuel = actuel->suivant;
    }
}
