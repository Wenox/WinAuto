/** @file */

#include <stdio.h>
#include <f_queue.h>
#include <functions_queue.h>
#include <stdbool.h>

void save_recording(struct f_queue *tail, char *file_name)
{
    FILE *f = fopen(file_name, "w");
    if (f == NULL)
        return;

    while (tail) {
        fprintf(f, "%d %d %d\n", tail->f_type, tail->f_args[0], tail->f_args[1]); ///< The data is saved in <b><int> <int> <int></b> fashion.
        tail = tail->prev;
    }

    fclose(f);
}

bool load_recording(struct f_queue **head, struct f_queue **tail, char *file_name)
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        return false;
    }

    char buffer[256];
    int f_type, arg1, arg2;
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (sscanf(buffer, "%d %d %d", &f_type, &arg1, &arg2) != 3) ///< Basic file validation.
            goto error; ///< In case of exception.

        add_function(head, tail, f_type, arg1, arg2);
    }

    fclose(f);
    return true;

error: ///< <b>goto</b> is not necessarily harmful when handling errors, it makes the code simple and can even increase readability.
    return false;
}
