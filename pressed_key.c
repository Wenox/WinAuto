#include <windows.h>
#include <stdbool.h>
#include <key_codes.h>
#include <keys_pqueue.h>

/** returns:
- true if key was pressed after previous call (least significant bit is set)
- false otherwise */
bool check_key(int key_id)
{
    //short state = GetAsyncKeyState(key_id);
    //if (state == 1)
    //    return true;
   // elsea
     //   return false;

    return (GetAsyncKeyState(key_id) & 0x8001) ? true : false;
}

/** returns value of last pressed key */
int last_pressed()
{
    for (int i = 0; i < keys_pqueue_size; i++) {
        clr_system_buffer();
        if (check_key(keys_pqueue[i])) { /// && *last_pressed_key != keys_pqueue[i]) {
            return keys_pqueue[i];
        }
    }
    return 0; // no key was pressed
}

void clr_system_buffer()
{
    for (int i = 0; i < keys_pqueue_size; i++)
        GetAsyncKeyState(keys_pqueue[i]);
}

void test_keypresses(int how_many)
{
    Sleep(3000);
    printf("testing keypresses:\n");
    for (int i = 0; i < how_many; i++) {
        printf("%d\n", last_pressed());
        Sleep(15);
    }
}
