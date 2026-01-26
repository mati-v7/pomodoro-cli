#include "pomodoro.h"
#include "notifications.h"
#include "timer.h"
#include "tui.h"
#include <stdio.h>

void run_pomodoro_tui(PomodoroConfig config)
{
    int cycles = config.cycles_before_long_break;

    for (int i = 1; i <= cycles; i++)
    {
        start_timer_tui(config.work_duration, STATE_WORK);
        notify_all("Pomodoro", "Timer complete! Take a break.");

        if (i < cycles)
        {
            start_timer_tui(config.short_break_duration, STATE_SHORT_BREAK);
            notify_all("Pomodoro", "Break over! Back to work.");
        }
    }

    start_timer_tui(config.long_break_duration, STATE_LONG_BREAK);
    notify_all("Pomodoro", "Long break over!");
}
