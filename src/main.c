#include <stdio.h>
#include "pomodoro.h"

int main(void) {
    printf("Pomodoro C 🍅\n");

    int total_cycles = 4;
    run_pomodoro_cycle(total_cycles);
    
    return 0;
}