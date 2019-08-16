/** @file */

#include <stdbool.h>
#include <windows.h>
#include <f_queue.h>
#include <input_cursor.h>
#include <functions_queue.h>
#include <pressed_key.h>
#include <key_codes.h>
#include <stdio.h>

#define GET_CURSOR 1
#define GET_KEY 2
#define SLEEP 3

void add_cursor(struct f_queue **head, struct f_queue **tail, POINT P[2])
{
    P[1] = get_cursor();

    if (P[0].x != P[1].x || P[0].y != P[1].y) {               ///< if current cursor pos != previous
        add_function(head, tail, GET_CURSOR, P[1].x, P[1].y); ///< add it to the queue
        P[0] = P[1];
    }
}

void add_keystroke(struct f_queue **head, struct f_queue **tail, int key_buff[2])
{
    key_buff[1] = get_keystroke();

    if (key_buff[1] != key_buff[0] && key_buff[1] != 0)     ///< if there was keystroke
        add_function(head, tail, GET_KEY, key_buff[1], -1); ///< add it to the queue

    key_buff[0] = key_buff[1];
}

bool is_prev_sleep_func(struct f_queue **head)
{
    return (*head)->f_type == SLEEP;
}

void add_sleep(struct f_queue **head, struct f_queue **tail, const int sleep_dur)
{
    Sleep(sleep_dur);

    if (!is_prev_sleep_func(head))
        add_function(head, tail, SLEEP, sleep_dur, -1);
    else
        (*head)->f_args[0] += sleep_dur; ///< increment the previous node, rather than add new one
}

void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur, const int hotkey_id)
{
    int key_buff[2] = {-1, -1};                     ///< buffer for curr and prev pressed key
    POINT cursor_buff[2] = {{-1, -1}, {-1, -1}};    ///< buffer for curr and prev cursor position

    printf("RECORDING...\n[press your hotkey to stop]\n");
    while(key_buff[1] != hotkey_id) {             ///< stop recording when 'hotkey' is pressed
        add_cursor(head, tail, cursor_buff);
        add_keystroke(head, tail, key_buff);
        add_sleep(head, tail, sleep_dur);
    }
}
