/*
** EPITECH PROJECT, 2022
** menu2
** File description:
** menu2
*/

#include "my_defender.h"

void button_back(scene_t *scene)
{
    sfVector2f size = {320, 80};
    sfVector2f pos = {1500, 800};
    char *str = "Back";
    sfVector2f pos_text = {1600, 815};
    sfFont *font;

    font = sfFont_createFromFile("assets/font/font.otf");
    scene->text.back = sfText_create();
    sfText_setPosition(scene->text.back, pos_text);
    sfText_setFont(scene->text.back, font);
    sfText_setColor(scene->text.back, sfBlack);
    sfText_setCharacterSize(scene->text.back, 40);
    sfText_setString(scene->text.back, str);
    scene->button.back = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.back, sfWhite);
    sfRectangleShape_setPosition(scene->button.back, pos);
    sfRectangleShape_setSize(scene->button.back, size);
    sfRectangleShape_setOutlineThickness(scene->button.back, 1);
    sfRectangleShape_setOutlineColor(scene->button.back, sfBlack);
}

void draw_button(scene_t *scene, sprite_t *sprite)
{
    sfRenderWindow_drawRectangleShape(sprite->window, scene->button.back,NULL);
    sfRenderWindow_drawText(sprite->window, scene->text.back,NULL);
}

int menu_2(scene_t scene, sprite_t sprite)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f pos_i = {0, 0};
    int need = 0;
    char *str = "assets/images/explication.png";

    button_back(&scene);
    sprite.expl_s = sfSprite_create();
    sprite.expl_t = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(sprite.expl_s, sprite.expl_t, sfFalse);
    while (sfRenderWindow_isOpen(sprite.window)) {
        sfRenderWindow_clear(sprite.window, sfBlack);
        need = back_menu(sprite.window, &sprite, &scene);
        if (need == 1)
            break;
        close_win(sprite.window, &sprite);
        sfRenderWindow_drawSprite(sprite.window, sprite.expl_s, NULL);
        draw_button(&scene, &sprite);
        sfRenderWindow_display(sprite.window);
    }
    menu(scene, sprite, 1);
}
