#include <stdio.h>
#include <stdlib.h>
#include "pomodoro.h"
#include "cli.h"
#include "stats.h"
#include "storage.h"

#define CONFIG_FILE "config.txt"
#define HISTORY_FILE "history.txt"

int main(int argc, char *argv[])
{
    CliOptions cli = parse_cli(argc, argv);

    if (cli.show_help)
    {
        print_help();
        return 0;
    }

    if (cli.show_version)
    {
        print_version();
        return 0;
    }

    // default values
    PomodoroConfig config = {
        .work_duration = 1500,       // 25 min
        .short_break_duration = 300, // 5 min
        .long_break_duration = 900,  // 15 min
        .cycles_before_long_break = 4};

    if (cli.show_config)
    {
        print_config(config);
        return 0;
    }

    if (cli.reset_history)
    {
        reset_history(HISTORY_FILE);
        printf("History cleared\n");
        return 0;
    }

    int total_cycles = 4;

    load_config(&config, CONFIG_FILE);

    if (argc >= 2)
        config.work_duration = atoi(argv[1]);
    if (argc >= 3)
        config.short_break_duration = atoi(argv[2]);
    if (argc >= 4)
        config.long_break_duration = atoi(argv[3]);
    if (argc >= 5)
        config.cycles_before_long_break = atoi(argv[4]);

    save_config(config, CONFIG_FILE);

    if (cli.show_stats)
    {
        PomodoroStats stats = load_stats(HISTORY_FILE);
        print_stats(stats);
        return 0;
    }

    printf("Pomodoro C 🍅\n");
    printf("Press P to pause and R to resume the timer.\n");
    
    if (!cli.no_stats)
    {
        PomodoroStats stats = load_stats(HISTORY_FILE);
        print_stats(stats);
    }
    
    run_pomodoro_cycle(total_cycles, config);
    save_history(total_cycles, HISTORY_FILE);


    return 0;
}