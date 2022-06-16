/*
** EPITECH PROJECT, 2022
** buy_alli
** File description:
** buy_alli
*/

#include "my_defender.h"

int detect_shop_2(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins)
{
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;
    int x1 = sfRectangleShape_getPosition(scene->button.shop_2).x;
    int y1 = sfRectangleShape_getPosition(scene->button.shop_2).y;

    if (mu_x >= x1 && mu_x <= (x1 + 100) && mu_y >= y1 && mu_y <= (y1 + 100)) {
        if (coins >= 20) {
            sound_buy(sprite);
            add_end_test(list, 2);
            coins -= 20;
        } else {
            sound_not_enough(sprite);
        }
    }
    return (coins);
}

int detect_shop(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins)
{
    int x = sfRectangleShape_getPosition(scene->button.shop_1).x;
    int y = sfRectangleShape_getPosition(scene->button.shop_1).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;

    if (mu_x >= x && mu_x <= (x + 100) && mu_y >= y && mu_y <= (y + 100)) {
        if (coins >= 10) {
            sound_buy(sprite);
            add_end_test(list, 1);
            coins -= 10;
        } else {
            sound_not_enough(sprite);
        }
    }
    coins = detect_shop_2(scene, sprite, list, coins);
    coins = detect_shop_3(scene, sprite, list, coins);
    return (coins);
}

int close_game(sprite_t *sprite, scene_t *scene, Liste_t *list)
{
    sfEvent event;
    int need = 0;
    static int coins = 500;

    coins = count_coin(sprite->clock, scene, sprite, coins);
    while (sfRenderWindow_pollEvent(sprite->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(sprite->window);
        if (event.type == sfEvtMouseButtonPressed) {
            need = detect_pause(scene, sprite, need, list);
            coins = detect_shop(scene, sprite, list, coins);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            take_time(sprite->clock, sprite);
            sprite->pause = 1;
            need = 1;
        }
    }
    return (need);
}

void ini_image_shop(sprite_t *sprite, sfVector2f pos_1, sfVector2f pos_2)
{
    char *mordecai = "assets/images/left/mordecai_shop.png";
    char *rigsby = "assets/images/left/rigsby_shop.png";

    sprite->mor_shop_spr = sfSprite_create();
    sprite->mor_shop_tex = sfTexture_createFromFile(mordecai, NULL);
    sfSprite_setTexture(sprite->mor_shop_spr, sprite->mor_shop_tex, sfFalse);
    sfSprite_setPosition(sprite->mor_shop_spr, pos_1);
    sprite->rig_shop_spr = sfSprite_create();
    sprite->rig_shop_tex = sfTexture_createFromFile(rigsby, NULL);
    sfSprite_setTexture(sprite->rig_shop_spr, sprite->rig_shop_tex, sfFalse);
    sfSprite_setPosition(sprite->rig_shop_spr, pos_2);
}

void ini_shop(scene_t *scene, sprite_t *sprite)
{
    sfVector2f pos_1 = {50, 880};
    sfVector2f pos_2 = {150, 880};
    sfVector2f size = {100, 100};

    scene->button.shop_1 = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.shop_1, sfGreen);
    sfRectangleShape_setPosition(scene->button.shop_1, pos_1);
    sfRectangleShape_setSize(scene->button.shop_1, size);
    sfRectangleShape_setOutlineThickness(scene->button.shop_1, 1);
    sfRectangleShape_setOutlineColor(scene->button.shop_1, sfBlack);
    scene->button.shop_2 = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.shop_2, sfGreen);
    sfRectangleShape_setPosition(scene->button.shop_2, pos_2);
    sfRectangleShape_setSize(scene->button.shop_2, size);
    sfRectangleShape_setOutlineThickness(scene->button.shop_2, 1);
    sfRectangleShape_setOutlineColor(scene->button.shop_2, sfBlack);
    ini_image_shop(sprite, pos_1, pos_2);
    ini_shop_3(scene, sprite);
}
