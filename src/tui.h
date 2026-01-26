#ifndef TUI_H
#define TUI_H

void tui_init(void);
void tui_cleanup(void);
void tui_draw_timer(int seconds_left, int total_seconds, int paused, const char *label);
int tui_handle_input(void);

#endif
