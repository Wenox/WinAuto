#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void draw_menu(const int error_id);

int get_choice();

bool str_ends_with(const char *source, const char *suffix);

int get_cycles_num();

void exec_play_recording(struct f_queue *head, struct f_queue *tail, const int cycles_num);

void init_menu(struct f_queue *head, struct f_queue *tail, const int error_id);

#endif // MENU_H_INCLUDED
