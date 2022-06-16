/*
** EPITECH PROJECT, 2022
** suppr_elem
** File description:
** suppr
*/

#include "my_defender.h"

int sup_el(Liste_t *list, int emplacement)
{
    element_t *tmp = list->premier;
    element_t *previous;
    int i;

    if (list == NULL || list->premier == NULL)
        return (84);
    for (i = 1; i != emplacement; i++) {
        tmp = tmp->suivant;
    }
    previous = tmp->suivant;
    tmp->suivant = tmp->suivant->suivant;
    if (previous == NULL || tmp == NULL)
        return (42);
    sfSprite_destroy(previous->test_spr);
    sfTexture_destroy(previous->test_tex);
    free(previous);
}
