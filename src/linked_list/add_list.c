/*
** EPITECH PROJECT, 2022
** list add
** File description:
** list add
*/

#include "my_defender.h"

void add_end(Liste_t *liste, int valeur)
{
    element_t *temp = liste->premier;
    element_t *new_el = malloc(sizeof(element_t));

    new_el->nombre = valeur;
    new_el->suivant = NULL;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = new_el;
}

void sup_end(Liste_t *liste)
{
    element_t *tmp = liste->premier;

    while (tmp->suivant->suivant != NULL) {
        tmp = tmp->suivant;
    }
    tmp->suivant = NULL;
}

void remove_zero(Liste_t *liste)
{
    element_t *list = liste->premier;

    while (list->suivant->suivant != NULL) {
        list = list->suivant;
    }
    list->suivant = NULL;
}

void sup_head(Liste_t *liste)
{
    element_t *aSupprimer = liste->premier;

    if (liste->premier != NULL) {
        liste->premier = liste->premier->suivant;
    }
    free(aSupprimer);
}
