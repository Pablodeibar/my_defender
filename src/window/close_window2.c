/*
** EPITECH PROJECT, 2022
** close
** File description:
** close
*/

#include "my_defender.h"

int detect_menu_back(scene_t *scene, sprite_t *sprite)
{
    int x = sfRectangleShape_getPosition(scene->button.back).x;
    int y = sfRectangleShape_getPosition(scene->button.back).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    int need = 0;

    if (mu_x >= x && mu_x <= (x + 320) && mu_y >= y && mu_y <= (y + 80)) {
        sound_start(sprite);
        need = 1;
    }
    return (need);
}

void change_color_of_button3(scene_t *scene, sprite_t *sprite)
{
    int x = sfRectangleShape_getPosition(scene->button.back).x;
    int y = sfRectangleShape_getPosition(scene->button.back).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    sfColor sfGray = sfColor_fromRGB(200, 200, 200);

    if (mu_x >= x && mu_x <= (x + 320) && mu_y >= y && mu_y <= (y + 80)) {
        sfRectangleShape_setFillColor(scene->button.back, sfGray);
        sfRectangleShape_setOutlineThickness(scene->button.back, 4);
    } else {
        sfRectangleShape_setFillColor(scene->button.back, sfWhite);
        sfRectangleShape_setOutlineThickness(scene->button.back, 1);
    }
}

int back_menu(sfRenderWindow *window, sprite_t *sprite, scene_t *scene)
{
    sfEvent event;
    int need = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    change_color_of_button3(scene, sprite);
    if (event.type == sfEvtMouseButtonPressed) {
        need = detect_menu_back(scene, sprite);
    }
    return (need);
}

void change_color_of_button2(scene_t *scene, sprite_t *sprite)
{
    int x = sfRectangleShape_getPosition(scene->button.how).x;
    int y = sfRectangleShape_getPosition(scene->button.how).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    sfColor sfGray = sfColor_fromRGB(200, 200, 200);

    if (mu_x >= x && mu_x <= (x + 320) && mu_y >= y && mu_y <= (y + 80)) {
        sfRectangleShape_setFillColor(scene->button.how, sfGray);
        sfRectangleShape_setOutlineThickness(scene->button.how, 4);
    } else {
        sfRectangleShape_setFillColor(scene->button.rect, sfWhite);
        sfRectangleShape_setFillColor(scene->button.leave, sfWhite);
        sfRectangleShape_setFillColor(scene->button.how, sfWhite);
        sfRectangleShape_setOutlineThickness(scene->button.how, 1);
        sfRectangleShape_setOutlineThickness(scene->button.rect, 1);
        sfRectangleShape_setOutlineThickness(scene->button.leave, 1);
    }
}
