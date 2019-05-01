#include <windows.h>
#include <stdbool.h>
#include <key_codes.h>

/** returns:
- true if key was pressed after previous call (least significant bit is set)
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

    /* to be replaced with keys_pqueue */
}

void empty_buffer()
{
    GetAsyncKeyState(KEY_A);
    GetAsyncKeyState(KEY_B);
    GetAsyncKeyState(KEY_C);

    /* final idea:
     *
     * short keys_pqueue[num_of_keys] = { KEY_SPACE, KEY_BACK, KEY_RETURN, KEY_SHIFT, KEY_A,
     *                                    KEY_E, KEY_O, ... , KEY_INS, KEY_PGUP, KEY_PGDN };
     *
     * keys_pqueue is a priority pseudo-queue,
     * with the most likely most often pressed key being the first element,
     * and the least likely least pressed key being the last element,
     * based on the data tracked by WhatPulse app
     *
     * for (int i = 0; i < keys_pqueue.size() - 1; i++)
     *     GetAsyncKeyState(i);
     *
     */
}

/** auxiliary */
int last_pressed_key_extra()
{
    if (check_key(KEY_C)) // C
        return KEY_C;
    return 0;
}
