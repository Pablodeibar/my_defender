/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

int my_putstr(char const *str)
{
    int compter = 0;

    while (str[compter] != '\0') {
        my_putchar(str[compter]);
        compter++;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int compteur = 0;

    while (str[compteur] != '\0') {
        compteur++;
    }
    return (compteur);
}
