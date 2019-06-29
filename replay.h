#ifndef REPLAY_H_INCLUDED
#define REPLAY_H_INCLUDED

/** function sends keyboard or mouse input, based on KEY_CODE */
void send_input(const int KEY_CODE);

/** function replays the recording */
void play_recording(struct f_queue *tail, const int hotkey_id);

#endif // REPLAY_H_INCLUDED
