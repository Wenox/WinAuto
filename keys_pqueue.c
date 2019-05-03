#include <key_codes.h>

/** sorted from the most likely most often pressed key to least likely least often */
const unsigned short keys_pqueue[25] = { KEY_LMB, // highest priority to be checked
KEY_SPACE,
KEY_BACK,
KEY_RETURN,
KEY_RMB,
KEY_SHIFT,
KEY_E,
KEY_A,
KEY_O,
KEY_I,
KEY_X,
KEY_O,
KEY_D,
KEY_W,
KEY_K,
KEY_Z,
KEY_P,
KEY_L,
KEY_S,
KEY_J,
KEY_B,
KEY_N,
KEY_1,
KEY_2,
KEY_3 // lowest priority
}; // rest to be filled, in proper priority order, after I get right amount of data from WhatPulse app

const int keys_pqueue_size = sizeof(keys_pqueue) / sizeof(keys_pqueue[0]);

/** used for testing */
#include <stdio.h>
void __test_display_pqueue(void)
{
    printf("ASCII codes of keys_pqueue:\n");
    for (int i = 0; i < (sizeof(keys_pqueue)/sizeof(keys_pqueue[0])); i++)
        printf("key %d: %d\n", i + 1, keys_pqueue[i]);
}
