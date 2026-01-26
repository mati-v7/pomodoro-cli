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
