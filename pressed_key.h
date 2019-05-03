#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

/** returns true if key was pressed at the time of function call, false otherwise */
bool check_key(const short key_id);

/** function clears GetAsyncKeyState's 'system' buffer */
void clr_system_buffer(void);

/** returns value of currently pressed key with highest priority */
short get_keystroke(void);

/** used for testing */
void __test_keypresses(const int how_many);

#endif // PRESSED_KEY_H_INCLUDED
