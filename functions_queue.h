#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

/** function adds new description of function-call at the start of f_queue */
void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2);

/** function frees all nodes from f_queue except the tail */
void free_all_but_tail(struct f_queue **head);

/** function frees the tail from f_queue */
void free_tail(struct f_queue **head, struct f_queue **tail);

/** function frees all nodes from f_queue, without introducing any excessive 'if' statements */
void free_recording(struct f_queue **head, struct f_queue **tail);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
