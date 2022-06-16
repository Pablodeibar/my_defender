/*
** EPITECH PROJECT, 2022
** linkedloop3
** File description:
** linkedloop3
*/

#include "my_defender.h"

int choose_damage(int who)
{
    int mordecai = 1;
    int rigsby = 5;
    int socoupe = 2;
    int mario = 1;
    int witch = 10;
    int sanji = 2;
    int laser = 2;
    int ball = 5000;

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
}

int choose_life_pnj(int who)
{
    int mordecai = 15;
    int rigsby = 15;
    int socoupe = 15;
    int mario = 15;
    int witch = 40;
    int sanji = 20;
    int laser = 20;
    int ball = 5000;

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
}

int choose_start_top(int who)
{
    int witch = 75;
    int sanji = 68;
    int laser = 75;

    switch (who) {
        case 5 : return (witch);
        case 6 : return (sanji);
        case 7 : return (laser);
    }
}

int choose_top(int who)
{
    int witch = 103;
    int sanji = 101;
    int laser = 75;

    switch (who) {
        case 5 : return (witch);
        case 6 : return (sanji);
        case 7 : return (laser);
    }
    if (who > 7)
        return (laser);
}

int choose_maxtop(int who)
{
    int witch = 281;
    int sanji = 1179;
    int laser = 1050;

    switch (who) {
        case 5 : return (witch);
        case 6 : return (sanji);
        case 7 : return (laser);
    }
    if (who > 7)
        return (laser);
}
