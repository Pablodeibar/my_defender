/*
** EPITECH PROJECT, 2022
** getnbr
** File description:
** getnbr
*/

#include "../../include/my_defender.h"

int my_power_rec(int nbr, int p)
{
    if (p == 0) {
        return 1;
    } else if (nbr == 0) {
        return 0;
    } else {
        return nbr * my_power_rec(nbr, p - 1);
    }
}

char operator(char *str)
{
    int j = 0;
    for (int i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            j++;
    }
    if (0 != j % 2)
        return ('-');
    else
        return ('+');
}

char *get_str(char *str)
{
    int i = 0;
    char *nbr;
    int j = 0;

    nbr = malloc(sizeof(char) * 60);
    while (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        nbr[j] = str[i];
        i++;
        j++;
    }
    nbr[i] = '\0';
    return nbr;
}

long nbr(char operator, char *nbr)
{
    int result = 0;
    int j = 0;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        result = result + (nbr[j] - '0') * my_power_rec(10, i);
        j++;
    }
    if (operator == '-') {
        return (-result);
    } else
        return (result);
}

long my_getnbr(char *str)
{
    return (nbr(operator(str), get_str(str)));
}
