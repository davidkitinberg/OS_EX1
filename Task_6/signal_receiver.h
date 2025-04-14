#ifndef SIGNAL_RECEIVER_H
#define SIGNAL_RECEIVER_H

#include <signal.h>

// Signal handler for SIGUSR1 and SIGUSR2
void handle_sigusr(int signum);

#endif
