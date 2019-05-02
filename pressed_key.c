#include <windows.h>
#include <stdbool.h>
#include <key_codes.h>
#include <keys_pqueue.h>

/** returns:
- true if key was pressed after previous call (least significant bit is set)
- false otherwise */
bool check_key(const short key_id)
{
    return (GetAsyncKeyState(key_id) & 0x8000) ? true : false;
}

void clr_system_buffer(void)
{
    for (int i = 0; i < keys_pqueue_size; i++)
        GetAsyncKeyState(keys_pqueue[i]);
}

/** returns value of last pressed key */
short last_pressed(void)
{
    for (int i = 0; i < keys_pqueue_size; i++) {
        clr_system_buffer();
        if (check_key(keys_pqueue[i])) { /// && *last_pressed_key != keys_pqueue[i]) {
            return keys_pqueue[i];
        }
    }
    return 0; // no key was pressed
}

#include <stdio.h>
void __test_keypresses(const int how_many)
{
    printf("testing keypresses:\n");
    for (int i = 0; i < how_many; i++) {
        printf("%d\n", last_pressed());
        Sleep(20);
    }
}
