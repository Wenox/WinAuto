/** @file */

#ifndef REPLAY_H_INCLUDED
#define REPLAY_H_INCLUDED

bool is_mouse_event(const int KEY_CODE);

void send_mouse_input(const int KEY_CODE);

void send_keyboard_input(const int KEY_CODE);

/** Function sends keyboard or mouse input event during the recording playback phase. The event is chosen on retrieved <b>KEY_CODE</b>.
The key codes of <b>2 or less</b> correspond to mouse event. Other key codes correspond to keyboard event.
The events are performed at an instant of time.
@param KEY_CODE */
void send_input(const int KEY_CODE);

/** <b>The recording replay (playback) simulation engine</b>.
The function simulates the recording saved in .txt file.
The playback's precision is almost accurate. The variation between playback and recording's duration is less than <b>5%</b> and usually below <b>1%</b>.
The variation is dependant on recording's keystrokes/mouse movements intensity, and user's CPU speed.
Starting from the tail iterates through entire <b>f_queue</b> doubly linked list-queue.
Executes functions corresponding to the given <b>f_type</b>.
The cursor's position is set when <b>f_type</b> describes cursor (f_type is 1).
The cursor's keystroke is simulated when <b>f_type</b> describes keystroke event (f_type is 2).
The sleep function (waiting interval for next cursor's movement or keystroke) is performed when <b>f_type</b> describes Sleep function (f_type is 3).
@param tail pointer to the last node of <b>f_queue</b> doubly linked list-queue. The playback starts from the tail.
@param hotkey_id turn-off playback key switch */
void play_recording(struct f_queue *tail, const int hotkey_id);

#endif // REPLAY_H_INCLUDED
