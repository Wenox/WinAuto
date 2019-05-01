#include <windows.h>
#include <stdbool.h>
#include <key_codes.h>

/** returns:
- true if key was pressed after previous call
- false otherwise */
bool check_key(int key_id)
{
    return (GetAsyncKeyState(key_id) & 0x0001) ? true : false;
}

/** returns value of last pressed key */
int last_pressed_key()
{
    if (check_key(KEY_A)) // A - highest priority
        return KEY_A;
    if (check_key(KEY_B)) // B - lower priority
        return KEY_B;

    return 0; // no key was pressed
}

/** auxiliary */
int last_pressed_key_extra()
{
    if (check_key(KEY_C)) // C
        return KEY_C;
    return 0;
}
