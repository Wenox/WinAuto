#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

bool check_key(int key_id);

/** returns value of last pressed key */
int last_pressed_key();

int last_pressed_key_extra();


#endif // PRESSED_KEY_H_INCLUDED
