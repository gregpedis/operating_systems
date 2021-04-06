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
    gm_flip_gate(g_manager->gates[i]);
  }
}

void create_child(struct gate *gate)
{
  pid_t p = fork();
  check_neg(p, "Failed to fork");

  if (p == 0)
  {
    int i_len = snprintf(NULL, 0, "%d", gate->i);
    char *i_str = malloc(i_len + 1);
    snprintf(i_str, i_len + 1, "%d", gate->i);

    const char *executable = "./child";
    char *const argv[] = {executable, i_str, gate->initial_state, NULL};
    int status = execv(executable, argv);

    /* on success, execution will never reach this line */
    check_neg(status, "Failed to create child");
  }

  printf(MAGENTA "[PARENT/PID=%d] Created child %d (PID=%d) and initial state '%s'",
         getpid(), gate->i, p, gate->initial_state WHITE "\n");

  gate->p_id = p;
}

int main(int argc, char **argv)
{
  g_manager = gm_alloc();
  gm_init_manager(g_manager);
  gm_parse_gates_from_str(manager, argv[1]);

  for (size_t i = 0; i < manager.gates_count; i++)
  {
    create_child(manager.gates[i]);
  }

  // int status;
  // pid_t pid = wait(&status);
  // describe_wait_status(pid, status);
  return 0;
}
