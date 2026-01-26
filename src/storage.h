#ifndef STORAGE_H
#define STORAGE_H

#include "pomodoro.h"

int load_config(PomodoroConfig *config, const char *filename);
int save_config(PomodoroConfig config, const char *filename);
int save_history(int completed_pomodoros, const char *filename);
void print_config(PomodoroConfig config);
int reset_history(const char *filename);

#endif
