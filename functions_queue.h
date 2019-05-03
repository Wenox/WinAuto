#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2);

void delete_first(struct f_queue **head);

void __print(struct f_queue *head);

void __print_back(struct f_queue *tail);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
