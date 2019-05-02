#include <windows.h>

POINT get_cursor(void)
{
    POINT P = {};
    GetCursorPos(&P);
    return P;
}
