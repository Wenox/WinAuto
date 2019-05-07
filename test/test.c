#include <stdio.h>
#include <windows.h>
#include <../pressed_key.h>
#include <../keys_pqueue.h>
#include <../f_queue.h>

void __test_keystrokes(const int how_many, const int sleep_dur)
{
    printf("testing %d keypresses, each keypress every %d miliseconds\n", how_many, sleep_dur);
    for (int i = 0; i < how_many; i++) {
        printf("%d\n", get_keystroke());
        Sleep(sleep_dur);
    }
}

void __test_print_pqueue(void)
{
    printf("Codes of keys_pqueue sorted from highest priority to lowest:\n");
    for (int i = 0; i < (sizeof(keys_pqueue) / sizeof(keys_pqueue[0])); i++)
        printf("key %d: %d code\n", i + 1, keys_pqueue[i]);
}

/** prints the functions queue forwards */
void __test_print_f_queue(struct f_queue *head)
{
    printf("printing forwards:\n");
    if (!head) {
        printf("empty\n");
        return;
    }

    for (int i = 1; head != NULL; head = head->next)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, head->f_type, head->f_args[0], head->f_args[1]);
}

/** prints the functions queue backwards */
void __test_print_f_queue_back(struct f_queue *tail)
{
    printf("printing backwards:\n");
    if (!tail) {
        printf("empty\n");
        return;
    }

    for (int i = 1; tail != NULL; tail = tail->prev)
        printf("node %d: f_type: %d, f_args: %d %d\n", i++, tail->f_type, tail->f_args[0], tail->f_args[1]);
}
