/** @file */

#include <windows.h>
#include <stdbool.h>
#include <keys_pqueue.h>

bool check_key(const short key_id)
{
    return (GetAsyncKeyState(key_id) & 0x8000); ///< If the most significant bit was set, the key was being held
}

void clr_system_buffer(void)
{
    for (int i = 0; i < keys_pqueue_size; i++)
        GetAsyncKeyState(keys_pqueue[i]);
}

short get_keystroke(void)
{
    clr_system_buffer();
    for (int i = 0; i < keys_pqueue_size; i++)
        if (check_key(keys_pqueue[i]))
            return keys_pqueue[i];

    return 0; ///< If no key was pressed
}
