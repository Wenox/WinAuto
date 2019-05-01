#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

bool check_key(int key_id);

int last_pressed();

void clr_system_buffer();

void test_keypresses();

#endif // PRESSED_KEY_H_INCLUDED
