#ifndef RECORDING_H_INCLUDED
#define RECORDING_H_INCLUDED

/** adds latest keystroke's description to the functions queue */
void add_cursor(struct f_queue **head, struct f_queue **tail, POINT P[2]);

/** adds latest keystroke's description to the functions queue */
void add_keystroke(struct f_queue **head, struct f_queue **tail, int key_buff[2]);

/** returns true if newly added node is sleep function type, false otherwise */
bool is_prev_sleep_func(struct f_queue **head);

/** adds sleep to functions queue */
void add_sleep(struct f_queue **head, struct f_queue **tail, const int sleep_dur);

/** keyboard/mouse recording engine */
void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur);

#endif // RECORDING_H_INCLUDED
