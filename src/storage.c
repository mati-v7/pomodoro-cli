#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int load_config(PomodoroConfig *config, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return 0;

    char line[128];
    while (fgets(line, sizeof(line), f))
    {
        int val;
        if (sscanf(line, "work_duration=%d", &val) == 1)
            config->work_duration = val;
        else if (sscanf(line, "short_break_duration=%d", &val) == 1)
            config->short_break_duration = val;
        else if (sscanf(line, "long_break_duration=%d", &val) == 1)
            config->long_break_duration = val;
        else if (sscanf(line, "cycles_before_long_break=%d", &val) == 1)
            config->cycles_before_long_break = val;
    }

    fclose(f);
    return 1;
}

int save_config(PomodoroConfig config, const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (!f)
        return 0;

    fprintf(f, "work_duration=%d\n", config.work_duration);
    fprintf(f, "short_break_duration=%d\n", config.short_break_duration);
    fprintf(f, "long_break_duration=%d\n", config.long_break_duration);
    fprintf(f, "cycles_before_long_break=%d\n", config.cycles_before_long_break);

    fclose(f);
    return 1;
}

int save_history(int completed_pomodoros, const char *filename)
{
    FILE *f = fopen(filename, "a");
    if (!f)
        return 0;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(f, "%04d-%02d-%02d %02d:%02d - %d pomodoros\n",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            completed_pomodoros);

    fclose(f);
    return 1;
}
