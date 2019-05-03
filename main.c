#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <smooth_cursor.h>
#include <pressed_key.h>
#include <structures.h>
#include <functions_queue.h>
#include <recording.h>
#include <replay.h>

int main()
{
    Sleep(4000);
    send_input(65);
    send_input(66);
    send_input(1);
    send_input(66);
    send_input(66);
    send_input(66);
    /*
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    record(&headptr, &tailptr, 20);
    __print(headptr);
    //__print_back(tailptr);
    printf("\ndelete:\n");
    __print(headptr);*/

    int i = -1;
    scanf("%d", &i);
    return 0;
}
