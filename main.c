#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <f_queue.h>
#include <functions_queue.h>
#include <recording.h>
#include <replay.h>
#include <files.h>
#include "test/test.h"

int main()
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    load_recording(&headptr, &tailptr);
    //record(&headptr, &tailptr, 10);
    play_recording(tailptr);
    //save_recording(tailptr);
    free_recording(&headptr, &tailptr);

    int i = -1;
    scanf("%d", &i);
    return 0;
}
