#include <stdio.h>
#include <f_queue.h>
#include <functions_queue.h>

/** TEMPORARY */
void save_recording(struct f_queue *tail)
{
    char *file_name = "recording.txt";

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
    fprintf(f, "num of nodes: %d\n", line_counter);
    fclose(f);
    printf("all saved\n");
}

void load_recording(struct f_queue **head, struct f_queue **tail)
{
    char *file_name = "recording.txt";

    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        printf("Cant open file\n");
        return;
    }

    int f_type, arg1, arg2;
    while (fscanf(f, "%d %d %d", &f_type, &arg1, &arg2))
        add_function(head, tail, f_type, arg1, arg2);
}
