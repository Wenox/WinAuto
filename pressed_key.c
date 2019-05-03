#include <windows.h>
#include <stdbool.h>
#include <keys_pqueue.h>

/** returns true if key was pressed at the time of function call, false otherwise */
bool check_key(const short key_id)
{
    return (GetAsyncKeyState(key_id) & 0x8000);
}

/** function clears GetAsyncKeyState's 'system' buffer */
void clr_system_buffer(void)
{
    for (int i = 0; i < keys_pqueue_size; i++)
        GetAsyncKeyState(keys_pqueue[i]);
}

/** returns value of currently pressed key with highest priority */
short get_keystroke(void)
{
    clr_system_buffer();
    for (int i = 0; i < keys_pqueue_size; i++) {
        if (check_key(keys_pqueue[i])) {
            return keys_pqueue[i];
        }
    }
    return 0; // no key was pressed
}

/** used for testing */
#include <stdio.h>
void __test_keypresses(const int how_many)
{
    printf("testing keypresses:\n");
    for (int i = 0; i < how_many; i++) {
        printf("%d\n", get_keystroke());
        Sleep(20);
    }
}
