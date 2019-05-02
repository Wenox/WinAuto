#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <structures.h>
#include <input_cursor.h>
#include <pressed_key.h>
#include <functions_queue.h>
#include <key_codes.h>

#define _GETKEY 1
#define _SLEEP 2
#define _GETCURSOR 3

/** returns true if latest added node is sleep function type, false otherwise */
bool is_prev_sleep_func(struct f_queue **head)
{
    return (*head)->f_type == _SLEEP ? true : false;
}

/** keyboard/mouse recording engine */
void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur)
{
    int key_buff[2] = {-1, -1};     // buffer for curr and prev pressed key
    POINT P[2] = {};                // buffer for curr and prev cursor position
    while(key_buff[1] != KEY_3) {   // stop recording when '3' is pressed
        /** add keypress to queue */
        key_buff[1] = last_pressed();
        if (key_buff[1] != key_buff[0])
            add_function(head, tail, _GETKEY, key_buff[1], -1);
        key_buff[0] = key_buff[1];

        /** add sleep to queue */
        Sleep(sleep_dur);
        if (!is_prev_sleep_func(head))
            add_function(head, tail, _SLEEP, sleep_dur, -1);
        else
            (*head)->f_args[0] += sleep_dur;

        /** add cursor to queue */
        P[1] = get_cursor();
        if (P[0].x != P[1].x && P[0].y != P[1].y) // if current cursor pos != previous
            add_function(head, tail, _GETCURSOR, P[1].x, P[1].y);
        P[0] = P[1];
    }
}
