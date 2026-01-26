#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void format_time(int seconds, char *buffer) {
    int minutes = seconds / 60;
    int remaining_seconds = seconds % 60;

    sprintf(buffer, "%02d:%02d", minutes, remaining_seconds);
}

void start_timer(int seconds) {
    char time_buffer[6]; // "mm:ss"

    while (seconds >= 0) {
        format_time(seconds, time_buffer);
        printf("\r⏱  %s", time_buffer);
        fflush(stdout);
        sleep(1);
        seconds--;
    }

    printf("\n");
    beep();
}

void beep(void) {
    int result = system("which play > /dev/null 2>&1");

    if (result == 0) {
        system("play -nq -t alsa synth 0.2 sine 440");
    } else {
        // fallback: ASCII bell
        printf("\a");
        fflush(stdout);
    }
}
