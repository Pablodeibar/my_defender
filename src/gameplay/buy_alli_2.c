/*
** EPITECH PROJECT, 2022
** buyalli
** File description:
** buyalli
*/

#include "my_defender.h"

int event_key(sfEvent event, sprite_t *sprite)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        sfClock_restart(sprite->clock);
        sprite->pause = 0;
    }
}

int event_menu_pause_2(sprite_t *sprite, int mu_y, int mu_x, int y)
{
    int x = 700;
    char *str = "./my_defender";
    char *av[1] = {str};

    if (mu_x >= x && mu_x <= (x + 400) && mu_y >= y && mu_y <= (y + 50)) {
        sfRenderWindow_close(sprite->window);
        main(1, av);
    }
    y += 250;
    if (mu_x >= x && mu_x <= (x + 400) && mu_y >= y && mu_y <= (y + 50))
        sfRenderWindow_close(sprite->window);
    return (y);
}

void event_menu_pause_condition(int mu_y, int mu_x, int y, sprite_t *sprite)
{
    int x = 700;

    if (mu_x >= x && mu_x <= (x + 400) && mu_y >= y && mu_y <= (y + 50)) {
        sfClock_restart(sprite->clock);
        sprite->pause = 0;
    }
}

int event_menu_pause(sprite_t *sprite, scene_t *scene, Liste_t *list)
{
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    int x = 700;
    int y = 200;
    char *str = "./my_defender";
    char *av[1] = {str};
    sfEvent event;

    while (sfRenderWindow_pollEvent(sprite->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
        if (event.type == sfEvtMouseButtonPressed) {
            event_menu_pause_condition(mu_y, mu_x, y, sprite);
            y += 250;
            y = event_menu_pause_2(sprite, mu_y, mu_x, y);
        }
    }
}

int events(sprite_t *sprite, scene_t *scene, Liste_t *list)
{
    if (sprite->pause == 0) {
        close_game(sprite, scene, list);
    } else if (sprite->pause == 1) {
        event_menu_pause(sprite, scene, list);
    } else {
        close_game(sprite, scene, list);
    }
}
