/** @file */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** The function outputs relevant text data to the user. The function helps the user navigate around the program.
@param flag_id menu flag to determine expected printf result based on earlier behaviour */
void draw_menu(const int flag_id);

/** The function prompts user to select menu choice to futher navigate around the program. Basic input validation is performed. */
int get_menu_choice(void);

/** The function saves user-inputted keystroke as a hotkey used in <b>2nd, 3rd and 4th</b> menu functions.
@warning User needs to remember his hotkey.
@warning For user's convenience, several hotkeys that would propably not me sense were blacklisted, including the default hotkey. */
int get_hotkey(void);

/** The function verifies if string (array of chars) ends with given suffix (other array of chars).
Used to validate if the file inputted by the user surely ends with .txt postfix.
@param source pointer to source array
@param suffix pointer to desired ending suffix of soruce array
@return <b>true</b> if source ends with suffix
@return <b>false</b> otherwise
@warning The function comes from stackoverflow.com */
bool str_ends_with(const char *source, const char *suffix);

/** The function prompts user to input how many cycles of recording he wishes to playback.
The input number has to be an integer greater or equal than 1, and if the input is greater than 5, then it is assumed the playback is infinitely loop.
<b>In such case the f_queue doubly linked list-queue attains cyclic properties.</b>
@return cycles_num the desired number of cycles */
int get_cycles_num(void);

/** The function executes the process of simulation of playing the recording.
In case if cycles number is greater than 5, the playback loop is infinite.
The playback loop ends at the end of all cycles, or <b>can be broken by pressing the set (or default if not set) hotkey</b>.
@param head pointer to the front of the <b>f_queue</b> list-queue
@param tail pointer to the last node of the <b>f_queue</b> list-queue
@param cycles_num the number of playback cycles
@param hotkey_id the turn-off playback key switch */
void exec_play_recording(struct f_queue *head, struct f_queue *tail, const int cycles_num, const int hotkey_id);

/** The function executes entire recording process when user chose <b>2</b>.
Recording is stopped when <b>hotkey</b> is pressed and saved into the inputted .txt file.
Hence it can be re-used afterwards for playback purposes.
The function <b>recurseively</b> goes back to the menu with appropriate <b>menu_flags</b>: SAVED_FILE or ERROR_NO_TXT_SUFFIX,
depending on the earlier behaviour.
@param head pointer to the front node of the <b>f_queue</b> linked list
@param tail pointer to the last node of the <b>f_queue</b< linked list
@param hotkey_id */
void chosen_recording(struct f_queue *head, struct f_queue *tail, const int hotkey_id);

/** Recursive function that loops the menu and loops the execution of the program.
The user chooses if he wants to set new hotkey, create new recording, playback old recording, start screensaver or end the program.
@param head pointer to the front node of <b>f_queue</b> doubly-linked list
@param tail pointer to the last node of <b>f_queue</b> doubly-linked list
@param flag_id the menu flag, depending on the value different output is displayed to the user
@param hotkey_id the turn-off switch for the program (default <b>F5</b>) */
void init_menu(struct f_queue *head, struct f_queue *tail, const int flag_id, const int hotkey_id);

#endif // MENU_H_INCLUDED
