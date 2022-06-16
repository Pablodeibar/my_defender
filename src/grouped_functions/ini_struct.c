/*
** EPITECH PROJECT, 2022
** ini
** File description:
** ini
*/

#include "my_defender.h"

void init_text_2(scene_t *scene, sfFont *font)
{
    char *str = "How to play";
    sfVector2f pos = {772, 50};

    scene->text.how = sfText_create();
    sfText_setPosition(scene->text.how, pos);
    sfText_setFont(scene->text.how, font);
    sfText_setColor(scene->text.how, sfBlack);
    sfText_setCharacterSize(scene->text.how, 40);
    sfText_setString(scene->text.how, str);
}

void init_text(scene_t *scene, char *str, sfVector2f pos)
{
    sfFont *font;
    sfVector2f pos_leave = {847, 910};

    font = sfFont_createFromFile("assets/font/font.otf");
    scene->text.text = sfText_create();
    sfText_setPosition(scene->text.text, pos);
    sfText_setFont(scene->text.text, font);
    sfText_setColor(scene->text.text, sfBlack);
    sfText_setCharacterSize(scene->text.text, 40);
    sfText_setString(scene->text.text, str);
    scene->text.leave = sfText_create();
    sfText_setPosition(scene->text.leave, pos_leave);
    sfText_setFont(scene->text.leave, font);
    sfText_setColor(scene->text.leave, sfBlack);
    sfText_setCharacterSize(scene->text.leave, 40);
    sfText_setString(scene->text.leave, "Leave");
    init_text_2(scene, font);
}

void init_objs(scene_t *scene, char *filepath, sfVector2f size)
{
    sfVector2f pos_b = {850, 510};
    sfVector2f size_b = {150, 70};

    scene->objs.texture = sfTexture_createFromFile(filepath, NULL);
    scene->objs.sprite = sfSprite_create();
    sfSprite_setTexture(scene->objs.sprite, scene->objs.texture, sfFalse);
    init_button(scene, pos_b, size_b);
}

void init_button_2(scene_t *scene)
{
    sfVector2f size = {320, 80};
    sfVector2f pos = {770, 30};

    scene->button.how = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.how, sfWhite);
    sfRectangleShape_setPosition(scene->button.how, pos);
    sfRectangleShape_setSize(scene->button.how, size);
    sfRectangleShape_setOutlineThickness(scene->button.how, 1);
    sfRectangleShape_setOutlineColor(scene->button.how, sfBlack);
}

void init_button(scene_t *scene, sfVector2f pos, sfVector2f size)
{
    char *str = "Play";
    sfVector2f pos_t = {870, 520};
    sfVector2f pos_leave = {840, 900};
    sfVector2f size_leave = {170, 75};

    scene->button.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.rect, sfWhite);
    sfRectangleShape_setPosition(scene->button.rect, pos);
    sfRectangleShape_setSize(scene->button.rect, size);
    sfRectangleShape_setOutlineThickness(scene->button.rect, 1);
    sfRectangleShape_setOutlineColor(scene->button.rect, sfBlack);
    init_text(scene, str, pos_t);
    scene->button.leave = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.leave, sfWhite);
    sfRectangleShape_setPosition(scene->button.leave, pos_leave);
    sfRectangleShape_setSize(scene->button.leave, size_leave);
    sfRectangleShape_setOutlineThickness(scene->button.leave, 1);
    sfRectangleShape_setOutlineColor(scene->button.leave, sfBlack);
    init_button_2(scene);
}
