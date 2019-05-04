#ifndef F_QUEUE_H_INCLUDED
#define F_QUEUE_H_INCLUDED

struct f_queue {
    short f_type;      // tbd(?): replace with enum (?)
    int f_args[2];
    struct f_queue *next, *prev;
};

/** Main structure which is filled during recording.
 *  Contains data organized in proper order representing corresponding function calls:
 *   - which keys were pressed
 *   - sleeps' durations
 *   - cursor's positions
 *  In order to make the queue as short as possible, when idle during recording process:
 *   - the sleep's duration is summed with previous one into one larger value, repeated until keypress/mouse movement occured
 *   - cursos's position is added if and only if the cursor is moving
 *   - keypresses are assumed to be instantaneous, hence prolonged keypresses are neglected (assumed as one keypress)
 *  Structure is filled by record() and then used for replay of the recording by play_recording().
*/

#endif // F_QUEUE_H_INCLUDED
