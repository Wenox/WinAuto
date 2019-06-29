#ifndef SMOOTH_CURSOR_H_INCLUDED
#define SMOOTH_CURSOR_H_INCLUDED

/** Functions in this file are not used yet. Just declarations, waiting for their usage later on. */
/** Functions in this file are not used yet. Just declarations, waiting for their usage later on. */
/** Functions in this file are not used yet. Just declarations, waiting for their usage later on. */


void move_cursor(const int x1, const int y1, const int x2, const int y2, const int duration);

void direction_RD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);
void direction_RU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);
void direction_LD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);
void direction_LU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay);

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

/** to be improved, main function */
short smooth_cursor_fps(float x1, float y1, const short x2, const short y2, const short duration, const short fps);

int get_input(const int MIN, const int MAX);

void wrapper_get_input(int * const speed, int * const min_fps);

void exec_screen_saver(const int hotkey_id);

/** debugging/testing function, to be removed or to be fixed */
void screen_saver(int x2, int y2, const int screen_width, const int screen_height, const int speed, const int min_fps, const int hotkey_id);

#endif // SMOOTH_CURSOR_H_INCLUDED
