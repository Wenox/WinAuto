#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

bool check_key(const short key_id);

void clr_system_buffer(void);

short last_pressed(void);

void __test_keypresses(const int how_many);

#endif // PRESSED_KEY_H_INCLUDED
