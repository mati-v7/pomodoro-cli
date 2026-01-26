#include "tui.h"
#include <ncurses.h>

void tui_init(void)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    if (has_colors())
    {
        start_color();
        use_default_colors();

        init_pair(1, COLOR_RED, -1);    // WORK
        init_pair(2, COLOR_GREEN, -1);  // BREAK
        init_pair(3, COLOR_YELLOW, -1); // PAUSED
        init_pair(4, COLOR_CYAN, -1);   // Títulos
    }
}

void tui_cleanup(void)
{
    endwin();
}

void tui_draw_timer(int seconds_left, int total_seconds, int paused, PomodoroState state)
{
    clear();

    int minutes = seconds_left / 60;
    int seconds = seconds_left % 60;

    attron(COLOR_PAIR(4));
    mvprintw(1, 2, "Pomodoro");
    attroff(COLOR_PAIR(4));

    int color = COLOR_PAIR(1);
    const char *label = "WORK";

    if (state == STATE_SHORT_BREAK || state == STATE_LONG_BREAK) {
        color = COLOR_PAIR(2);
        label = "BREAK";
    }

    if (paused) {
        color = COLOR_PAIR(3);
        label = "PAUSED";
    }

    attron(color | A_BOLD);
    mvprintw(3, 2, "State: %s", label);
    attroff(color | A_BOLD);

    mvprintw(5, 2, "Time: %02d:%02d", minutes, seconds);

    // Barra de progreso
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
