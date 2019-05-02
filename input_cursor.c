#include <windows.h>

/** returns cursor's position */
POINT get_cursor(void)
{
    POINT P = {};
    GetCursorPos(&P);
    return P;
}
