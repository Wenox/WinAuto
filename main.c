#include <stdio.h>
#include <windows.h>
#include <smooth_cursor.h>
#include <pressed_key.h>
#include <structures.h>
#include <functions_queue.h>
#include <recording.h>

int main()
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    record(&headptr, &tailptr, 10);
    //__print(headptr);
    __print_back(tailptr);

    int i = -1;
    scanf("%d", &i);
    return 0;
}
