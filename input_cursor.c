#include <windows.h>

POINT get_cursor()
{
    POINT P = {};
    GetCursorPos(&P);
    return P;
}
