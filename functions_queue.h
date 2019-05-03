#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

/** used for testing. prints the functions queue backwards */
void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2);

/** currently not used, to be fixed */
void __delete_first(struct f_queue **head);

/** used for testing. prints the functions queue forwards */
void __print(struct f_queue *head);

/** used for testing. prints the functions queue backwards */
void __print_back(struct f_queue *tail);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
