#include <stdio.h>
#include <windows.h>
#include <structures.h>
#include <input_cursor.h>
#include <pressed_key.h>
#include <functions_queue.h>
#include <key_codes.h>
#define _GETKEY 1
#define _SLEEP 2
#define _GETCURSOR 3

void record(struct f_queue *head, struct f_queue *tail, const int sleep_dur)
{
    int k = 0; // irrelevant
    int key_buff[2] = {-1, -1}; // buffer for curr and prev pressed key
    POINT P[2] = {}; // buffer for curr and prev cursor position
    while(key_buff[1] != KEY_3) { // stop recording when '3' is pressed
        printf("iter %d\n", ++k);

        /** add SendInput to queue */
        key_buff[1] = last_pressed();
        if (key_buff[1] != key_buff[0])
            add_function(head, tail, _GETKEY, key_buff[1], -1);
        key_buff[0] = key_buff[1];

        /** add Sleep to queue */
        Sleep(sleep_dur);
        //add_function(head, tail, _SLEEP, sleep_dur, -1);

        /** add SetCursorPos to queue */
        P[1] = get_cursor();
        if (P[0].x != P[1].x && P[0].y != P[1].y) // if current cursor pos != previous
            add_function(head, tail, _GETCURSOR, P[1].x, P[1].y);
        P[0] = P[1];
    }
}
