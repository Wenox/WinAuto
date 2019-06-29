/** @file */

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

/** Testing purposes, no longer needed. Could be useful in the future.
@param how_many number of key_presses to be checked
@sleep_dur waiting interval */
void __test_keystrokes(const int how_many, const int sleep_dur);

/** The function prints the priority queue of keys to be checked during recording process. No longer used, however could be needed for future testing/debugging purposes. */
void __test_print_pqueue(void);

/** The function prints the <b>f_queue</b> forwards. No longer used, however could be needed for future testing/debugging purposes.
@param head pointer to the first node of the <b>f_queue</b> */
void __test_print_f_queue(struct f_queue *head);

/** The function prints the <b>f_queue</b> backwards. No longer used, however could be needed for future testing/debugging purposes.
@param tail pointer to the last node of the <b>f_queue</b> */
void __test_print_f_queue_back(struct f_queue *tail);

#endif // TEST_H_INCLUDED
