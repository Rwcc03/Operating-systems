#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    //Question 1:
    //This sets the x value before forking
    int x = 100;

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        //This shows what the child's x value is
        printf("my x value is: %d\n", x);

        x--;
        //The child edits the x value 
        printf("my x value after changing is: %d\n", x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());

        //This shows what the parent's x value is set as after forking
        printf("my x value is: %d\n", x);
        x ++;
        //This shows what the parent's x value is set as after changing it
        printf("my x value after changing is: %d\n", x);
        //The parent and child have different copies of the same value
    }


    //Question 2:






    //Question 3:





}