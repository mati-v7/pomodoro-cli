#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "pomodoro.h"

typedef enum
{
    EVENT_WORK_DONE,
    EVENT_SHORT_BREAK_DONE,
    EVENT_LONG_BREAK_DONE,
    EVENT_POMODORO_CYCLE_DONE
} NotificationEvent;

typedef struct
{
    int enable_sound;
    int enable_desktop;
    int throttle_seconds;
} NotificationConfig;

void notifications_init(PomodoroConfig config);
void notify_event(NotificationEvent event);

void notify_desktop(const char *title, const char *message);
void notify_sound(const char *sound_cmd);

#endif
