#include <windows.h>
#include <time.h>

/** not used */
void move_cursor(const int x1, const int y1, const int x2, const int y2, const int duration)
{
    SetCursorPos(x1, y1);
    Sleep(duration);
    SetCursorPos(x2, y2);
}

void direction_RD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay)
{
    (*x1) += x_jump;
    (*y1) += y_jump;
    Sleep(sleep_delay);
    SetCursorPos(*x1, *y1);
}

void direction_RU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay)
{
    (*x1) += x_jump;
    (*y1) -= y_jump;
    Sleep(sleep_delay);
    SetCursorPos(*x1, *y1);
}

void direction_LD(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay)
{
    (*x1) -= x_jump;
    (*y1) += y_jump;
    Sleep(sleep_delay);
    SetCursorPos(*x1, *y1);
}

void direction_LU(float *x1, float *y1, float x_jump, float y_jump, float sleep_delay)
{
    (*x1) -= x_jump;
    (*y1) -= y_jump;
    Sleep(sleep_delay);
    SetCursorPos(*x1, *y1);
}

void smooth_transition(void(*direction)(float *, float *, const float, const float, const float),
                       float *x1,
                       float *y1,
                       const float x_jump,
                       const float y_jump,
                       const float sleep_delay,
                       short num_of_jumps,
                       const short x2,
                       const short y2,
                       const short duration)
{
    SetCursorPos(x1, y1);
    clock_t move_duration = clock();
    while (num_of_jumps > 0) {
        direction(x1, y1, x_jump, y_jump, sleep_delay);
        num_of_jumps--;
    }
    SetCursorPos(x2, y2); // rarely final position's fix is needed, in case if cursor is off by 1 pixel
    float remaining_time = duration - (clock() - move_duration);
    if (remaining_time > 0)
        Sleep(remaining_time); // transition is not 100% accurate in time (usually +- 5%), so if transition took less than expected, wait
}

short smooth_cursor_fps(float x1, float y1, const short x2, const short y2, const short duration, const short fps)
{
    const float sleep_delay = 1000.0 / fps;
    const short dx = abs(x2 - x1);
    const short dy = abs(y2 - y1);
    short num_of_jumps = (short) duration / sleep_delay;
    const float x_jump = (float) dx / num_of_jumps;
    const float y_jump = (float) dy / num_of_jumps;

    if (x1 <= x2 && y1 <= y2)
        smooth_transition(direction_RD, &x1, &y1, x_jump, y_jump, sleep_delay, num_of_jumps, x2, y2, duration);
    else if (x1 <= x2 && y1 >= y2)
        smooth_transition(direction_RU, &x1, &y1, x_jump, y_jump, sleep_delay, num_of_jumps, x2, y2, duration);
    else if (x1 >= x2 && y1 <= y2)
        smooth_transition(direction_LD, &x1, &y1, x_jump, y_jump, sleep_delay, num_of_jumps, x2, y2, duration);
    else if (x1 >= x2 && y1 >= y2)
        smooth_transition(direction_LU, &x1, &y1, x_jump, y_jump, sleep_delay, num_of_jumps, x2, y2, duration);
}

/** debugging/testing */
void getcursor_movecursor()
{
    POINT p[300] = {};

    Sleep(1000);
    for (int i = 0; i < 300; i++) {
        GetCursorPos(&p[i]);
        printf("x: %d, y: %d\n", p[i].x, p[i].y);
        Sleep(10);
    }
    printf("Stopped recording.\n");
    Sleep(2000);
    system("cls");
    printf("100 FPS replay\n");
    for (int i = 0; i < 300; i++) {
    SetCursorPos(p[i].x, p[i].y);
    Sleep(10);
    }
    Sleep(2000);
    printf("slow-mo 10 FPS replay");
    for (int i = 0; i < 300; i++) {
    SetCursorPos(p[i].x, p[i].y);
    Sleep(100);
    }
}

/** debugging/testing */
void __random_smooth_move(int x2, int y2)
{
    int previous_x2 = x2;
    int previous_y2 = y2;
    x2 = rand() % 1920;
    y2 = rand() % 1080;
    int duration = rand() % 1000 + 20;
    int fps = rand () % 100;
    system("cls");
    printf("fps: %d", fps);
    smooth_cursor_fps(previous_x2, previous_y2, x2, y2, duration, fps);
    __random_smooth_move(x2, y2);
}
