#include "pomodoro.h"
#include "timer.h"
#include <stdio.h>

#define COLOR_RESET   "\x1b[0m"
#define COLOR_GREEN   "\x1b[32m" // Work
#define COLOR_BLUE    "\x1b[34m" // Short Break
#define COLOR_MAGENTA "\x1b[35m" // Long Break

void run_pomodoro_cycle(int total_cycles, PomodoroConfig config) {
    int completed_cycles = 0;

    while (completed_cycles < total_cycles) {
        printf("\n--- Pomodoro %d/%d ---\n", completed_cycles + 1, total_cycles);

        printf(COLOR_GREEN "Work Time!\n" COLOR_RESET);
        start_timer(config.work_duration);
        printf(COLOR_GREEN "Work complete! Take a break\n" COLOR_RESET);

        completed_cycles++;

        if (completed_cycles % config.cycles_before_long_break == 0) {
            printf(COLOR_MAGENTA "Long Break!\n" COLOR_RESET);
            start_timer(config.long_break_duration);
            printf(COLOR_MAGENTA "Long break complete! Ready for next work session\n" COLOR_RESET);
        } else if (completed_cycles < total_cycles) {
            printf(COLOR_BLUE "Short Break!\n" COLOR_RESET);
            start_timer(config.short_break_duration);
            printf(COLOR_BLUE "Short break complete! Back to work\n" COLOR_RESET);
        }
    }

    printf("\nAll pomodoros completed!\n");
}
