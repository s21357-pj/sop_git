#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

int main(int argc, char **argv)
{
    printf("%f\n", argc);
    exit(EXIT_SUCCESS);
}
