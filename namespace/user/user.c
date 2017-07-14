/* demo_userns.c

   Copyright 2013, Michael Kerrisk
   Licensed under GNU General Public License v2 or later

   Demonstrate the use of the clone() CLONE_NEWUSER flag.

   Link with "-lcap" and make sure that the "libcap-devel" (or
   similar) package is installed on the system.
*/
#define _GNU_SOURCE
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

static int                      /* Startup function for cloned child */
childFunc(void *arg)
{
   

    for (;;) {
        printf("eUID = %ld;  eGID = %ld;  ",
                (long) geteuid(), (long) getegid());

        if (arg == NULL)
            break;

        sleep(5);
    }

    return 0;
}

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];    /* Space for child's stack */

int
main(int argc, char *argv[])
{
    pid_t pid;

    /* Create child; child commences execution in childFunc() */

    pid = clone(childFunc, child_stack + STACK_SIZE,CLONE_NEWUSER | SIGCHLD, NULL);
    if (pid == -1)
        errExit("clone");

    /* Parent falls through to here.  Wait for child. */

    if (waitpid(pid, NULL, 0) == -1)
        errExit("waitpid");

    exit(EXIT_SUCCESS);
}
