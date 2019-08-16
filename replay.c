/** @file */

#define WINVER 0x0500

#include <windows.h>
#include <f_queue.h>
#include <pressed_key.h>
#include <stdbool.h>

#define GET_CURSOR 1
#define GET_KEY 2
#define SLEEP 3

bool is_mouse_event(const int KEY_CODE)
{
    return KEY_CODE <= 2;
}

void send_mouse_input(const int KEY_CODE)
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;

    switch(KEY_CODE) {
        case 1:
                ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
                break;
        case 2:
                ip.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
                break;
        default:
                return;
    }

    SendInput(1, &ip, sizeof(INPUT));
}

void send_keyboard_input(const int KEY_CODE)
{
    INPUT ip = {0};
    ip.type = INPUT_KEYBOARD;

    ip.ki.wVk = KEY_CODE;
    SendInput(1, &ip, sizeof(INPUT));   // press

    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));   // release
}

void send_input(const int KEY_CODE)
{
    if (is_mouse_event(KEY_CODE))
        send_mouse_input(KEY_CODE);
    else
        send_keyboard_input(KEY_CODE);
}

void play_recording(struct f_queue *tail, const int hotkey_id)
{
    while (tail) {
        if (check_key(hotkey_id))
            return;

        if (tail->f_type == GET_CURSOR)
            SetCursorPos(tail->f_args[0], tail->f_args[1]);     ///< Simulates cursor's position
        else if (tail->f_type == GET_KEY)
            send_input(tail->f_args[0]);                        ///< Simulates keystroke
        else if (tail->f_type == SLEEP)
            Sleep(tail->f_args[0]);                             ///< Simulates waiting interval in between keystrokes and/or cursor's movements

        tail = tail->prev;
    }
}
