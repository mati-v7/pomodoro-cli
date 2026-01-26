#ifndef EXPORT_H
#define EXPORT_H

typedef struct {
    int year, month, day;
    int hour, minute;
    int pomodoros;
} PomodoroSession;

int export_csv(const char *history_file, const char *output_file);
int export_json(const char *history_file, const char *output_file);

#endif
