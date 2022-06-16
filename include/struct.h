/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#ifndef struct_h
    #define struct_h
    #include "my_setup.h"

typedef struct element_s{
    int nombre;
    sfSprite *test_spr;
    sfTexture *test_tex;
    sfVector2f pos;
    sfVector2f speed;
    int damage;
    int life;
    int need;
    sfIntRect rect;
    int offset;
    int max;
    int top;
    int max_top;
    int who;
    sfVector2f move;
    int arrived;
    struct element_s *suivant;
    int start_top;
    int attack;
    int visible;
}element_t;

typedef struct Liste_s{
    element_t *premier;
}Liste_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfRectangleShape *leave;
    sfRectangleShape *how;
    sfRectangleShape *back;
    sfRectangleShape *shop_1;
    sfRectangleShape *shop_2;
    sfRectangleShape *shop_3;
    sfRectangleShape *shop_4;
    sfRectangleShape *pause;
}button_t;

typedef struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
}game_object_t;

typedef struct text_s {
    sfText *text;
    sfText *leave;
    sfText *how;
    sfText *back;
    sfText *coins;
    sfFont *font;
}text_t;

typedef struct sprite_s{
    sfRenderWindow *window;
    sfSprite *map_s;
    sfTexture *map_t;
    sfSprite *expl_s;
    sfTexture *expl_t;
    sfMusic *music_back;
    sfSound *start;
    sfSound *not_enought;
    int second_en;
    int second_coins;
    int second_rand;
    int pause;
    sfSprite *coin_s;
    sfTexture *coin_t;
    sfSprite *test_s;
    sfTexture *test_t;
    sfSprite *mor_shop_spr;
    sfTexture *mor_shop_tex;
    sfSprite *rig_shop_spr;
    sfTexture *rig_shop_tex;
    sfSprite *las_shop_spr;
    sfTexture *las_shop_tex;
    sfSprite *ball_shop_spr;
    sfTexture *ball_shop_tex;
    sfSound *buy;
    sfClock *clock;
    sfSprite *life_spr;
    sfTexture *life_tex;
    sfIntRect rect_life;
    int loose;
    sfIntRect rect_over;
    sfSprite *end_spr;
    sfTexture *end_tex;
}sprite_t;

typedef struct scene_s {
    struct game_object_s objs;
    struct button_s button;
    struct text_s text;
    struct Liste_s list;
    struct element_s element;
    struct sprite_s sprite;
}scene_t;

#endif /* !struct_h */
