// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>

#include "gatesapi.h"

struct gate_context *g_context;

void print_identity_message(*g_context)
{
  if (g_context->state == GT_STATE_CLOSED)
  {
    printf(RED GT_MESSAGE_CLOSED WHITE "\n", g_context->i, getpid());
  }
  else if (g_context->state == GT_STATE_OPEN)
  {
    printf(GREEN GT_MESSAGE_OPEN WHITE "\n", g_context->I, getpid());
  }
  else
  {
    perror("This is not a valid state");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    perror("Not enough arguments for child process.");
    exit(EXIT_FAILURE)
  }

  char s = argv[2][0];
  int i;
  sscanf(argv[1], "%d", &i);

  g_context = gc_alloc();
  gc_init_context(g_context);
  gc_parse_gate_from_args(g_context, i, s);

  print_identity_message(*g_context);

  return 0;
}
