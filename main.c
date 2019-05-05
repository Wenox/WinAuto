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

    printf("recording [press W to stop]\n");
    record(&headptr, &tailptr, 10);
    play_recording(tailptr);

    free_recording(&headptr, &tailptr);
    __test_print_f_queue_back(tailptr);
    __test_print_f_queue(headptr);

    int i = -1;
    scanf("%d", &i);
    return 0;
}

/*void save_file(struct f_queue *tail)
{
    char *file_name = "file.txt";

    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        printf ("f == NULL\n");
        return;
    }

    int line_counter = 0;
    while (tail) {
        fprintf(f, "%d %d %d\n", tail->f_type, tail->f_args[0], tail->f_args[1]);
        line_counter++;
        tail = tail->prev;
    }
    fprintf(f, "num of lines: %d\n", line_counter);
    fclose(f);
}*/
