#include <stddef.h>
#include <stdlib.h>
#include <structures.h>


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

/** used for testing */
#include <stdio.h>
void __print(struct f_queue *head)
{
    if (!head) {
        printf("empty\n");
        return;
    }

    for (int i = 1 ; head != NULL; head = head->next)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, head->f_type, head->f_args[0], head->f_args[1]);
}

/** used for testing */
void __print_back(struct f_queue *tail)
{
    if (!tail) {
        printf("empty\n");
        return;
    }

    for (int i = 1 ; tail != NULL; tail = tail->prev)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, tail->f_type, tail->f_args[0], tail->f_args[1]);
}
