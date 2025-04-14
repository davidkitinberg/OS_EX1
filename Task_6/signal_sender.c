#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "signal_sender.h"


// Sends a single bit (0 or 1) as a signal to the given PID
void send_bit(pid_t pid, int bit) {
    int sig = (bit == 0) ? SIGUSR1 : SIGUSR2; // Choose SIGUSR1 for 0, SIGUSR2 for 1
    kill(pid, sig); // Send the signal to the receiver process
    usleep(500); // Small delay to let the receiver process it
}

int main() {
    pid_t receiver_pid; // PID of the receiving process
    int message; // The message to send (0–255)

    printf("Enter receiver PID: ");
    scanf("%d", &receiver_pid); // Read receiver's PID

    printf("Enter message (0-255): ");
    scanf("%d", &message); // Read the message to send

    // Validate message size bounds
    if (message < 0 || message > 255) {
        fprintf(stderr, "Message must be between 0 and 255\n");
        return 1;
    }

    // Send message bit by bit (starting from MSB)
    for (int i = 7; i >= 0; i--) 
    {
        int bit = (message >> i) & 1; // Extract the i-th bit
        send_bit(receiver_pid, bit); // Send the bit as a signal
    }

    return 0;
}
