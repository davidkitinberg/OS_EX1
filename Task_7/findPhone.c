#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: findPhone <name>\n");
        exit(EXIT_FAILURE);
    }

    // Create pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // First child process (grep)
    pid_t pid1 = fork();
    if (pid1 == -1) // Validate fork
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid1 == 0) 
    {
        // Child 1: grep process
        close(pipefd[0]);  // Close unused read end
        
        // Redirect stdout to pipe -> grep's output goes into the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) 
        {
            perror("dup2 failed");
            exit(EXIT_FAILURE);
        }
        
        close(pipefd[1]);  // Close original write end
        
        // Execute grep
        execlp("grep", "grep", argv[1], "phonebook.txt", NULL);
        
        perror("exec grep failed"); // exec failed
        exit(EXIT_FAILURE);
    }

    // Second child process (awk)
    pid_t pid2 = fork();
    if (pid2 == -1) // Validate fork
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid2 == 0) 
    {
        // Child 2: awk process
        close(pipefd[1]);  // Close unused write end
        
        // Redirect stdin from pipe -> awk receives input from grep
        if (dup2(pipefd[0], STDIN_FILENO) == -1) 
        {
            perror("dup2 failed");
            exit(EXIT_FAILURE);
        }
        
        close(pipefd[0]);  // Close original read end
        
        // Execute awk -> extract the second column which is phone number
        execlp("awk", "awk", "-F,", "{print $2}", NULL);
        
        perror("exec awk failed"); // exec failed
        exit(EXIT_FAILURE);
    }

    // Parent process
    // Close both ends of the pipe in the parent
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both children to finish
    int status1, status2;
    if (waitpid(pid1, &status1, 0) == -1) 
    {
        perror("waitpid for grep (child 1)"); // Child 1
    }
    
    if (waitpid(pid2, &status2, 0) == -1) 
    {
        perror("waitpid for awk (child 2)"); // Child 2
    }


}