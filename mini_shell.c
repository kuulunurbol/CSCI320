//Nurbol Kanatbek uulu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>    
#include <sys/wait.h> 

/* Tokenizer function and I used strtok() */
int tokenize(char *line, char *argv[], int max_args) {
    char *whitespace = " \t";
    int argc = 0;
    char *token = strtok(line, whitespace);

    while (token != NULL && argc < max_args - 1) {
        argv[argc++] = token;
        token = strtok(NULL, whitespace);
    }
    argv[argc] = NULL;  // NULL terminate
    return argc;
}


int main() {
    char text_line[1000];
    char *argv[1000];

    while (1) {
        printf("mini_shell> ");

        if (fgets(text_line, sizeof(text_line), stdin) == NULL) {
            printf("\n");
            break;
        }

        /* Remove trailing newline */
        text_line[strcspn(text_line, "\n")] = 0;

        /* Tokenize input */
        int argc = tokenize(text_line, argv, 1000);
        if (argc == 0) continue;  // blank line, skip

        /* Fork & exec */
        int pid = fork();
        if (pid == 0) { // Child process
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        } else { // parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}
