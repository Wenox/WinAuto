#define WINVER 0x0500
#include <windows.h>
#include <key_codes.h>

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
        ip.ki.wVk = KEY_CODE;

        SendInput(1, &ip, sizeof(INPUT));
        return;
    }
}
