#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <smooth_cursor.h>

int main()
{
    srand (time(NULL));
    __random_smooth_move(500, 500);
    //getcursor_movecursor();
    return 0;
}
