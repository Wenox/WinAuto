#ifndef REPLAY_H_INCLUDED
#define REPLAY_H_INCLUDED

void send_input(const int KEY_CODE);

void set_cursor(const int x, const int y);

void set_sleep(const int duration);

void play_recording(struct f_queue *tail);

#endif // REPLAY_H_INCLUDED
