#ifndef POMODORO_H
#define POMODORO_H

typedef struct
{
    int work_duration;        // seconds
    int short_break_duration; // seconds
    int long_break_duration;  // seconds
    int cycles_before_long_break;
    int enable_sound;
    int enable_desktop;
    int throttle_seconds;
} PomodoroConfig;

void run_pomodoro_tui(PomodoroConfig config);

#endif