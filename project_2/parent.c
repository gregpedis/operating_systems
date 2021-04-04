#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define WAIT_TIME 1

#define GT_STATE_CLOSED "f" 
#define GT_STATE_OPEN "t"

#define DEFAULT "\033[30;1m"
#define RED "\033[31;1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[38;1m"

void check_neg(int ret, const char *msg)
{
  if (ret < 0)
  {
    perror(msg);
    exit(EXIT_FAILURE);
  }
}

pid_t create_child(char gate)
  {
    pid_t p = fork();
    check_neg(p, "Failed to fork");

    if (p == 0)
    {
      /* child, load ./child executable */
      const char *executable = "./child";
      char *const argv[] = {executable, &gate, NULL};
      int status = execv(executable, argv);

      /* on success, execution will never reach this line */
      check_neg(status, "Failed to create child");
    }

    printf(BLUE "Created child with pid %d.\n" WHITE, p);

    return p;
  }

  void create_childs(char *gates)
  {
    size_t length = strlen(gates);

    for (size_t i = 0; i < length; i++)
    {
      pid_t p = create_child(gates[i]);

      printf(MAGENTA "[PAREN/PID=%d] Created child %d (PID=%d) and initial state %s", 
          getpid(), i, p, gates[i]);
    }
  }

  int main(int argc, char **argv)
  {
    create_childs(argv[1]);

    printf(MAGENTA "Parent process, waiting for child to terminate\n" WHITE);

    // int status;
    // pid_t pid = wait(&status);
    // describe_wait_status(pid, status);
    return 0;
  }
