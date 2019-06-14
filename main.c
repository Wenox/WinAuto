#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <f_queue.h>
#include <functions_queue.h>
#include <recording.h>
#include <replay.h>
#include <menu.h>
#include <files.h>
#include "test/test.h"

int main()
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    init_menu(headptr, tailptr, 0);

    return 0;
}
