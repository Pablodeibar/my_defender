/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my_defender.h"

int main(int ar, char **av)
{
    scene_t scene;
    sprite_t sprite;
    sfVector2f pos_i = {0, 0};

    init_objs(&scene, "assets/images/menu_back.jpg", pos_i);
    if (ar == 1)
        menu(scene, sprite, 0);
    else if ((ar == 2) && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("You have to kill the ennemies with the machineguns");
        my_putstr(", the ennemies will come on the road and walk slowlie ");
        my_putstr("good luck !!!");
    } else {
        return (84);
    }
}
