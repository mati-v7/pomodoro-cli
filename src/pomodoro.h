#ifndef POMODORO_H
#define POMODORO_H

#define WORK_DURATION 1500         // 25 min
#define SHORT_BREAK_DURATION 300   // 5 min
#define LONG_BREAK_DURATION 900    // 15 min
#define CYCLES_BEFORE_LONG_BREAK 4

typedef enum {
    STATE_WORK,
    STATE_SHORT_BREAK,
    STATE_LONG_BREAK
} PomodoroState;

void run_pomodoro_cycle(int total_cycles);

#endif