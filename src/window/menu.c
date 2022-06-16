/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#include "my_defender.h"

int verif_choice(int need, scene_t scene, sprite_t sprite)
{
    if (need == 1) {
        sfRenderWindow_close(sprite.window);
        game();
    }
    if (need == 3)
        menu_2(scene, sprite);
}

int menu(scene_t scene, sprite_t sprit, int nbr)
{
    sfVideoMode md = {1920, 1080, 32};
    sfVector2f pos_i = {0, 0};
    int need = 0;
    char *str = "menu";

    init_objs(&scene, "assets/images/menu_back.jpg", pos_i);
    if (nbr == 0)
        sprit.window = sfRenderWindow_create(md, str, sfResize | sfClose,
        NULL);
    while (sfRenderWindow_isOpen(sprit.window)) {
        sfRenderWindow_clear(sprit.window, sfBlack);
        need = close_menu(sprit.window, &sprit, &scene);
        if (need == 1 || need == 2 || need == 3)
            break;
        draw_menu(&sprit, &scene);
        sfRenderWindow_display(sprit.window);
    }
    verif_choice(need, scene, sprit);
    destroy(&sprit, &scene);
}
