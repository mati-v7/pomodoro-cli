#include "stats.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

PomodoroStats load_stats(const char *filename)
{
    PomodoroStats stats = {0, 0, 0, "N/A"};

    FILE *f = fopen(filename, "r");
    if (!f)
        return stats;

    char line[128];
    time_t now = time(NULL);
    struct tm *today = localtime(&now);

    while (fgets(line, sizeof(line), f))
    {
        int y, m, d, hh, mm, p;
        if (sscanf(line,
                   "%d-%d-%d %d:%d - %d pomodoros",
                   &y, &m, &d, &hh, &mm, &p) == 6)
        {

            stats.total_sessions++;
            stats.total_pomodoros += p;

            strncpy(stats.last_session, line, sizeof(stats.last_session) - 1);

            if (y == today->tm_year + 1900 &&
                m == today->tm_mon + 1 &&
                d == today->tm_mday)
            {
                stats.today_pomodoros += p;
            }
        }
    }

    fclose(f);
    return stats;
}

void print_stats(PomodoroStats stats) {
    printf("\nStatistics\n");
    printf("────────────────────────\n");
    printf("Total sessions    : %d\n", stats.total_sessions);
    printf("Total pomodoros   : %d\n", stats.total_pomodoros);
    printf("Pomodoros today   : %d\n", stats.today_pomodoros);
    printf("Last session      : %s\n", stats.last_session);
}
