#include <structures.h>
#include <stddef.h>

void add_function(struct f_queue **head, struct f_queue **tail, short f_type, int arg1, int arg2)
{
    struct f_queue *node = (struct f_queue*)malloc(sizeof(struct f_queue));
    node->f_type = f_type;
    node->f_args[0] = arg1;
    node->f_args[1] = arg2;
    node->prev = NULL;
    if(*head==NULL) {
        *tail=node;
        node->next=NULL;
    }
    else {
        node->next=*head;
        (*head)->prev=node;
    }
    *head = node;
}
void print(struct f_queue *head)
{
    if (!head)
        printf("empty\n");

    for (int i = 1 ; head != NULL; head = head->next)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, head->f_type, head->f_args[0], head->f_args[1]);
}
void print_back(struct f_queue *tail)
{
    for (int i = 1 ; tail != NULL; tail = tail->prev)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, tail->f_type, tail->f_args[0], tail->f_args[1]);
}
