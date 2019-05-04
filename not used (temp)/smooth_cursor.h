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

/** debugging/testing */
void getcursor_movecursor();

/** debugging/testing function, to be removed or to be fixed */
void __random_smooth_move(int x2, int y2);

#endif // SMOOTH_CURSOR_H_INCLUDED
