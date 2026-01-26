#include "export.h"
#include <stdio.h>
#include <stdlib.h>

static int parse_line(const char *line, PomodoroSession *s)
{
    return sscanf(line,
                  "%d-%d-%d %d:%d - %d pomodoros",
                  &s->year, &s->month, &s->day,
                  &s->hour, &s->minute,
                  &s->pomodoros) == 6;
}

int export_csv(const char *history_file, const char *output_file)
{
    FILE *in = fopen(history_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out)
        return 0;

    fprintf(out, "date,time,pomodoros\n");

    char line[128];
    PomodoroSession s;

    while (fgets(line, sizeof(line), in))
    {
        if (parse_line(line, &s))
        {
            fprintf(out,
                    "%04d-%02d-%02d,%02d:%02d,%d\n",
                    s.year, s.month, s.day,
                    s.hour, s.minute,
                    s.pomodoros);
        }
    }

    fclose(in);
    fclose(out);
    return 1;
}

int export_json(const char *history_file, const char *output_file)
{
    FILE *in = fopen(history_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out)
        return 0;

    fprintf(out, "[\n");

    char line[128];
    PomodoroSession s;
    int first = 1;

    while (fgets(line, sizeof(line), in))
    {
        if (parse_line(line, &s))
        {
            if (!first)
                fprintf(out, ",\n");
            first = 0;

            fprintf(out,
                    "  {\n"
                    "    \"date\": \"%04d-%02d-%02d\",\n"
                    "    \"time\": \"%02d:%02d\",\n"
                    "    \"pomodoros\": %d\n"
                    "  }",
                    s.year, s.month, s.day,
                    s.hour, s.minute,
                    s.pomodoros);
        }
    }

    fprintf(out, "\n]\n");

    fclose(in);
    fclose(out);
    return 1;
}
