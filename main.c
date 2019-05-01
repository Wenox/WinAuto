#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <smooth_cursor.h>
#include <key_codes.h>
#include <pressed_key.h>
#include <keys_pqueue.h>
#include <structures.h>
#include <functions_queue.h>

int main()
{
    //test_keypresses(100);
    //test_display_pqueue();

    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    add_function(&headptr, &tailptr, 1, 55, 55);
    add_function(&headptr, &tailptr, 2, 14, 88);
    add_function(&headptr, &tailptr, 1, 111, 0);
    print(headptr);
    print_back(tailptr);

    int i;
    scanf("%d", i);
    return 0;
}
