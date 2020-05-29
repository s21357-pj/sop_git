#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

int main(int argc, char **argv)
{
	if (argc > 1 && argc <= 3)
    {
        printf("%s\n", argv[1]);
        printf("%s\n", argv[1]);
    }
    exit(EXIT_SUCCESS);
}
