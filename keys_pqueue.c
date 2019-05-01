#include <key_codes.h>

/** sorted from the most often pressed key to least often */
const unsigned short keys_pqueue[21] = { KEY_LMB,
KEY_SPACE,
KEY_BACK,
KEY_RETURN,
KEY_RMB,
KEY_SHIFT,
KEY_E,
KEY_A,
KEY_O,
KEY_I,
KEY_O,
KEY_D,
KEY_W,
KEY_K,
KEY_Z,
KEY_P,
KEY_L,
KEY_S,
KEY_1,
KEY_2,
KEY_3
}; // rest to be filled, in proper priority order, after I get right amount of data from WhatPulse app

const int keys_pqueue_size = sizeof(keys_pqueue) / sizeof(keys_pqueue[0]);

void test_display_pqueue()
{
    printf("ASCII codes of keys_pqueue:\n");
    for (int i = 0; i < (sizeof(keys_pqueue)/sizeof(keys_pqueue[0])); i++)
        printf("key %d: %d\n", i + 1, keys_pqueue[i]);
}
