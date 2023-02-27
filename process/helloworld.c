#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// function used to replace the code of a process
int main (int argc, char *argv[]){
    printf("Hello World\n");
    printf("Executing process number: %d\n", (int)getpid());
    exit(1);
}