// signal_receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "signal_receiver.h"


// Global variables used in the signal handler
volatile sig_atomic_t bit_count = 0; // Counts the number of bits received (up to 8)
volatile sig_atomic_t message = 0;   // Stores the reconstructed 8-bit number

// Signal handler for SIGUSR1 and SIGUSR2
void handle_sigusr(int signum) {
    if (signum == SIGUSR1) {
        message <<= 1;  // Append a 0 bit to the message by shifting left
    } else if (signum == SIGUSR2) {
        message <<= 1;  // Append a 1 bit to the message by shifting left and OR'ing with 1
        message |= 1;
    }

    bit_count++;  // Increase bit counter

    // If 8 bits have been received, print the message
    if (bit_count == 8) {
        printf("Received %d\n", message);
        fflush(stdout); // Make sure the output is flushed immediately
        bit_count = 0; // Reset for next message
        message = 0; // Reset current message
    }
}

int main() {
    // Print the process ID so sender knows where to send signals
    printf("My PID is %d\n", getpid());
    fflush(stdout); // Ensure that we output our stream first

    // Set up the signal handler
    struct sigaction act;
    act.sa_handler = handle_sigusr; // We set our custom handler function for the signal
    sigemptyset(&act.sa_mask); // Initialize an empty signal set (no signals are blocked initially)
    // Add SIGUSR1 and SIGUSR2 to the mask to prevent signal interruption
    sigaddset(&act.sa_mask, SIGUSR1);
    sigaddset(&act.sa_mask, SIGUSR2);
    act.sa_flags = SA_RESTART; // Automatically restart any interrupted system calls like pause() (we added only this flag)

    // Assign signal handlers for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    // Infinite loop in order to wait for signals (each signal will trigger the handler)
    while (1) {
        pause(); // Sleep until a signal is received
    }

    return 0;
}

