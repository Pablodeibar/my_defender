/*
** EPITECH PROJECT, 2022
** loop
** File description:
** loop
*/

#include "my_defender.h"

sfVector2f choose_move(int who)
{
    sfVector2f mordecai = {0.1, 0};
    sfVector2f rigsby  = {0.2, 0};
    sfVector2f sanji = {-0.35, 0};
    sfVector2f socoupe = {-0.3, 0};
    sfVector2f witch = {-0.2, 0};
    sfVector2f mario = {-0.15, 0};
    sfVector2f laser = {0.15, 0};
    sfVector2f ball = {0.4, 0};

    switch (who) {
        case 1 : return (mordecai);
        case 2 : return (rigsby);
        case 3 : return (socoupe);
        case 4 : return (mario);
        case 5 : return (witch);
        case 6 : return (sanji);
        case 7 : return (laser);
        case 8 : return (ball);
    }
    return (ball);
}

void add_end_test_2(element_t *new_el, int who)
{
    int offset = choose_offset(who);
    int max = choose_max(who);
    sfVector2f move = choose_move(who);
    int top = choose_top(who);
    int top_max = choose_maxtop(who);
    int start_top = choose_start_top(who);
    int life = choose_life_pnj(who);

    new_el->offset = offset;
    new_el->max = max;
    new_el->move = move;
    new_el->who = who;
    new_el->max_top = top_max;
    new_el->top = top;
    new_el->start_top = start_top;
    new_el->arrived = 0;
    new_el->life = life;
    new_el->attack = 0;
    new_el->visible = 1;
    new_el->damage = choose_damage(who);
}

int add_end_test(Liste_t *list, int who)
{
    element_t *temp = list->premier;
    element_t *new_el = malloc(sizeof(element_t));
    sfVector2f pos = choose_pos(who);
    char *perso = choose_perso(who);
    sfIntRect rect = choose_rect(who);

    if (new_el == NULL || list == NULL)
        return (84);
    new_el->test_tex = sfTexture_createFromFile(perso, NULL);
    new_el->test_spr = sfSprite_create();
    sfSprite_setTexture(new_el->test_spr, new_el->test_tex, sfFalse);
    sfSprite_setPosition(new_el->test_spr, pos);
    new_el->rect = rect;
    add_end_test_2(new_el, who);
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    new_el->suivant = NULL;
    temp->suivant = new_el;
    list->premier->need = 1;
}

sfIntRect choose_new_rect(int who)
{
    sfIntRect socoupe = {0, 0, 50, 53};
    sfIntRect mario = {0, 0, 97, 97};
    sfIntRect witch = {0, 75, 173, 103};
    sfIntRect sanji = {0, 68, 159, 101};
    sfIntRect laser = {0, 75, 232, 75};

    switch (who) {
        case 3 : return (socoupe);
        case 4 : return (mario);
        case 6 : return (sanji);
        case 5 : return (witch);
        case 7 : return (laser);
    }
}

int verif_attack(element_t *actuel)
{
    if (actuel->who <= 2 && actuel->arrived == 1)
        actuel->attack++;
}

int move_link(sfIntRect *rect, element_t *actuel)
{
    int max_value = actuel->max;
    int x = sfSprite_getPosition(actuel->test_spr).x;

    if (x > 1600 && actuel->who < 3 || x > 1600 && actuel->who == 7)
        actuel->move.x = 0;
    if (x < 255 && actuel->who > 2 && actuel->arrived == 0 &&
    actuel->who < 7) {
        actuel->arrived = 1;
        actuel->move.x = 0;
        actuel->rect = choose_new_rect(actuel->who);
    }
    if (actuel->arrived == 1 && actuel->who > 4) {
        rect->top += actuel->top ;
        if (rect->top == actuel->max_top) {
            rect->top = actuel->start_top;
            actuel->attack++;
        }
    } else {
        rect->left = rect->left + actuel->offset;
        if (rect->left == max_value) {
            rect->left = 0;
            verif_attack(actuel);
        }
    }
}
