/*
** EPITECH PROJECT, 2022
** linked_loop_2
** File description:
** linked_loop_2
*/

#include "my_defender.h"

char *choose_perso(int who)
{
    char *mor = "assets/images/left/mordecai.png";
    char *rig = "assets/images/left/rigsby.png";
    char *socoupe = "assets/images/right/socoupe.png";
    char *mario = "assets/images/right/mario.png";
    char *sanji = "assets/images/right/sanji.png";
    char *sorciere = "assets/images/right/witch.png";
    char *laser = "assets/images/left/mr_laser.png";
    char *ball = "assets/images/left/fireballe.png";

    switch (who) {
        case 1 : return (mor);
        case 2 : return (rig);
        case 3 : return (socoupe);
        case 4 : return (mario);
        case 5 : return (sorciere);
        case 6 : return (sanji);
        case 7 : return (laser);
        case 8 : return (ball);
    }
}

sfVector2f choose_pos(int who)
{
    sfVector2f ally = {0, 770};
    sfVector2f ennemi = {1920, 770};

    switch (who) {
        case 1 : return (ally);
        case 2 : return (ally);
        case 3 : return (ennemi);
        case 4 : return (ennemi);
        case 5 : return (ennemi);
        case 6 : return (ennemi);
        case 7 : return (ally);
        case 8 : return (ally);
    }
}

sfIntRect choose_rect(int who)
{
    sfIntRect mordecai = {0, 0, 95 , 97};
    sfIntRect rigsby = {0, 0, 95, 97};
    sfIntRect socoupe = {0, 0, 50, 53};
    sfIntRect mario = {0, 0, 97, 97};
    sfIntRect witch = {0, 0, 56, 75};
    sfIntRect sanji = {0, 0, 71, 67};
    sfIntRect laser = {0, 0, 49, 75};
    sfIntRect ball = {0, 0, 64, 58};

    switch (who) {
        case 1 : return (mordecai);
        case 2 : return (rigsby);
        case 3 : return (socoupe);
        case 4 : return (mario);
        case 5 : return (witch);
        case 6 : return (sanji);
        case 7 : return (laser);
        case 8 : return (laser);
    }
}

int choose_offset(int who)
{
    int mordecai = 113;
    int rigsby = 95;
    int socoupe = 50;
    int mario = 97;
    int witch = 56;
    int sanji = 71;
    int laser = 49;
    int ball = 64;

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

int choose_max(int who)
{
    int mordecai = 339;
    int rigsby = 380;
    int socoupe = 200;
    int mario = 291;
    int witch = 448;
    int sanji = 568;
    int laser = 343;
    int ball = 512;

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
