/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "my_defender.h"

void end_game(sprite_t sprite, scene_t scene, Liste_t *list)
{
    destroy_game(&sprite, list, &scene);
    sfRenderWindow_destroy(sprite.window);
}

int game(void)
{
    sprite_t sprite;
    scene_t scene;
    sfVideoMode md = {1920, 1080, 32};
    Liste_t *list = ini();
    element_t *actuel = list->premier;

    initi_sprit(&sprite, &scene);
    sprite.window = sfRenderWindow_create(md, "game", sfResize | sfClose,
    NULL);
    while (sfRenderWindow_isOpen(sprite.window)) {
        sfRenderWindow_clear(sprite.window, sfBlack);
        events(&sprite, &scene, list);
        clock(sprite.clock, &sprite, list);
        ennemi_link(list, sprite.clock, &sprite);
        collision(list, &sprite);
        verif_life(list, &sprite);
        choose_draw(&sprite, &scene, list);
        sfRenderWindow_display(sprite.window);
    }
    end_game(sprite, scene, list);
}
