#include "key_press.h"

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Function to set the terminal into raw mode
void setRawMode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // Save old terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    }
}

// Function to check if a key is pressed
bool kbhit() {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}

// Function to get the pressed key
int getch() {
    return getchar();
}
