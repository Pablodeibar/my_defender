/*
** EPITECH PROJECT, 2022
** linked
** File description:
** linked
*/

#include "my_defender.h"

void verif_pos(element_t *temp, Liste_t *list, int i)
{
    if (sfSprite_getPosition(temp->test_spr).x < 240
        && temp->who > 2 && temp->who < 7)
        sup_el(list, i);
    if (sfSprite_getPosition(temp->test_spr).x > 1700
        && temp->who < 2 && temp->who > 7)
        sup_el(list, i);
}

Liste_t *ini(void)
{
    Liste_t *liste = malloc(sizeof(*liste));
    element_t *element = malloc(sizeof(*element));

    element->suivant = NULL;
    liste->premier = element;
    liste->premier->need = 0;
    return liste;
}

void display_list(Liste_t *liste)
{
    element_t *actuel = liste->premier;

    while (actuel != NULL) {
        my_put_nbr(actuel->nombre);
        my_putchar(' ');
        actuel = actuel->suivant;
    }
}
