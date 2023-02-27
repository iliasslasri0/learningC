#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child_function(int child_number);
void father_function();

int  main (int argc, char *argv[]) {
  int nb_of_processes, i_child, pid_child;

  /* Check that one parameter was provided */
  if (argc != 2) {
    printf(" Wrong usage, expected : %s number_of_processes ! \n", argv[0]);
    exit(2);
  }

  nb_of_processes = atoi (argv [1]);  /* conversion ascii -> integer */

  /* ----------------------------------------
  *  creation of children processes
  * ----------------------------------------
  */
  for ( i_child =1; i_child <= nb_of_processes  ; i_child++ ) {
    pid_child = fork();
    switch (pid_child) {
      case 0 :
      child_function(i_child);
      break;
      case -1 :
      perror("Fork just failed !!!");
      exit(33);  /* exit in case an error occured */
    }
  }
  father_function();
  return 0;

}

void child_function(int child_number)
{
  printf("executing proces number= %d - parent pid:%d \n",(int)getpid(), (int)getppid() );
  printf("going to wait...\n");
  sleep(2*child_number);
  int div_zero = 1/(1-child_number) ; // to see the changement in the register state
  exit(child_number);
}

void father_function()
{
  int state;
  int ret=0;
   while(ret!=-1)
  {
    ret = wait (&state);
    if(ret!=-1)
      printf("Child finished its exectuion, pid: %d,\nIts state was : %04x\n",
	     ret,state);
  }

}