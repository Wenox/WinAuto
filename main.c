#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <f_queue.h>
#include <recording.h>
#include <replay.h>
#include "test/test.h"

int main()
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    printf("recording\n");
    record(&headptr, &tailptr, 10);
    __print_f_queue_back(tailptr);

    Sleep(5000);
    printf("playing recording\n");
    play_recording(tailptr);

    int i = -1;
    scanf("%d", &i);
    return 0;
}
