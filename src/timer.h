#ifndef TIMER_H
#define TIMER_H

void start_timer(int seconds);
void format_time(int seconds, char *buffer);
void beep(void);
void set_nonblocking(int enable);
char check_input();
void start_timer_tui(int seconds, const char *label);

#endif
