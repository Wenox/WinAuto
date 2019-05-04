#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

/** function adds new description of function-call at the start of queue */
void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2);

/** currently not used, to be fixed */
void __delete_first(struct f_queue **head);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
