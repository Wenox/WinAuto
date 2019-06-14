#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

void save_recording(struct f_queue *tail, char *file_name);

bool load_recording(struct f_queue **head, struct f_queue **tail, char *file_name);

#endif // FILES_H_INCLUDED
