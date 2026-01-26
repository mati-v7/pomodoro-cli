#ifndef STATS_H
#define STATS_H

typedef struct {
    int total_sessions;
    int total_pomodoros;
    int today_pomodoros;
    char last_session[64];
} PomodoroStats;

PomodoroStats load_stats(const char *filename);
void print_stats(PomodoroStats stats);

#endif
