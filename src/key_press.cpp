#include "key_press.h"

#if defined(_WIN32) || defined(WIN32)
#include <conio.h>
#elif defined(__linux)
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#else
#error Platform not supported!
#endif

// Function to set the terminal into raw mode
void setTerminalRawMode(bool enable) {
#if defined(__linux)
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // Save old terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    }
#else
    (void)enable; // For compiler warning
    // TODO(odin): check if exists equivalent Windows functionality?
#endif
}

// Function to check if a key is pressed
bool keyHit() {
#if defined(_WIN32) || defined(WIN32)
    return (bool)_kbhit();
#elif defined(__linux)
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
#endif
}

// Function to get the pressed key
int getKey() {
#if defined(_WIN32) || defined(WIN32)
    return _getch();
#elif defined(__linux)
    return getchar();
#endif
}
