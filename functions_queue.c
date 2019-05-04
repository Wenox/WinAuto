#include <stddef.h>
#include <stdlib.h>
#include <f_queue.h>

/** function adds new description of function-call at the start of queue */
void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2)
{
    struct f_queue *node = malloc(sizeof(struct f_queue));
    node->f_type = f_type;
    node->f_args[0] = arg1;
    node->f_args[1] = arg2;
    node->prev = NULL;
    if(*head == NULL) {
        *tail = node;
        node->next = NULL;
    }
    else {
        node->next = *head;
        (*head)->prev = node;
    }
    *head = node;
}

/** currently not used, to be fixed */
void __delete_first(struct f_queue **head)
{
    /** to be fixed */
    struct f_queue *to_be_deleted = *head;
    *head = to_be_deleted->next;
    (*head)->prev = NULL;
    free(to_be_deleted);
}
