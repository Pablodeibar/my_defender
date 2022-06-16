/*
** EPITECH PROJECT, 2022
** music
** File description:
** music
*/

#include "my_defender.h"

void music(sprite_t *sprite)
{
    sfMusic_play(sprite->music_back);
    sfMusic_setLoop(sprite->music_back, sfTrue);
    sfMusic_setVolume(sprite->music_back, 40);
}

void sound_start(sprite_t *sprite)
{
    char *button = "assets/music_sounds/sound_button.ogg";
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(button);
    sfSound *test;
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    sprite->start = sfSound_create();
    sfSound_setBuffer(sprite->start, buff);
    sfSound_setVolume(sprite->start, 100);
    sfSound_play(sprite->start);
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 100000.0;
        if (seconds > 3.85) {
            break;
        }
    }
}

void sound_buy(sprite_t *sprite)
{
    char *coin = "assets/music_sounds/coin.ogg";
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(coin);

    sprite->buy = sfSound_create();
    sfSound_setBuffer(sprite->buy, buff);
    sfSound_setVolume(sprite->buy, 100);
    sfSound_play(sprite->buy);
}

void sound_not_enough(sprite_t *sprite)
{
    char *not_enough = "assets/music_sounds/not_enough.ogg";
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(not_enough);

    sprite->not_enought = sfSound_create();
    sfSound_setBuffer(sprite->not_enought, buff);
    sfSound_setVolume(sprite->not_enought, 100);
    sfSound_play(sprite->not_enought);
}
