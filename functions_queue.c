/** @file */

#include <stddef.h>
#include <stdlib.h>
#include <f_queue.h>

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

void free_all_but_tail(struct f_queue **head)
{
    while ((*head)->next != NULL) {
        struct f_queue *to_be_deleted = *head;
        *head = to_be_deleted->next;
        (*head)->prev = NULL;
        free(to_be_deleted);
    }
}

void free_tail(struct f_queue **head, struct f_queue **tail)
{
    struct f_queue *to_be_deleted = *tail;
    *head = NULL;
    *tail = NULL;
    free(to_be_deleted);
}

void free_recording(struct f_queue **head, struct f_queue **tail)
{
    free_all_but_tail(head);
    free_tail(head, tail);
}

void make_queue_cyclic(struct f_queue *head, struct f_queue *tail)
{
    tail->next = head;
    head->prev = tail;
}

void unmake_queue_cyclic(struct f_queue *head, struct f_queue *tail)
{
    tail->next = NULL;
    head->prev = NULL;
}

void trim_head(struct f_queue **head)
{
    struct f_queue *to_be_deleted = *head;
    *head = to_be_deleted->next;
    free((*head)->prev);
    (*head)->prev = NULL;
}

void trim_list(struct f_queue **head)
{
    trim_head(head);
    trim_head(head);
}
