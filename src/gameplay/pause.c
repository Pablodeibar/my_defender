/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "my_defender.h"

sfRectangleShape **create_button(sfRectangleShape **button, sfColor sfGray)
{
    sfVector2f pos = {700, 200};
    sfVector2f size = {400, 50};

    button = malloc(sizeof(sfRectangleShape *) * 3);
    for (int i = 0; i != 3; i++) {
        button[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(button[i], sfWhite);
        sfRectangleShape_setPosition(button[i], pos);
        pos.y += 250;
        sfRectangleShape_setSize(button[i], size);
        sfRectangleShape_setOutlineThickness(button[i], 1);
        sfRectangleShape_setOutlineColor(button[i], sfGray);
    }
    return button;
}

sfText **text_button(sfText **text)
{
    sfVector2f pos = {840, 210};
    sfVector2f pos2 = {715, 460};
    sfVector2f pos3 = {860, 710};
    sfFont *font = sfFont_createFromFile("assets/font/font.otf");

    text = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i != 3; i++) {
        text[i] = sfText_create();
        sfText_setFont(text[i], font);
        sfText_setColor(text[i], sfBlack);
        sfText_setCharacterSize(text[i], 25);
    }
    sfText_setPosition(text[0], pos);
    sfText_setPosition(text[1], pos2);
    sfText_setPosition(text[2], pos3);
    sfText_setString(text[0], "resume");
    sfText_setString(text[1], "return  to  main  menu");
    sfText_setString(text[2], "leave");
    return text;
}

int rea_time(sprite_t *sprite, scene_t *scene)
{
    int x = sfRectangleShape_getPosition(scene->button.pause).x;
    int y = sfRectangleShape_getPosition(scene->button.pause).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;

    if (mu_x >= x && mu_x <= (x + 70) && mu_y >= y && mu_y <= (y + 70))
        return (1);
    return (0);
}

int detect_pause(scene_t *scene, sprite_t *sprite, int need, Liste_t *list)
{
    int x = sfRectangleShape_getPosition(scene->button.pause).x;
    int y = sfRectangleShape_getPosition(scene->button.pause).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    element_t *tmp = list->premier;

    if (mu_x >= x && mu_x <= (x + 70) && mu_y >= y && mu_y <= (y + 70)) {
        take_time(sprite->clock, sprite);
        sprite->pause = 1;
        need = 1;
    }
    return (need);
}

void ini_pause(scene_t *scene)
{
    sfVector2f pos = {1830, 10};
    sfVector2f size = {70, 70};

    scene->button.pause = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.pause, sfGreen);
    sfRectangleShape_setPosition(scene->button.pause, pos);
    sfRectangleShape_setSize(scene->button.pause, size);
    sfRectangleShape_setOutlineThickness(scene->button.pause, 1);
    sfRectangleShape_setOutlineColor(scene->button.pause, sfBlack);
}
