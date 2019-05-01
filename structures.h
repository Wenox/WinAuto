#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

struct f_queue {
    short f_type;
    int f_args[2];
    struct f_queue *next, *prev;
} list1, list2;

#endif // STRUCTURES_H_INCLUDED
