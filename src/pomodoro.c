#include "pomodoro.h"
#include "notifications.h"
#include "timer.h"
#include "tui.h"
#include <stdio.h>

void run_pomodoro_tui(PomodoroConfig config)
{
    int cycles = config.cycles_before_long_break;
    notifications_init(config);

    for (int i = 1; i <= cycles; i++)
    {
        start_timer_tui(config.work_duration, STATE_WORK);
        notify_event(EVENT_WORK_DONE);

        if (i < cycles)
        {
            start_timer_tui(config.short_break_duration, STATE_SHORT_BREAK);
            notify_event(EVENT_SHORT_BREAK_DONE);
        }
    }

    start_timer_tui(config.long_break_duration, STATE_LONG_BREAK);
    notify_event(EVENT_LONG_BREAK_DONE);
}
