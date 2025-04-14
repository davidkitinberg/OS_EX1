#ifndef SIGNAL_SENDER_H
#define SIGNAL_SENDER_H

#include <sys/types.h>

// Helper function that sends a single bit (0 or 1) to a given process
void send_bit(pid_t pid, int bit);

#endif
