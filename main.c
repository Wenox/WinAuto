/** @file */

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

int main(int argc, char **argv)
{
    struct f_queue *headptr = NULL;
    struct f_queue *tailptr = NULL;

    if (!h_switch_invoked(argc, argv))
        init_menu(headptr, tailptr, 0, 0);
    else
        init_menu(headptr, tailptr, 7, 0);

    return 0;
}
