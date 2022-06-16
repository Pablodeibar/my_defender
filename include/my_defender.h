/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#ifndef my_defender_
    #define my_defender_
    #include "struct.h"
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

int menu(scene_t scene, sprite_t sprite, int nbr);
void init_objs(scene_t *scene, char *filepath, sfVector2f size);
void init_button(scene_t *scene, sfVector2f pos, sfVector2f size);
int close_win(sfRenderWindow *window, sprite_t *sprite);
void draw_menu(sprite_t *sprite, scene_t *scene);
void destroy(sprite_t *sprite, scene_t *scene);
int close_menu(sfRenderWindow *window, sprite_t *sprite, scene_t *scene);
int game(void);
void change_color_of_button2(scene_t *scene, sprite_t *sprite);
void initi_sprit(struct sprite_s *sprite, scene_t *scene);
void music(sprite_t *sprite);
void sound_start(sprite_t *sprite);
void draw(sprite_t *sprite, scene_t *scene, Liste_t *list);
void clock(sfClock *clocks, sprite_t *sprite, Liste_t *list);
int menu_2(scene_t scene, sprite_t sprite);
int back_menu(sfRenderWindow *window, sprite_t *sprite, scene_t *scene);
int count_coin(sfClock *clock, scene_t *scene, sprite_t *sprite, int coins);
void ini_pause(scene_t *scene);
int detect_pause(scene_t *scene, sprite_t *sprite, int need, Liste_t *list);
int close_game(sprite_t *sprite, scene_t *scene, Liste_t *list);
void ini_shop(scene_t *scene, sprite_t *sprite);
void sound_buy(sprite_t *sprite);
void add_head(Liste_t *liste, sprite_t *sprite);
Liste_t *ini(void);
int link_test(void);
void clock_link(sfClock *clo, sfIntRect *rect);
int add_end_test(Liste_t *list, int who);
int move_link(sfIntRect *rect, element_t *actuel);
void ennemi_link(Liste_t *list, sfClock *clo, sprite_t *sprite);
void take_time(sfClock *clock, sprite_t *sprite);
void sound_not_enough(sprite_t *sprite);
char *choose_perso(int who);
sfVector2f choose_pos(int who);
sfIntRect choose_rect(int who);
void draw_pause_menu(sprite_t *sprite);
sfRectangleShape **create_button(sfRectangleShape **button, sfColor sfGray);
sfText **text_button(sfText **text);
int events(sprite_t *sprite, scene_t *scene, Liste_t *list);
void choose_draw(sprite_t *sprite, scene_t *scene, Liste_t *list);
int main(int ac, char **av);
int choose_offset(int who);
int choose_max(int who);
sfIntRect choose_new_rect(int who);
int choose_top(int who);
int choose_maxtop(int who);
void destroy_game(sprite_t *sprite, Liste_t *list, scene_t *scene);
void init_life(scene_t *scene, sprite_t *sprite, sfClock *clock);
void verif_life(Liste_t *list, sprite_t *sprite);
int collision(Liste_t *list, sprite_t *sprite);
int choose_start_top(int who);
int choose_life_pnj(int who);
void draw_2_con(Liste_t *list, sprite_t *sprite, element_t *actuel);
sfVector2f choose_move(int who);
int choose_damage(int who);
void ini_shop_3(scene_t *scene, sprite_t *sprite);
int detect_shop_3(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins);
int detect_shop_4(scene_t *scene, sprite_t *sprite, Liste_t *list, int coins);
int sup_el(Liste_t *list, int emplacement);
int init_coins(scene_t *scene);
void verif_pos(element_t *temp, Liste_t *list, int i);

#endif /* !my_defender_ */
