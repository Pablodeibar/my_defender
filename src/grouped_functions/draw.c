/*
** EPITECH PROJECT, 2022
** draw
** File description:
** draw
*/

#include "my_defender.h"

void draw_2(sprite_t *sprit, scene_t *scen, Liste_t *list)
{
    sfRenderWindow_drawSprite(sprit->window, sprit->map_s, NULL);
    sfRenderWindow_drawText(sprit->window, scen->text.coins, NULL);
    sfRenderWindow_drawSprite(sprit->window, sprit->coin_s, NULL);
    sfRenderWindow_drawRectangleShape(sprit->window, scen->button.pause, NULL);
    sfRenderWindow_drawRectangleShape(sprit->window, scen->button.shop_1,
    NULL);
    sfRenderWindow_drawRectangleShape(sprit->window, scen->button.shop_2,
    NULL);
    sfRenderWindow_drawRectangleShape(sprit->window, scen->button.shop_3,
    NULL);
    sfRenderWindow_drawRectangleShape(sprit->window, scen->button.shop_4,
    NULL);
}

void draw(sprite_t *sprite, scene_t *scene, Liste_t *list)
{
    element_t *actuel = list->premier;
    sfVector2f move = {0.15, 0};

    draw_2(sprite, scene, list);
    sfRenderWindow_drawSprite(sprite->window, sprite->mor_shop_spr, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->rig_shop_spr, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->las_shop_spr, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->ball_shop_spr, NULL);
    sfSprite_setTextureRect(scene->sprite.life_spr, sprite->rect_life);
    sfRenderWindow_drawSprite(sprite->window, scene->sprite.life_spr, NULL);
    if (list->premier->need == 1) {
        actuel = list->premier->suivant;
        while (actuel != NULL) {
            sfSprite_setTextureRect(actuel->test_spr, actuel->rect);
            draw_2_con(list, sprite, actuel);
            actuel = actuel->suivant;
        }
    }
}

void draw_menu(sprite_t *sprite, scene_t *scen)
{
    sfRenderWindow_drawSprite(sprite->window, scen->objs.sprite, NULL);
    sfRenderWindow_drawRectangleShape(sprite->window, scen->button.rect, NULL);
    sfRenderWindow_drawRectangleShape(sprite->window, scen->button.leave,
    NULL);
    sfRenderWindow_drawRectangleShape(sprite->window, scen->button.how, NULL);
    sfRenderWindow_drawText(sprite->window, scen->text.text, NULL);
    sfRenderWindow_drawText(sprite->window, scen->text.leave, NULL);
    sfRenderWindow_drawText(sprite->window, scen->text.how, NULL);
}

void draw_menu_pause(sprite_t *sprite)
{
    sfColor sfGray = sfColor_fromRGB(200, 200, 200);
    sfRectangleShape **button = create_button(button, sfGray);
    sfText **text = text_button(text);
    sfVector2f size = {1700, 800};
    sfVector2f pos = {100, 100};
    sfRectangleShape *menu;

    menu = sfRectangleShape_create();
    sfRectangleShape_setFillColor(menu, sfBlue);
    sfRectangleShape_setPosition(menu, pos);
    sfRectangleShape_setSize(menu, size);
    sfRectangleShape_setOutlineThickness(menu, 1);
    sfRectangleShape_setOutlineColor(menu, sfBlack);
    sfRenderWindow_drawRectangleShape(sprite->window, menu, NULL);
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawRectangleShape(sprite->window, button[i], NULL);
        sfRenderWindow_drawText(sprite->window, text[i], NULL);
    }
}

void change_rect(sprite_t *sprite)
{
    if (sprite->second_en > 140000) {
        sprite->rect_over.left += 1920;
        if (sprite->rect_over.left == 11520)
            sprite->rect_over.left = 0;
        sprite->second_en -= 140000;
    }
}

void choose_draw(sprite_t *sprite, scene_t *scene, Liste_t *list)
{
    draw(sprite, scene, list);
    if (sprite->pause == 1) {
        draw_menu_pause(sprite);
    } else if (sprite->pause == 2) {
        take_time(sprite->clock, sprite);
        change_rect(sprite);
        sfSprite_setTextureRect(sprite->end_spr, sprite->rect_over);
        sfRenderWindow_drawSprite(sprite->window, sprite->end_spr, NULL);
    }
}
