#include <stdio.h>
#include <windows.h>
#include <f_queue.h>
#include <recording.h>
#include <files.h>
#include <replay.h>
#include <f_queue.h>

void draw_menu(const int error_id)
{
    system("cls");
    switch (error_id) {
        case 0:
            printf("WinAuto\n");
            break;
        case 1:
            printf("ERROR: File name must end with .txt suffix\n\n");
            break;
        case 2:
            printf("ERROR: No such file\n\n");
            break;
        default: // do nothing
            break;
    }
    printf("Press 1 to set global hotkey\n");
    printf("Press 2 to create new recording\n");
    printf("Press 3 to load recording from file\n");
}

int get_choice()
{
    int choice = 0;

    while (choice < 1 || choice > 3)
        if (1 != scanf("%d", &choice))
            fseek(stdin, 0, SEEK_END);

    return choice;
}

bool str_ends_with(const char *source, const char *suffix)
{
    int source_len = strlen(source);
    int suffix_len = strlen(suffix);

    return (source_len >= suffix_len) && (0 == strcmp(source + (source_len - suffix_len), suffix));
}

int get_cycles_num()
{
    printf("How many playing cycles? (>5 to play infinitely, default 1): ");
    int cycles_num = 1;
    if (1 != scanf("%d", &cycles_num) || cycles_num <= 0) {
        fseek(stdin, 0, SEEK_END);
        get_cycles_num();
    }

    return cycles_num;
}

void exec_play_recording(struct f_queue *head, struct f_queue *tail, const int cycles_num)
{
    if (cycles_num > 5) {
        make_queue_cyclic(head, tail);
        play_recording(tail);
        unmake_queue_cyclic(head, tail);
        return;
    }
    for (int i = 0; i < cycles_num; i++)
        play_recording(tail);
}

void init_menu(struct f_queue *head, struct f_queue *tail, const int error_id)
{
    draw_menu(error_id);

    int choice = get_choice();

    switch(choice) {
        case 1:
            printf("Choose hotkey: \n");
            break;
        case 2:
            printf("Save recording as (i.e: myrecording.txt):\n");
            char file_name[64];
            scanf("%s", file_name);
            if (str_ends_with(file_name, ".txt")) {
                    record(&head, &tail, 10);
                    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                    trim_list(&head);
                    save_recording(tail, file_name);
                    free_recording(&head, &tail);
                    init_menu(head, tail, 0);
            }
            init_menu(head, tail, 1);
            break;
        case 3:
            printf("Type in file name (i.e: myfile.txt):\n");
            scanf("%s", file_name);
            printf("\n%s\n", file_name);
            if (load_recording(&head, &tail, file_name)) {
                int cycles_num = get_cycles_num();
                exec_play_recording(head, tail, cycles_num);
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                free_recording(&head, &tail);
                init_menu(head, tail, 0);
            }
            init_menu(head, tail, 2);
            break;
        default: // do nothing
            break;
    }
}
