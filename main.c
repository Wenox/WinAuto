#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <smooth_cursor.h>
#include <key_codes.h>
#include <pressed_key.h>

int main()
{
    Sleep(3000); // during those 3 seconds I press keys 'a', 'b' and 'c'
    printf("%d\n", last_pressed_key()); // prints 65 (a) as expected
    empty_buffer();

    Sleep(1000);
    printf("%d\n", last_pressed_key()); // prints 0 (no key pressed) as expected
    empty_buffer();

    Sleep(1000);
    printf("extra:\n");
    printf("%d\n", last_pressed_key_extra()); // prints 0 as expected
    empty_buffer();

    int i;
    scanf("%d", i);
    return 0;
}
