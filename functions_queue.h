#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

void add_function(struct f_queue **head, struct f_queue **tail, short f_type, int arg1, int arg2);

void print(struct f_queue *head);

void print_back(struct f_queue *tail);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
