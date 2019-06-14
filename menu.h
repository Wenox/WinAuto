#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void draw_menu();

int get_choice();

bool str_ends_with(const char *source, const char *suffix);

int get_cycles_num();

void init_menu(struct f_queue *head, struct f_queue *tail);

#endif // MENU_H_INCLUDED
