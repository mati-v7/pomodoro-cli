#include <stdio.h>
#include <stdlib.h>

void notify_desktop(const char *title, const char *message)
{
    char command[512];

    snprintf(
        command,
        sizeof(command),
        "notify-send \"%s\" \"%s\"",
        title,
        message);

    system(command);
}

void notify_sound(void)
{
    int result = system("which play > /dev/null 2>&1");

    if (result == 0)
    {
        system("play -nq -t alsa synth 0.2 sine 880");
    }
    else
    {
        // fallback terminal bell
        printf("\a");
        fflush(stdout);
    }
}

void notify_all(const char *title, const char *message)
{
    notify_sound();
    notify_desktop(title, message);
}