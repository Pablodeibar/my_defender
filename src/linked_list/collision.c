/*
** EPITECH PROJECT, 2022
** collision
** File description:
** collision
*/

#include "my_defender.h"

void ennem_alli_die(int *tab, Liste_t *list, element_t *temp,
element_t *temp_2)
{
    if (temp_2->life <= 0 && temp->arrived == 1 && temp->life > 0) {
        temp->move.x = choose_move(temp->who).x;
        temp->arrived = 0;
        temp_2->arrived = 0;
        temp->rect = choose_rect(temp->who);
        temp_2->visible = 0;
        sup_el(list, tab[1]);
    }
    if (temp->life <= 0 && temp->arrived == 1 && temp_2->life > 0){
        temp_2->move.x = choose_move(temp_2->who).x;
        temp_2->arrived = 0;
        temp->arrived = 0;
        temp_2->rect = choose_rect(temp_2->who);
        temp->visible = 0;
        sup_el(list, tab[0]);
    }
}

void collision_4(element_t *temp_2, element_t *temp)
{
    temp_2->arrived = 1;
    temp_2->move.x = 0;
    temp_2->rect = choose_new_rect(temp_2->who);
    if (temp->who == 7)
        temp->rect = choose_new_rect(temp->who);
    temp->arrived = 1;
    temp->move.x = 0;
}

void collision_3(element_t *temp, element_t *temp_2, Liste_t *list, int j)
{
    if (sfSprite_getPosition(temp->test_spr).x + temp->offset >=
        sfSprite_getPosition(temp_2->test_spr).x && temp->who == 8)
        sup_el(list, j);
    else if ((sfSprite_getPosition(temp->test_spr).x + temp->offset >=
    sfSprite_getPosition(temp_2->test_spr).x)
    && (temp_2->arrived == 0 && temp->arrived == 0)) {
        collision_4(temp_2, temp);
    }
    if (temp->attack == 1 && temp->arrived == 1) {
        temp_2->life -= temp->damage;
        temp->attack = 0;
    }
    if (temp_2->attack == 1 && temp_2->arrived == 1) {
        temp->life -= temp_2->damage;
        temp_2->attack = 0;
    }
}

int collision_2(element_t *temp, element_t *temp_2, int i, Liste_t *list)
{
    int j = 1;
    int tab[2] = {i, j};

    while (temp_2->suivant != NULL) {
        if (temp_2->who > 2 && temp_2->who < 7) {
            collision_3(temp, temp_2, list, tab[1]);
            ennem_alli_die(tab, list, temp, temp_2);
        }
        if (temp_2 == NULL || list == NULL)
            return (84);
        else {
            temp_2 = temp_2->suivant;
            tab[1]++;
        }
    }
}

int collision(Liste_t *list, sprite_t *sprite)
{
    element_t *temp = list->premier;
    element_t *temp_2 = list->premier;
    int i = 1;

    temp = temp->suivant;
    while (temp != NULL) {
        verif_pos(temp, list, i);
        if (temp->who <= 2 || temp->who >= 7) {
            temp_2 = temp_2->suivant;
            collision_2(temp, temp_2, i, list);
        }
        if (temp == NULL || list == NULL)
            return (84);
        else {
            temp = temp->suivant;
            i++;
        }
    }
}
