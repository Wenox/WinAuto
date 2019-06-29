/** @file */

#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

/** Function saves the recording into .txt file, allowing user to retrieve data from it later on (in order to play the saved recording).
@param tail pointer to the last <b>f_queue</b>
@param file_name pointer to saved file's name */
void save_recording(struct f_queue *tail, char *file_name);

/** Function reads saved recording from the .txt file into the <b>f_queue</b> linked list. Function <b>validates correctness</b> of
the .txt file that is being read. If the file for some reason is corrupted, an exception occurs. In such case, corrupted file cannot be handled by playing engine,
so the <b>memory is freed</b> and user is sent back to main menu.
@param head pointer to pointer to the first <b>f_queue</b> node
@param tail pointer to pointer to the last <b>f_queue</b> node
@param file_name pointer to file name that is being read
@return <b>true</b> if file has been read successfully
@return <b>false</b> if file cannot be opened, does not exist or is corrupted */
bool load_recording(struct f_queue **head, struct f_queue **tail, char *file_name);

#endif // FILES_H_INCLUDED
