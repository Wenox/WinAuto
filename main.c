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
#include <recording.h>
#include <input_cursor.h>

int main()
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;
    record(&headptr, &tailptr, 10);
    //print(headptr);
    print_back(tailptr);

    int i;
    scanf("%d", i);
    return 0;
}
