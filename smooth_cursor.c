#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <pressed_key.h>
#include <smooth_cursor.h>

/** Functions in this file are not used yet. Just definitions, waiting for their usage later on. */
/** Functions in this file are not used yet. Just definitions, waiting for their usage later on. */
/** Functions in this file are not used yet. Just definitions, waiting for their usage later on. */


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
    SetCursorPos((int) x1, (int) y1);
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
    return -1;
}

int get_input(const int MIN, const int MAX)
{
    int input = 0;

    while (input < MIN || input > MAX)
        if (1 != scanf("%d", &input))
            fseek(stdin, 0, SEEK_END);

    return input;
}

void wrapper_get_input(int * const speed, int * const min_fps)
{
    printf("Choose speed of cursor [1 - slowest, 10 - fastest]:\n");
    *speed = 11 - get_input(1, 10);

    printf("Choose minimal FPS of cursor [1 to 99, recommended 60]\n");
    *min_fps = get_input(1, 99);
}

void exec_screen_saver(const int hotkey_id)
{
    const int gScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int gScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    int speed = 0, min_fps = 0;

    wrapper_get_input(&speed, &min_fps);

    printf("%d %d", speed, min_fps);

    screen_saver(0, 0, gScreenWidth, gScreenHeight, speed, min_fps, hotkey_id);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

/** debugging/testing */
void screen_saver(int x2, int y2, const int screen_width, const int screen_height, const int speed, const int min_fps, const int hotkey_id)
{
    if (check_key(hotkey_id)) /// stop condition: screensaver ends when hotkey is HELD
        return;

    int previous_x2 = x2;
    int previous_y2 = y2;
    x2 = rand() % screen_width;
    y2 = rand() % screen_height;
    int duration = rand() % (200 * speed) + 100;
    int fps = rand () % (101 - min_fps) + min_fps;

    system("cls");
    printf("HOLD hotkey to stop\n");
    printf("fps: %d", fps);

    smooth_cursor_fps(previous_x2, previous_y2, x2, y2, duration, fps);
    screen_saver(x2, y2, screen_width, screen_height, speed, min_fps, hotkey_id);
}
