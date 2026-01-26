#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "notifications.h"
#include "pomodoro.h"

static PomodoroConfig cfg;
static time_t last_notification = 0;

static int can_notify(void)
{
    time_t now = time(NULL);
    if (difftime(now, last_notification) < cfg.throttle_seconds)
        return 0;

    last_notification = now;
    return 1;
}

void notify_desktop(const char *title, const char *message)
{
    char command[512];

    snprintf(
        command,
        sizeof(command),
        "notify-send --app-name=Podomoro \"%s\" \"%s\"",
        title,
        message);

    system(command);
}

void notify_sound(const char *sound_cmd)
{
    int has_play = system("which play > /dev/null 2>&1") == 0;

    if (has_play)
        system(sound_cmd);
    else
        printf("\a");
}

void notifications_init(PomodoroConfig config)
{
    cfg = config;
}

void notify_event(NotificationEvent event)
{
    if (!can_notify())
        return;

    const char *title = "";
    const char *message = "";
    const char *sound = "";

    switch (event)
    {
    case EVENT_WORK_DONE:
        title = "Pomodoro completed";
        message = "Time to rest";
        sound = "play -nq -t alsa synth 0.3 sine 880";
        break;

    case EVENT_SHORT_BREAK_DONE:
        title = "Short break finished";
        message = "Back to work";
        sound = "play -nq -t alsa synth 0.2 sine 660";
        break;

    case EVENT_LONG_BREAK_DONE:
        title = "Long break finished";
        message = "New Pomodoro cycle";
        sound = "play -nq -t alsa synth 0.4 sine 520";
        break;

    case EVENT_POMODORO_CYCLE_DONE:
        title = "Cycle completed";
        message = "Excellent work today";
        sound = "play -nq -t alsa synth 0.5 sine 440";
        break;
    }

    if (cfg.enable_sound)
        notify_sound(sound);

    if (cfg.enable_desktop)
        notify_desktop(title, message);
}
