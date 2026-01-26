#include "cli.h"
#include <stdio.h>
#include <string.h>

CliOptions parse_cli(int argc, char *argv[])
{
    CliOptions opts = {0};

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
            opts.show_help = 1;
        else if (strcmp(argv[i], "--stats") == 0)
            opts.show_stats = 1;
        else if (strcmp(argv[i], "--config") == 0)
            opts.show_config = 1;
        else if (strcmp(argv[i], "--reset-history") == 0)
            opts.reset_history = 1;
        else if (strcmp(argv[i], "--no-stats") == 0)
            opts.no_stats = 1;
        else if (strcmp(argv[i], "--version") == 0)
            opts.show_version = 1;
        else if (strcmp(argv[i], "--export") == 0 && i + 1 < argc)
        {
            strncpy(opts.export_format, argv[++i], sizeof(opts.export_format) - 1);
        }
    }

    return opts;
}

void print_help(void)
{
    printf("Pomodoro C 🍅\n\n");
    printf("Usage:\n");
    printf("  pomodoro [options]\n\n");
    printf("Options:\n");
    printf("  --help            Show this help message\n");
    printf("  --stats           Show statistics and exit\n");
    printf("  --config          Show current configuration\n");
    printf("  --reset-history   Clear history\n");
    printf("  --no-stats        Do not show statistics on start\n");
    printf("  --version         Show version\n");
}

void print_version(void)
{
    printf("Pomodoro C v1.2.0\n");
}
