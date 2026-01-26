#include "pomodoro.h"
#include "timer.h"
#include <stdio.h>

void run_pomodoro_cycle(int total_cycles) {
    int completed_cycles = 0;

    while (completed_cycles < total_cycles) {
        printf("\n--- Pomodoro %d/%d ---\n", completed_cycles + 1, total_cycles);

        printf("Work Time!\n");
        start_timer(WORK_DURATION);

        completed_cycles++;

        if (completed_cycles % CYCLES_BEFORE_LONG_BREAK == 0) {
            printf("Long Break!\n");
            start_timer(LONG_BREAK_DURATION);
        } else if (completed_cycles < total_cycles) {
            printf("Short Break!\n");
            start_timer(SHORT_BREAK_DURATION);
        }
    }

    printf("\nAll pomodoros completed!\n");
}
