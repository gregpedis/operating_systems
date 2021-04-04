#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define WAIT_TIME 1

#define DEFAULT "\033[30;1m"
#define RED "\033[31;1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[38;1m"

 int main(int argc, char **argv)
  {
    char *v = argv[1];

    printf(YELLOW "Child process, i got created with value: %s\n" WHITE, argv[1]);

    return 0;
  }
