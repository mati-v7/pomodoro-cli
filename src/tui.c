#include "tui.h"
#include <ncurses.h>

void tui_init(void)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void tui_cleanup(void)
{
    endwin();
}

void tui_draw_timer(int seconds_left, int total_seconds, int paused, const char *label)
{
    clear();

    int minutes = seconds_left / 60;
    int seconds = seconds_left % 60;

    mvprintw(1, 2, "Pomodoro C TUI");
    mvprintw(3, 2, "State : %s", label);
    mvprintw(5, 2, "Time : %02d:%02d %s",
             minutes, seconds,
             paused ? "(PAUSED)" : "");

    int width = 30;
    int filled = (total_seconds - seconds_left) * width / total_seconds;

    mvprintw(7, 2, "[");
    for (int i = 0; i < width; i++)
    {
        addch(i < filled ? '#' : ' ');
    }
    addch(']');

    mvprintw(9, 2, "p: pause | r: resume | q: exit");

    refresh();
}

int tui_handle_input(void)
{
    int ch = getch();
    return ch;
}
