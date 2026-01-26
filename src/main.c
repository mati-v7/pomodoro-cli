#include <stdio.h>
#include <stdlib.h>
#include "pomodoro.h"

int main(int argc, char *argv[]) {
    printf("Pomodoro C 🍅\n");

    // default values
    PomodoroConfig config = {
        .work_duration = 1500,          // 25 min
        .short_break_duration = 300,    // 5 min
        .long_break_duration = 900,     // 15 min
        .cycles_before_long_break = 4
    };

    int total_cycles = 4;

    if (argc >= 2) config.work_duration = atoi(argv[1]);
    if (argc >= 3) config.short_break_duration = atoi(argv[2]);
    if (argc >= 4) config.long_break_duration = atoi(argv[3]);
    if (argc >= 5) config.cycles_before_long_break = atoi(argv[4]);

    run_pomodoro_cycle(total_cycles, config);

    return 0;
}