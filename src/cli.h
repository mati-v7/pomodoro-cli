#ifndef CLI_H
#define CLI_H

typedef struct {
    int show_help;
    int show_stats;
    int show_config;
    int reset_history;
    int no_stats;
    int show_version;
    char export_format[8];
} CliOptions;

CliOptions parse_cli(int argc, char *argv[]);
void print_help(void);
void print_version(void);

#endif
