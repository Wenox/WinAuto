/** @file */

#include <stdio.h>
#include <key_codes.h>
#include <windows.h>
#include <f_queue.h>
#include <recording.h>
#include <files.h>
#include <replay.h>
#include <functions_queue.h>
#include <pressed_key.h>
#include <smooth_cursor.h>

#define error(msg) fprintf(stderr, msg)

void print_help()
{
    printf("Welcome to WinAuto\n");
    printf("You chose -h flag\n\n");
    printf("Option (1): choose the hotkey. This hotkey will be used in options (2), (3), (4)\n\n");
    printf("Option (2): start the recording. Save as <file-name>.txt, for example test.txt. The file has to end with .txt\n");
    printf("Use hotkey to stop the recording.\n\n");
    printf("Option (3): start the playback of the recording created in (2). Load the recording with appropriate file name.\n");
    printf("Choose number of cycles (repetitions) of the replay. If you wish to terminate the playback, hold hotkey.\n\n");
    printf("Option (4): extra feature. Choose arbitrary speed and minfps to start the screensaver.\nYou have to HOLD hotkey to terminate\n\n\n");
    printf("Option (5): to exit program\n\n\n");
}

bool h_switch_invoked(int argc, char **argv)
{
    if (argc > 1)
        if (0 == strcmp(argv[1], "-h"))
            return true;

    return false;
}

/** Enum containing various menu flags used to determine which <b>printf</b> should be displayed to the user, based on earlier program behaviour. */
enum menu_flags {               ///< start of definition
    NO_ERRORS,                  ///< default
    ERROR_NO_TXT_SUFFIX,        ///< when user forgot to input the .txt postfix
    ERROR_READING_FILE,         ///< when file was corrupted, does not exist or cannot be opened
    SAVED_HOTKEY,               ///< when the hotkey has been successfully saved
    SAVED_FILE,                 ///< when the file saved successfully
    STOPPED_PLAYBACK,           ///< when the recording playback successfully ended
    STOPPED_SCREENSAVER,        ///< when the screensaver has been successfully stopped
    HELP_SWITCH                 ///< when program was ran with '-h' switch
};

void draw_menu(const int flag_id)
{
    system("cls");

    switch (flag_id) {
        case 0:
            printf("WinAuto\n");
            break;
        case 1:
            error("ERROR: File name must end with .txt suffix\n\n");
            break;
        case 2:
            error("ERROR: No such file or file is corrupted\n\n");
            break;
        case 3:
            printf("Hotkey set successfully\n\n");
            break;
        case 4:
            printf("Recording saved successfully\n\n");
            break;
        case 5:
            printf("Playback finished or interrupted\n\n");
            break;
        case 6:
            printf("Welcome back\n\n");
            break;
        case 7:
            print_help();
            break;
        default: // do nothing
            break;
    }

    printf("Press 1 to set global hotkey (DEFAULT HOTKEY: F5)\n");
    printf("Press 2 to create new recording\n");
    printf("Press 3 to play recording\n");
    printf("Press 4 to start screensaver\n");
    printf("Press 5 to exit\n");
}

int get_menu_choice(void)
{
    int choice = 0;

    while (choice < 1 || choice > 5)
        if (1 != scanf("%d", &choice))
            fseek(stdin, 0, SEEK_END);

    return choice;
}

int get_hotkey(void)
{
    printf("Set hotkey: \n");
    int hotkey = 0;

    while (hotkey == 0 ||
           hotkey == KEY_RETURN ||
           hotkey == KEY_LMB ||
           hotkey == KEY_RMB ||
           hotkey == KEY_F5) {
                hotkey = get_keystroke();
           }

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    return hotkey;
}

bool str_ends_with(const char *source, const char *suffix)
{
    int source_len = strlen(source);
    int suffix_len = strlen(suffix);

    return (source_len >= suffix_len) && (0 == strcmp(source + (source_len - suffix_len), suffix));
}

int get_cycles_num(void)
{
    printf("How many playing cycles? (>5 to play infinitely, default 1):\n");
    int cycles_num = 1;

    if (1 != scanf("%d", &cycles_num) || cycles_num <= 0) {
        fseek(stdin, 0, SEEK_END);
        get_cycles_num();
    }

    return cycles_num;
}

void exec_play_recording(struct f_queue *head, struct f_queue *tail, const int cycles_num, const int hotkey_id)
{
    printf("Playing recording...\n");
    printf("Press your hotkey to stop\n");

    if (cycles_num > 5) {
        make_queue_cyclic(head, tail);
        play_recording(tail, hotkey_id);
        unmake_queue_cyclic(head, tail);
    }
    else {
        for (int i = 0; i < cycles_num; i++)
            play_recording(tail, hotkey_id);
    }
}

void init_menu(struct f_queue *head, struct f_queue *tail, const int flag_id, const int hotkey_id); ///< cyclic dependency

void chosen_recording(struct f_queue *head, struct f_queue *tail, const int hotkey_id)
{
    printf("Save recording as (i.e: myrecording.txt):\n");
    char file_name[64];
    scanf("%s", file_name);

    if (str_ends_with(file_name, ".txt")) {
        record(&head, &tail, 10, hotkey_id);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        trim_list(&head);
        save_recording(tail, file_name);
        free_recording(&head, &tail);
        init_menu(head, tail, SAVED_FILE, hotkey_id);
    }
    else {
        init_menu(head, tail, ERROR_NO_TXT_SUFFIX, hotkey_id);
    }
}

void chosen_playback(struct f_queue *head, struct f_queue *tail, const int hotkey_id)
{
    printf("Type in file name of your recording (i.e: myfile.txt):\n");
    char file_name[64];
    scanf("%s", file_name);

    if (load_recording(&head, &tail, file_name)) {
        int cycles_num = get_cycles_num();
        exec_play_recording(head, tail, cycles_num, hotkey_id);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        free_recording(&head, &tail);
        init_menu(head, tail, STOPPED_PLAYBACK, hotkey_id);
    }
    else { // error when reading file
        free_recording(&head, &tail);
        init_menu(head, tail, ERROR_READING_FILE, hotkey_id);
    }
}

void init_menu(struct f_queue *head, struct f_queue *tail, const int flag_id, const int hotkey_id)
{
    draw_menu(flag_id);

    int choice = get_menu_choice();
    static int hotkey = KEY_F5; /// default hotkey

    switch(choice) {
        case 1:
            hotkey = get_hotkey();
            init_menu(head, tail, SAVED_HOTKEY, hotkey);
            break;
        case 2:
            chosen_recording(head, tail, hotkey);
            break;
        case 3:
            chosen_playback(head, tail, hotkey);
            break;
        case 4:
            exec_screen_saver(hotkey);
            init_menu(head, tail, STOPPED_SCREENSAVER, hotkey);
            break;
        case 5:
            return;
        default: // do nothing
            break;
    }
}
