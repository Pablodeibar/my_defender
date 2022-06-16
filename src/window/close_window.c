/*
** EPITECH PROJECT, 2022
** close
** File description:
** close
*/

#include "my_defender.h"

void change_color_of_button(scene_t *scene, sprite_t *sprite)
{
    int x = sfRectangleShape_getPosition(scene->button.rect).x;
    int y = sfRectangleShape_getPosition(scene->button.rect).y;
    int x_l = sfRectangleShape_getPosition(scene->button.leave).x;
    int y_l = sfRectangleShape_getPosition(scene->button.leave).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    sfColor sfGray = sfColor_fromRGB(200, 200, 200);

    if (mu_x >= x && mu_x <= (x + 150) && mu_y >= y && mu_y <= (y + 70)) {
        sfRectangleShape_setFillColor(scene->button.rect, sfGray);
        sfRectangleShape_setOutlineThickness(scene->button.rect, 4);
    } else if (mu_x >= x_l && mu_x <= (x_l + 170) &&
            mu_y >= y_l && mu_y <= (y_l + 75)) {
        sfRectangleShape_setFillColor(scene->button.leave, sfGray);
        sfRectangleShape_setOutlineThickness(scene->button.leave, 4);
    } else {
        change_color_of_button2(scene, sprite);
    }
}

int detect_menu_2(scene_t *scene, sprite_t *sprite, int need)
{
    int x = sfRectangleShape_getPosition(scene->button.how).x;
    int y = sfRectangleShape_getPosition(scene->button.how).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;

    if (mu_x >= x && mu_x <= (x + 320) && mu_y >= y && mu_y <= (y + 80)) {
        need = 3;
        sound_start(sprite);
    }
    return (need);
}

int detect_menu(scene_t *scene, sprite_t *sprite)
{
    int x = sfRectangleShape_getPosition(scene->button.rect).x;
    int y = sfRectangleShape_getPosition(scene->button.rect).y;
    int x_l = sfRectangleShape_getPosition(scene->button.leave).x;
    int y_l = sfRectangleShape_getPosition(scene->button.leave).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    int need = 0;

    if (mu_x >= x && mu_x <= (x + 150) && mu_y >= y && mu_y <= (y + 70)) {
        sound_start(sprite);
        need = 1;
    }
    if (mu_x >= x_l && mu_x <= (x_l + 170) &&
        mu_y >= y_l && mu_y <= (y_l + 75)) {
        need = 2;
        sound_start(sprite);
    }
    need = detect_menu_2(scene, sprite, need);
    return (need);
}

int close_menu(sfRenderWindow *window, sprite_t *sprite, scene_t *scene)
{
    sfEvent event;
    int need = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        change_color_of_button(scene, sprite);
        if (event.type == sfEvtMouseButtonPressed) {
            need = detect_menu(scene, sprite);
        }
    }
    return (need);
}

int close_win(sfRenderWindow *window, sprite_t *sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
