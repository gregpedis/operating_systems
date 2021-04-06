// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>

#include "gatesapi.h"

struct gate_manager *g_manager;

void on_sigusr1()
{
  for (size_t i; i < g_manager->gates_count; i++)
  {
    kill(SIGUSR1, g_manager->gates[i]->p_id);
  }
}

void on_sigterm()
{
  for (size_t i; i < g_manager->gates_count; i++)
  {
    printf(GRAY"[PARENT/PID=%d] Waiting for %d childs to exit" WHITE "\n",
         getpid(), g_manager->gates_count -i); 

    kill(SIGTERM, g_manager->gates[i]->p_id);
    free((void *)&(g_manager->gates[i]));
  }

  free((void *)g_manager);
}

void on_sigchld()
{
  for (size_t i = 0; i <g_manager->gates_count; i++) 
  {
    int status;
    pid_t pid = waitpid(g_manager->gates[i]->p_id, &status, WNOHANG);
    if (pid == -1) {
      perror("waitpid failed");
    }
    else if (pid>0) {
   int status;
   pid_t pid = wait(&status);
   // describe_wait_status(pid, status);
    }
  }
}

void dispatch_signal(int signal) {

  switch (signal) {
    case SIGUSR1:
      on_sigusr1();
      break;
    case SIGTERM:
      on_sigterm();
      break;
    case SIGCHLD:
      on_sigchld();
      break;
    default:
      break;
  }
}

void now_we_wait()
{
  struct sigaction action;
  action.sa_handler = dispatch_signal;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGTERM, &action, NULL);
  sigaction(SIGCHLD, &action, NULL);

  while (1);
}

void create_child(struct gate_process *gate)
{
  printf("Forking");
  pid_t p = fork();
  check_neg(p, "Failed to fork");

  printf("Pid after fork: %d", p);

  if (p == 0)
  {
    int i_len = snprintf(NULL, 0, "%d", gate->i);
    printf("I_len: %d", i_len);

    char *i_str = malloc(i_len + 1);
    printf("I_str: %d", i_str);
    snprintf(i_str, i_len + 1, "%s", gate->i);

    char executable[8] = "./child";
    char gate_value[2] = { gate->initial_state, '\0'};
    printf("Executable %s", executable);
    printf("gate_value %s", gate_value);

    char *const argv[] = {executable, i_str, gate_value, NULL};
    int status = execv(executable, argv);

    /* on success, execution will never reach this line */
    check_neg(status, "Failed to create child");
  }

  printf("[PARENT]: Gate info: i: %d, state: %c\n", gate->i, gate->initial_state);

  printf(MAGENTA "[PARENT/PID=%d] Created child %d (PID=%d) and initial state '%c'" WHITE "\n",
         getpid(), gate->i, p, gate->initial_state);

  gate->p_id = p;
}

int main(int argc, char **argv)
{
  printf("SKATA");
  if (argc<2) {
    perror("Not enough arguments for parent process");
    exit(EXIT_FAILURE);
  }
  
  printf("Allocating");
  g_manager = gm_alloc();
  printf("Initializing");
  gm_init_manager(g_manager);
  printf("Parsing gates");
  gm_parse_gates_from_str(g_manager, argv[1]);

  for (size_t i = 0; i < g_manager->gates_count; i++)
  {
      create_child(g_manager->gates[i]);
  }

  now_we_wait();
  return 0;
}
