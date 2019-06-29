/** @file */

#ifndef FUNCTIONS_QUEUE_H_INCLUDED
#define FUNCTIONS_QUEUE_H_INCLUDED

/** Function adds new <b>description</b> of function-call at the start of <b>f_queue</b>.
@warning
@param head pointer to pointer to the first node
@param tail pointer to pointer to the last node
@param f_type describes inserted function's type:
<b>1</b> - if function is of type describing cursor's position,
<b>2</b> - if function is of type describing keystrokes,
<b>3</b> - if function is of type describing durations in between function calls
@param arg1 the first argument for the described function
@param arg2 the second argument for the described function */
void add_function(struct f_queue **head, struct f_queue **tail, const short f_type, const int arg1, const int arg2);

/** Function <b>frees</b> all nodes from <b>f_queue except</b> the tail without introducing any <b>'if'</b> statements.
@param head pointer to pointer to the first <b>f_queue</b> node */
void free_all_but_tail(struct f_queue **head);

/** Function <b>frees</b> the tail that has not been freed by <b>free_all_but_tail()</b> function.
@param head pointer to pointer to the first <b>f_queue</b> node
@param tail pointer to pointer to the last <b>f_queue</b> node */
void free_tail(struct f_queue **head, struct f_queue **tail);

/** Function frees all nodes from f_queue, without introducing any excessive <b>'if'</b> statements. This function ties up <b>free_all_but_tail</b> and <b>free_tail</b> functions.
@param head pointer to pointer to the first <b>f_queue</b> node
@param tail pointer to pointer to the last <b>f_queue</b> node */
void free_recording(struct f_queue **head, struct f_queue **tail);

/** The function <b>sets the cyclic list property</b> onto the <b>f_queue</b> doubly linked list. The function ties up the head and the tail together.
@param head pointer to the first <b>f_queue</b> node
@param tail pointer to the last <b>f_queue</b> node */
void make_queue_cyclic(struct f_queue *head, struct f_queue *tail);

/** The function removes the cyclic list property off of the <b>f_queue</b> doubly linked list. The head and tail are no longer tied up together.
@param head pointer to the first <b>f_queue</b> node
@param tail pointer to the last <b>f_queue</b> node */
void unmake_queue_cyclic(struct f_queue *head, struct f_queue *tail);

/** The function removes the first element from the <b>f_queue</b> doubly linked list. No margin cases need to be considered, as they will never occur.
@param head pointer to pointer to the first list element */
void trim_head(struct f_queue **head);

/** The function is a wrapper function around <b>trim_head</b> function, and removes <b>two</b> starting nodes from the <b>f_queue</b> doubly linked list. No margin cases need to be considered, as they will never occur.
@param head pointer to pointer to the first list element */
void trim_list(struct f_queue **head);

#endif // FUNCTIONS_QUEUE_H_INCLUDED
