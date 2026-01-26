#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>

void format_time(int seconds, char *buffer)
{
    int minutes = seconds / 60;
    int remaining_seconds = seconds % 60;

    sprintf(buffer, "%02d:%02d", minutes, remaining_seconds);
}

void start_timer(int seconds)
{
    char time_buffer[6]; // "mm:ss"
    set_nonblocking(1);
    int paused = 0;

    while (seconds >= 0)
    {
        char c = check_input();
        if (c == 'p')
            paused = 1;
        else if (c == 'r')
            paused = 0;

        printf("\r⏱  %s %s\033[K", time_buffer, paused ? "(PAUSED)" : "");
        fflush(stdout);

        if (!paused)
        {
            format_time(seconds, time_buffer);
            printf("\r⏱  %s %s", time_buffer, paused ? "(PAUSED)" : "");
            fflush(stdout);
            sleep(1);
            seconds--;
        }
        else
        {
            printf("\r⏱  %s (PAUSED) ", time_buffer);
            fflush(stdout);
            struct timespec ts = {0, 100000000}; // 0.1s
            nanosleep(&ts, NULL);
        }
    }

    set_nonblocking(0);
    printf("\n");
    beep();
}

void beep(void)
{
    int result = system("which play > /dev/null 2>&1");

    if (result == 0)
    {
        system("play -nq -t alsa synth 0.2 sine 440");
    }
    else
    {
        // fallback: ASCII bell
        printf("\a");
        fflush(stdout);
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
