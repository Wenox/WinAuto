#define WINVER 0x0500
#include <windows.h>
#include <structures.h>

#define _GETCURSOR 1
#define _GETKEY 2
#define _SLEEP 3

/** function sends keyboard or mouse input, based on KEY_CODE */
void send_input(const int KEY_CODE)
{
    if (KEY_CODE <= 2) { /** mouse event */
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
        return;
    }
    else { /** keyboard event */
        INPUT ip = {0};
        ip.type = INPUT_KEYBOARD;

        ip.ki.wVk = KEY_CODE;
        SendInput(1, &ip, sizeof(INPUT));

        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        return;
    }
}

/** function replays the recording */
void play_recording(struct f_queue *tail)
{
    while (tail) {
        if (tail->f_type == _GETCURSOR)
            SetCursorPos(tail->f_args[0], tail->f_args[1]);
        else if (tail->f_type == _GETKEY)
            send_input(tail->f_args[0]);
        else if (tail->f_type == _SLEEP)
            Sleep(tail->f_args[0]);

        tail = tail->prev;
    }
}
