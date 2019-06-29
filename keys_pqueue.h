/** @file */

#ifndef KEYS_PQUEUE_H_INCLUDED
#define KEYS_PQUEUE_H_INCLUDED

/** Represents priority queue for keys to be checked while recording process. Sorted from the most likely most often pressed key to least likely least often.
The priority has been determined by nearly <b>2 000 000</b> registered keypresses throughout weeks of recording.
In order to increase readibility, individual files have been introduced due to long array's definition. */
extern const unsigned short keys_pqueue[104];

/** Determines the size of keys priority queue. */
extern const int keys_pqueue_size;

#endif // KEYS_PQUEUE_H_INCLUDED
