#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

bool check_key(int key_id);

int last_pressed_key();

void empty_buffer();

int last_pressed_key_extra();

#endif // PRESSED_KEY_H_INCLUDED
