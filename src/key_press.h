#pragma once

// Helper functions for non-blocking keyboard input

void setTerminalRawMode(bool enable);
bool keyHit();
int getKey();
