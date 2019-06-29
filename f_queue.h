/** @file */

#ifndef F_QUEUE_H_INCLUDED
#define F_QUEUE_H_INCLUDED

/** The core, most significant structure of the program. <b>f_queue</b> is a doubly linked list that if needed shifts itself into cyclic doubly linked list.
<b>f_queue</b> resembles queue-alike structure.
Each <b>f_queue</b> node describes a function call that needs to be performed when playing the saved recording.
@warning There are three types of function descriptions:
- Type 1: corresponding to cursor's position
- Type 2: corresponding to registered keystrokes (including mouse device)
- Type 3: corresponding to setting the registered duration in between mouse's movements and keystrokes
@warning Each node has up to two function arguments. */
struct f_queue {
    short f_type;                   ///< Describes one of three available function types to be registered (thanks to this, we know which function call should be executed during playback phase)
    int f_args[2];                  ///< Describes up to two function arguments to be inserted into function call during playback phase
    struct f_queue *next, *prev;    ///< Pointers to the next and previous <b>f_type</b> nodes
};

/** Main structure which is filled during recording.
 *  Contains data organized in proper order representing corresponding function calls:
 *   - which keys were pressed
 *   - sleeps' durations
 *   - cursor's positions
 *  In order to make the queue <b>as short as possible</b>, and hence save memory, when idle during recording process:
 *   - the sleep's duration is summed up with previous one into one larger value, repeated until keypress/mouse movement occured
 *   - cursos's position is added if and only if the cursor had moved since previous cursor position's registration
 *   - keypresses are assumed to be <b>instantaneous</b>, hence prolonged keypresses are <b>neglected</b> (assumed as one keypress)
 *  Structure is filled by record() and then used for replay of the recording by play_recording().
*/

#endif // F_QUEUE_H_INCLUDED
