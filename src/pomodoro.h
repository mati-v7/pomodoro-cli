#ifndef POMODORO_H
#define POMODORO_H

typedef enum {
    STATE_WORK,
    STATE_SHORT_BREAK,
    STATE_LONG_BREAK
} PomodoroState;

typedef struct {
    int work_duration;           // seconds
    int short_break_duration;    // seconds
    int long_break_duration;     // seconds
    int cycles_before_long_break;
} PomodoroConfig;

void run_pomodoro_cycle(int total_cycles, PomodoroConfig config);
void run_pomodoro_tui(PomodoroConfig config);

#endif