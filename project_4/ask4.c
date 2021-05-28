#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>

#define DEFAULT "\033[30;1m"
#define RED "\033[31;1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[38;1m"

#define CHLD_MESSAGE_CURRENT "[Child=%d] %d * %d = %d"
#define CHLD_MESSAGE_EXITING_RESULT "[Child=%d] Finished my job. RESULT: %d."
#define CHLD_MESSAGE_EXITING "[Child=%d] Finished my job. I'm going home!"

#define PRNT_MESSAGE_INITIAL "[PARENT] Initiating factorial of %d with %d processes"
#define PRNT_MESSAGE_FINAL "[PARENT] All children exited, terminating as well"

#define WAIT_TIME 1
#define TRUE 1
#define FALSE 0

#define DEFAULT_HOST "lab4-server.dslab.os.grnetcloud.net"
#define DEFAULT_PORT 18080
#define DEFAULT_DEBUG FALSE

struct UserConfig
{
    char *host;
    int port;
    int is_debug;
};

struct UserConfig *alloc_default_user_config()
{
    struct UserConfig *config = (struct UserConfig *)malloc(sizeof(struct UserConfig));
    config->host = DEFAULT_HOST;
    config->port = DEFAULT_PORT;
    config->is_debug = DEFAULT_DEBUG;
    return config;
}

void do_something(int argc, const char **argv,void*location)
{

}


struct UserConfig *parse_args(int argc, const char **argv)
{
    struct UserConfig *config = alloc_default_user_config();
    optind = 1;
    int c;

    while (1)
    {
        int this_option_opt_ind = optind ? optind : 1;
        int options_index = 0;
        c = getopt(argc, argv, "");
        // c = getopt_long(argc, argv, "", long_options, &options_index);
        if (c == -1)
        {
            break;
        }

        printf(optarg);
    }
}

void free_user_config(struct UserConfig *config)
{
    free(config);
}

int main(int argc, char **argv)
{
    parse_args(argc, argv);
    return 0;
}
