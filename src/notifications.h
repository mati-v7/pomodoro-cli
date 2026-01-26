#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

void notify_desktop(const char *title, const char *message);
void notify_sound(void);
void notify_all(const char *title, const char *message);

#endif
