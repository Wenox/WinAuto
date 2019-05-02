#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/** Main structure which is filled during recording.
 *  Contains data organized in proper order representing corresponding function calls:
 *   - which keys were pressed
 *   - sleeps' durations
 *   - cursor's positions
 *  In order to make the queue as short as possible, when idle during recording process:
 *   - the sleep's duration is summed with previous one into one larger value, repeated until keypress/mouse movement occured
 *   - cursos's position is added if and only if the cursor is moving
 *   - keypresses are assumed to be instantaneous, hence prolonged keypresses are neglected
 *  Structure is filled during keyboard/mouse recording and used for replay of the recording.
 */

struct f_queue {
    short f_type;      // tbd(?): replace with enum
    int f_args[2];
    struct f_queue *next, *prev;
};

#endif // STRUCTURES_H_INCLUDED
