#ifndef TIMER_H
#define TIMER_H

#include "tui.h"

void set_nonblocking(int enable);
char check_input();
void start_timer_tui(int seconds, PomodoroState state);

#endif
