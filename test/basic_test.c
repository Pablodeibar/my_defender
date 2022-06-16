/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/my_defender.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_getnbr, basic)
{
    char *str = "33";
    long nb = my_getnbr(str);
    cr_assert_eq(nb, 33);
}

Test(my_getnbr, zero)
{
    char *str = "0";
    long nb = my_getnbr(str);
    cr_assert_eq(nb, 0);
}
