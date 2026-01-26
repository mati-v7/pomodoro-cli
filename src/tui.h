#ifndef TUI_H
#define TUI_H

typedef enum {
    STATE_WORK,
    STATE_SHORT_BREAK,
    STATE_LONG_BREAK,
    STATE_PAUSED
} PomodoroState;

void tui_init(void);
void tui_cleanup(void);
void tui_draw_timer(int seconds_left, int total_seconds, int paused, PomodoroState state);
int tui_handle_input(void);

#endif
