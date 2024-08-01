#pragma once

// Helper functions for non-blocking keyboard input

void setRawMode(bool enable);
bool kbhit();
int getch();
