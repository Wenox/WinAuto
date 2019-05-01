#include <windows.h>
#include <input_cursor.h>
#include <pressed_key.h>
#include <functions_queue.h>

#define _GETKEY 1
#define _SLEEP 2
#define _GETCURSOR 3

void record(struct f_queue *head, struct f_queue *tail, int sleep_dur)
{
    int k = 100;
    while(k > 0) {
        printf("iter %d\n", k);
        add_function(head, tail, _GETKEY, last_pressed(), 0);
        Sleep(sleep_dur);
        add_function(head, tail, _SLEEP, sleep_dur, 0);
        POINT P = get_cursor();
        add_function(head, tail, _GETCURSOR, P.x, P.y);
        k--;
    }
}
