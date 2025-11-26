#include <stdio.h>
#include <time.h>
#include <unistd.h>  // sleep()

// 0 = happy, 1 = sleep
void clear_screen(void) {
    // ANSI escape sequence: clear screen + move cursor to top-left
    printf("\033[2J\033[H");
}

void draw_bunny_clock(struct tm *now, int mood) {
    char time_str[9];  // "HH:MM:SS" + null
    strftime(time_str, sizeof(time_str), "%H:%M:%S", now);

    if (mood == 0) {
        // HAPPY BUNNY
        printf("(\\_/)\n");
        printf("(•ㅅ•)  Time: %s\n", time_str);
        printf("/   づ\n");
    } else {
        // sleep BUNNY
        printf("(\\_/)\n");
        printf("(-ㅅ-)  Time: %s\n", time_str);
        printf("/   づ\n");
    }
}

int main(void) {
    int counter = 0;

    while (1) {
        time_t t = time(NULL);
        struct tm *now = localtime(&t);

        // Every 5 seconds, switch mood:
        // 0–4s: happy, 5–9s: sleep, 10–14s: happy, ...
        int mood = (counter / 5) % 2;  // 0 or 1

        clear_screen();
        draw_bunny_clock(now, mood);

        fflush(stdout);
        sleep(1);

        counter++;
    }

    return 0;
}
