#include "timer.h"
#include "tui.h"
#include "notifications.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>

void start_timer_tui(int seconds, PomodoroState state)
{
    int total = seconds;
    int paused = 0;

    while (seconds >= 0)
    {
        tui_draw_timer(seconds, total, paused, state);

        int ch = tui_handle_input();
        if (ch == 'p')
            paused = 1;
        else if (ch == 'r')
            paused = 0;
        else if (ch == 'q')
            break;

        if (!paused)
        {
            sleep(1);
            seconds--;
        }
        else
        {
            struct timespec ts = {0, 100000000};
            nanosleep(&ts, NULL);
        }
    }
}

void set_nonblocking(int enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // modo raw
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    }
    else
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

char check_input()
{
    fd_set set;
    struct timeval timeout = {0, 0};
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    int rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
    if (rv > 0)
    {
        char c;
        read(STDIN_FILENO, &c, 1);
        return c;
    }
    return 0;
}
