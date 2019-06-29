/** @file */

#ifndef RECORDING_H_INCLUDED
#define RECORDING_H_INCLUDED

#include <stdbool.h>

/** The function inserts current cursor's position as a description of a function call into the <b>f_queue</b>.
The new node is inserted at the front of <b>f_queue</b>.
@param head pointer to pointer to the first node
@param tail pointer to pointer to the last node
@param P[2] array of two <b>POINT</b> structures. The array contains current cursor's position <b>(x and y, in pixels)</b>. */
void add_cursor(struct f_queue **head, struct f_queue **tail, POINT P[2]);

/** The function inserts keystroke, if there was one, as a description of a function call into the <b>f_queue</b>.
The new node is inserted at the front of <b>f_queue</b>.
@param head pointer to pointer to the first node
@param tail pointer to pointer to the last node
@param key_buff[2] array of two integers. The array is a buffer for current and previous keystroke. */
void add_keystroke(struct f_queue **head, struct f_queue **tail, int key_buff[2]);

/** Function verifies if newly added node was describing sleep function.
@param head pointer to pointer to the first <b>f_queue</b> node
@return <b>true</b> if previous node was describing <b>Sleep</b> type of function.
In this case afterwards summation with previous node is performed, in order to safe space complexity.
@return <b>false</b> otherwise */
bool is_prev_sleep_func(struct f_queue ** head);

/** The function inserts fixed </b>10 miliseconds</b> duration as a description of a function call into the <b>f_queue</b>.
The new node is inserted at the front of <b>f_queue</b>.
If previous node was of sleep type as well, then rather than adding new node, they are <b>summed up together</b>.
@param head pointer to pointer to the first node
@param tail pointer to pointer to the last node
@param sleep_dur waiting interval between function calls, fixed to be 10 miliseconds */
void add_sleep(struct f_queue **head, struct f_queue **tail, const int sleep_dur);

/** <b>Keyboard/Mouse recording engine</b>. Ties up all recording functions together.
The function inserts new function descriptions as nodes into the doubly linked list-queue.
@warning Nodes are inserted in the following consecutive order: <b>cursor position -> keystroke -> waiting interval.</b>
@warning Nodes are inserted repeatedly until hotkey (turn-off switch) is pressed.
In such case recording breaks and the recording is saved into the .txt file.
@param head pointer to pointer to the front of the <b>f_queue</b>
@param tail pointer to pointer to the last node of the <b>f_queue</b>
@param sleep_dur constant fixed waiting interval in between recording consecutive cursor movements/keystrokes, fixed to be 10 miliseconds
@param hotkey_id turn-off key switch */
void record(struct f_queue **head, struct f_queue **tail, const int sleep_dur, const int hotkey_id);

#endif // RECORDING_H_INCLUDED
