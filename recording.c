#include <stdbool.h>
#include <windows.h>
#include <structures.h>
#include <input_cursor.h>
#include <functions_queue.h>
#include <pressed_key.h>
#include <key_codes.h>

#define _GETCURSOR 1
#define _GETKEY 2
#define _SLEEP 3

/** adds cursor's position to the functions queue */
void add_cursor(struct f_queue **head, struct f_queue **tail, POINT P[2])
{
    P[1] = get_cursor();
    if (P[0].x != P[1].x || P[0].y != P[1].y) {               // if current cursor pos != previous
        add_function(head, tail, _GETCURSOR, P[1].x, P[1].y); // add it to the queue
        P[0] = P[1];
    }
}

/** adds latest keystroke's description to the functions queue */
void add_keystroke(struct f_queue **head, struct f_queue **tail, int key_buff[2])
{
    key_buff[1] = get_keystroke();
    if (key_buff[1] != key_buff[0] && key_buff[1] != 0)     // if there was keystroke
        add_function(head, tail, _GETKEY, key_buff[1], -1); // then add it to the queue
    key_buff[0] = key_buff[1];
}

/** returns true if newly added node is function of sleep type, false otherwise */
bool is_prev_sleep_func(struct f_queue **head)
{
    return (*head)->f_type == _SLEEP;
}

/** adds sleep to functions queue */
void add_sleep(struct f_queue **head, struct f_queue **tail, const int sleep_dur)
{
    Sleep(sleep_dur);
    if (!is_prev_sleep_func(head))
        add_function(head, tail, _SLEEP, sleep_dur, -1);
    else
        (*head)->f_args[0] += sleep_dur; // increment the node rather than add new one
}

/** keyboard/mouse recording engine */
void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur)
{
    int key_buff[2] = {-1, -1};               // buffer for curr and prev pressed key
    POINT cursor_buff[2] = {0};               // buffer for curr and prev cursor position

    while(key_buff[1] != KEY_W) {             // stop recording when '3' is pressed
        add_cursor(head, tail, cursor_buff);
        add_keystroke(head, tail, key_buff);
        add_sleep(head, tail, sleep_dur);
    }
}
