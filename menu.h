#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void draw_menu(const int flag_id);

int get_menu_choice(void);

int get_hotkey(void);

bool str_ends_with(const char *source, const char *suffix);

int get_cycles_num(void);

void exec_play_recording(struct f_queue *head, struct f_queue *tail, const int cycles_num, const int hotkey_id);

void chosen_recording(struct f_queue *head, struct f_queue *tail, const int hotkey_id);

void chosen_recording(struct f_queue *head, struct f_queue *tail, const int hotkey_id);

void init_menu(struct f_queue *head, struct f_queue *tail, const int flag_id, const int hotkey_id);

#endif // MENU_H_INCLUDED
