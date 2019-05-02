#ifndef RECORDING_H_INCLUDED
#define RECORDING_H_INCLUDED

/** returns true if latest added node is sleep function type, false otherwise */
bool is_prev_sleep_func(struct f_queue **head);

/** keyboard/mouse recording engine */
void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur);

#endif // RECORDING_H_INCLUDED
