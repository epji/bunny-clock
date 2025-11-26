#include <stdio.h>
#include <time.h>
#include <unistd.h>  // for sleep() on macOS/Linux

void clear_screen(void) {
    // ANSI escape sequence: clear screen + move cursor to top-left
    printf("\033[2J\033[H");
}

void draw_bunny_clock(struct tm *now) {
    char time_str[9];  // "HH:MM:SS" + null
    strftime(time_str, sizeof(time_str), "%H:%M:%S", now);

    printf("(\\_/)\n");
    printf("(•ㅅ•)  Time: %s\n", time_str);
    printf("/   づ\n");
}

int main(void) {
    while (1) {
        time_t t = time(NULL);     // get current time in seconds
        struct tm *now = localtime(&t); // convert to local time

        clear_screen();
        draw_bunny_clock(now);

        fflush(stdout);   // make sure it prints immediately
        sleep(1);         // wait 1 second
    }

    return 0;
}
