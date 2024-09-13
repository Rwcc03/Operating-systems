#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void runFile(char*argument, char*argv[]) {
    
    if(execvp(argument, argv)<0){
        printf ("Invalid Command\n");
    }

}

char** tokenize(char*input) {

    char* space = " \t\f\r\v\n"; //notes space char at the beginning
    char* token;
    char** tokens;

    //get space for tokens
    tokens = malloc(100*sizeof(char));

    //Set tokens to NULL
    for(int i = 0; i<100; i++) {
        tokens[i] = NULL;
    }

    int counter = 0;
    token = strtok(input, space);

    //Adds tokens to the list, increases counter for tokens
    while(token != NULL) {
        tokens[counter] = token;
        token = strtok(NULL, space);
        counter++;
    }

    return tokens;
}

int main() {
    char* input;
    //gets space
    input = malloc(100*sizeof(char));

    while(!feof(stdin)) {
        //User prompt
        printf("> ");

        //Gets input
        input = fgets(input, 100 * sizeof(char), stdin);

        //Tokenizes input
        char** tokenList = tokenize(input);
        int pid;

        pid = fork();

        if (pid == 0) {
            //Child
            //argc, argv
            runFile(tokenList[0], tokenList);
            exit(1);
        }
        else {
            //Parent
            wait(NULL);
            free(tokenList);
        }
    }

    return 0;
}