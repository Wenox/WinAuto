#define WINVER 0x0500
#include <windows.h>
#include <structures.h>

#define _GETCURSOR 1
#define _GETKEY 2
#define _SLEEP 3

/** requires more testing */
void send_input(const int KEY_CODE)
{
    if (KEY_CODE <= 2) {
        INPUT ip = {0};
        ip.type = INPUT_MOUSE;

        switch(KEY_CODE) {
            case 1:
                    ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
                    break;
            case 2:
                    ip.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
                    break;
            case 4:
                    ip.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP;
                    break;
            default:
                    return;
        }
        SendInput(1, &ip, sizeof(INPUT));
        return;
    }
    else {
        INPUT ip = {0};
        ip.type = INPUT_KEYBOARD;
        //ip.ki.wScan = MapVirtualKey(KEY_CODE, 0);
        //ip.ki.dwFlags = KEYEVENTF_SCANCODE;

        ip.ki.dwFlags = 0;
        ip.ki.wVk = KEY_CODE;

        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        return;
    }
}

void set_cursor(const int x, const int y)
{
    SetCursorPos(x, y);
}

void set_sleep(const int duration)
{
    Sleep(duration);
}

void play_recording(struct f_queue *tail)
{
    int i = 1;
    while (tail) {
        if (tail->f_type == _GETCURSOR)
            set_cursor(tail->f_args[0], tail->f_args[1]);
        else if (tail->f_type == _GETKEY)
            send_input(tail->f_args[0]);
        else if (tail->f_type == _SLEEP)
            set_sleep(tail->f_args[0]);

        tail = tail->prev;
    }
}
