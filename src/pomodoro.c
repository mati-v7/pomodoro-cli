#include "pomodoro.h"
#include "timer.h"
#include <stdio.h>

void run_pomodoro_cycle(int total_cycles, PomodoroConfig config) {
    int completed_cycles = 0;

    while (completed_cycles < total_cycles) {
        printf("\n--- Pomodoro %d/%d ---\n", completed_cycles + 1, total_cycles);

        printf("Work Time!\n");
        start_timer(config.work_duration);

        completed_cycles++;

        if (completed_cycles % config.cycles_before_long_break == 0) {
            printf("Long Break!\n");
            start_timer(config.long_break_duration);
        } else if (completed_cycles < total_cycles) {
            printf("Short Break!\n");
            start_timer(config.short_break_duration);
        }
    }

    printf("\nAll pomodoros completed!\n");
}
