/*
** EPITECH PROJECT, 2022
** coin
** File description:
** coin
*/

#include "my_defender.h"

int init_coins(scene_t *scene)
{
    sfVector2f pos = {50, 10};

    if (scene->text.font == NULL)
        return (84);
    scene->text.coins = sfText_create();
    sfText_setFont(scene->text.coins, scene->text.font);
    sfText_setCharacterSize(scene->text.coins, 40);
    sfText_setPosition(scene->text.coins, pos);
}

char *int_to_char(int result)
{
    int i = 0;
    char *str;
    int compteur = 0;

    for (int rep = result; rep < -9 || rep > 9; i++)
        rep = rep / 10;
    str = malloc(sizeof(char) * (i + 3));
    if (result < 0) {
        result = -result;
        str[0] = '-';
        str[1] = '\0';
        compteur++;
    }
    for (; i != -1; compteur++, i--) {
        str[compteur] = '0' + (result / my_power_rec(10, i));
        str[compteur + 1] = '\0';
        result -= (result / my_power_rec(10, i)) * my_power_rec(10, i);
    }
    return (str);
}

int count_coin(sfClock *clock, scene_t *scene, sprite_t *sprite, int coins)
{
    char *nbr;

    take_time(clock, sprite);
    if (sprite->second_coins > 1000000) {
        coins += 1;
        sprite->second_coins -= 1000000;
    }
    nbr = int_to_char(coins);
    sfText_setString(scene->text.coins, nbr);
    if (nbr == NULL)
        return (84);
    free(nbr);
    return (coins);
}
