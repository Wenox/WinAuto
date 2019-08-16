/** @file */

#ifndef SMOOTH_CURSOR_H_INCLUDED
#define SMOOTH_CURSOR_H_INCLUDED

/** This neat function is currently not in use, however might be used in the future. */
void move_cursor(const int x1, const int y1, const int x2, const int y2, const int duration);

/** Translates current cursor position along <b>Right-Down (RD)</b> directional vector. Sets the cursor position into the computed position.
@param x1 pointer to <b>x</b> coordinate
@param y1 pointer to <b>y</b> coordinate
@param x_jump jump to be added to <b>x1</b> coordinate
@param y_jump jump to be added to <b>y1</b> coordinate
@param sleep_delay sleep delay in between consecutive cursor jumps (float is intended) */
void direction_RD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);

/** Translates current cursor position along <b>Right-Up (RU)</b> directional vector. Sets the cursor position into the computed position.
@param x1 pointer to <b>x</b> coordinate
@param y1 pointer to <b>y</b> coordinate
@param x_jump jump to be added to <b>x1</b> coordinate
@param y_jump jump to be removed from <b>y1</b> coordinate
@param sleep_delay sleep delay in between consecutive cursor jumps (float is intended) */
void direction_RU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);

/** Translates current cursor position along <b>Left-Down (LD)</b> directional vector. Sets the cursor position into the computed position.
@param x1 pointer to <b>x</b> coordinate
@param y1 pointer to <b>y</b> coordinate
@param x_jump jump to be removed from <b>x1</b> coordinate
@param y_jump jump to be added to <b>y1</b> coordinate
@param sleep_delay sleep delay in between consecutive cursor jumps (float is intended) */
void direction_LD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);

/** Translates current cursor position along <b>Left-Up (LU)</b> directional vector. Sets the cursor position into the computed position.
@param x1 pointer to <b>x</b> coordinate
@param y1 pointer to <b>y</b> coordinate
@param x_jump jump to be removed to <b>x1</b> coordinate
@param y_jump jump to be removed from <b>y1</b> coordinate
@param sleep_delay sleep delay in between consecutive cursor jumps (float is intended) */
void direction_LU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);

/** The function accurately moves the cursor from initial to final position in a smooth fashion.
@param direction pointer to function returing void (the function takes directional vector as a parameters)
@param x1 pointer to x1 coordinate
@param x2 pointer to y1 coordinate
@param x_jump the jump of cursor along x axis, jump between two consecutive cursor moves
@param y_jump the jump of cursor along y axis, jump between two consecutive cursor moves
@param sleep_delay waiting duration in between cursor jumps
@param num_of_jumps total number of jumps the cursor does during the entire cursor transition
@param x2 final x position
@param y2 final y position
@param duration duration of the entire smooth cursor translation process */
void smooth_transition(void(*direction)(float *, float *, const float, const float, const float),
                       float *x1,
                       float *y1,
                       const float x_jump,
                       const float y_jump,
                       const float sleep_delay,
                       short num_of_jumps,
                       const short x2,
                       const short y2,
                       const short duration);

/** The function computes data for accurate smooth cursor translation and then sends it to the main cursor transition function.
@param x1 initial cursor's position on x (float is intended)
@param y1 intitial cursor's position on y axis (float is intended)
@param x2 final cursor's x position
@param y2 final cursor's y position
@param duration duration of the transition
@param fps FPS of the translation. <b>Custom feature that imitates smooth, less smooth or lagging cursor depending on the value.</b> */
void exec_smooth_cursor(float x1, float y1, const short x2, const short y2, const short duration, const short fps);

/** Wrapper function for <b>scanf</b> further usage. The input request occurs in a loop until proper data value is entered by the user.
@param MIN defines lower bound of the correct data set
@param MAX defines upper bound of the correct data set */
int get_input(const int MIN, const int MAX);

/** Wrapper function for get_input. The function prompts user to enter speed of the cursor and minimal value of FPS for the <b>screensaver</b> animation.
@param speed speed of the cursor, values from 1 to 10
@param min_fps minimal fps of the screensaving animation's cursor's movement. Values from 1 to 99. */
void wrapper_get_input(int * const speed, int * const min_fps);

/** The function prepares <b>screensaving</b> cursor animation for execution. The function checks the user's monitor resolution and matches it accordingly.
@param hotkey_id toggle off key */
void exec_screen_saver(const int hotkey_id);

/** The function performs looped <b>screensaving</b> cursor animation. The animation is broken when <b>hotkey is HELD</b>.
The animation can have various speeds and various smoothness (FPS) feelings, depending on user's entered values in <b>wrapper_get_input</b> function.
@warning This is a recursive function and its stop condition is pressing the hotkey.
@param x2 previous x cursor's position
@param y2 previous y cursor's position
@param screen_width
@param screen_height
@param speed speed of the cursor
@param min_fps minimal FPS of the animation
@param hotkey_id the toggle-off hotkey's ID */
void screen_saver(int x2, int y2, const int screen_width, const int screen_height, const int speed, const int min_fps, const int hotkey_id);

#endif // SMOOTH_CURSOR_H_INCLUDED
