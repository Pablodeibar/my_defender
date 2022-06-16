/*
** EPITECH PROJECT, 2022
** inishop
** File description:
** inishop
*/

#include "my_defender.h"

int detect_shop_4(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins)
{
    int x = sfRectangleShape_getPosition(scene->button.shop_4).x;
    int y = sfRectangleShape_getPosition(scene->button.shop_4).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;

    if (mu_x >= x && mu_x <= (x + 100) && mu_y >= y && mu_y <= (y + 100)) {
        if (coins >= 30) {
            sound_buy(sprite);
            add_end_test(list, 8);
            coins -= 30;
        } else {
            sound_not_enough(sprite);
        }
    }
    return (coins);
}

int detect_shop_3(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins)
{
    int x = sfRectangleShape_getPosition(scene->button.shop_3).x;
    int y = sfRectangleShape_getPosition(scene->button.shop_3).y;
    int mu_x = sfMouse_getPositionRenderWindow(sprite->window).x;
    int mu_y = sfMouse_getPositionRenderWindow(sprite->window).y;

    if (mu_x >= x && mu_x <= (x + 100) && mu_y >= y && mu_y <= (y + 100)) {
        if (coins >= 10) {
            sound_buy(sprite);
            add_end_test(list, 7);
            coins -= 10;
        } else {
            sound_not_enough(sprite);
        }
    }
    coins = detect_shop_4(scene, sprite, list, coins);
    return (coins);
}

void ini_image_shop_2(sprite_t *sprite, sfVector2f pos_3, sfVector2f pos_4)
{
    sfVector2f pos_las = {260, 890};
    char *mr_laser = "assets/images/left/mr_laser_shop.png";
    char *fireball = "assets/images/left/fireball_shop.png";

    sprite->las_shop_spr = sfSprite_create();
    sprite->las_shop_tex = sfTexture_createFromFile(mr_laser, NULL);
    sfSprite_setTexture(sprite->las_shop_spr, sprite->las_shop_tex, sfFalse);
    sfSprite_setPosition(sprite->las_shop_spr, pos_las);
    sprite->ball_shop_spr = sfSprite_create();
    sprite->ball_shop_tex = sfTexture_createFromFile(fireball, NULL);
    sfSprite_setTexture(sprite->ball_shop_spr, sprite->ball_shop_tex, sfFalse);
    sfSprite_setPosition(sprite->ball_shop_spr, pos_4);
}

void ini_shop_3(scene_t *scene, sprite_t *sprite)
{
    sfVector2f pos_3 = {250, 880};
    sfVector2f pos_4 = {350, 880};
    sfVector2f size = {100, 100};

    scene->button.shop_3 = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.shop_3, sfBlue);
    sfRectangleShape_setPosition(scene->button.shop_3, pos_3);
    sfRectangleShape_setSize(scene->button.shop_3, size);
    sfRectangleShape_setOutlineThickness(scene->button.shop_3, 1);
    sfRectangleShape_setOutlineColor(scene->button.shop_3, sfBlack);
    scene->button.shop_4 = sfRectangleShape_create();
    sfRectangleShape_setFillColor(scene->button.shop_4, sfBlue);
    sfRectangleShape_setPosition(scene->button.shop_4, pos_4);
    sfRectangleShape_setSize(scene->button.shop_4, size);
    sfRectangleShape_setOutlineThickness(scene->button.shop_4, 1);
    sfRectangleShape_setOutlineColor(scene->button.shop_4, sfBlack);
    ini_image_shop_2(sprite, pos_3, pos_4);
}
