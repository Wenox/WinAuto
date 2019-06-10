#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

void save_recording(struct f_queue *tail);

void load_recording(struct f_queue **head, struct f_queue **tail);

#endif // FILES_H_INCLUDED
