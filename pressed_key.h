/** @file */

#ifndef PRESSED_KEY_H_INCLUDED
#define PRESSED_KEY_H_INCLUDED

#include <stdbool.h>

/** Function checks if given key was being pressed (held) at the exact time of function call.
@return <b>true</b> if the key was being held
@return <b>false</b> otherwise */
bool check_key(const short key_id);

/** @warning Function clears GetAsyncKeyState's <b>'system'</b> buffer. Needed due to <b>GetAsyncKeyState</b> nature. */
void clr_system_buffer(void);

/** Returns integer value of key that was being pressed at the time of function call.
@warning If two or more keys were pressed simultaneously, the key with the highest priority is returned. */
short get_keystroke(void);

#endif // PRESSED_KEY_H_INCLUDED
