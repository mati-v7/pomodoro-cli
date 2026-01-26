#ifndef TIMER_H
#define TIMER_H

#include "tui.h"

void start_timer(int seconds);
void format_time(int seconds, char *buffer);
void beep(void);
void set_nonblocking(int enable);
char check_input();
void start_timer_tui(int seconds, PomodoroState state);

#endif
