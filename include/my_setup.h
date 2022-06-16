/*
** EPITECH PROJECT, 2022
** my_setup
** File description:
** my_setup
*/

#ifndef my_setup_
    #define my_setup_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <unistd.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_power_rec(int nbr, int p);
long my_getnbr(char *str);

#endif /* !my_setup_ */
