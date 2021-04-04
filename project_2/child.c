#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define WAIT_TIME 1

#define GT_MESSAGE_OPEN "The gates are open!"
#define GT_MESSAGE_CLOSED "The gates are closed!"

#define DEFAULT "\033[30;1m"
#define RED "\033[31;1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[38;1m"


void print_initial_message(char state)
{
  if (state =='f')
  {
    printf(RED "ID=" GT_MESSAGE_CLOSED WHITE, getpid());
  }
  else if (state=='t')
  {
    printf(GREEN GT_MESSAGE_OPEN WHITE, getpid());
  }
  else
  {
    perror("This is not a valid state");
    exit(-1);
  }
}

 int main(int argc, char **argv)
  {
    char v = argv[1];

    printf(YELLOW "Child process, i got created with value: %s\n" WHITE, argv[1]);

    return 0;
  }
