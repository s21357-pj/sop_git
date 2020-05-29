#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

void my_sig(int sig) {
	printf("Dostalem signal\n");
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	if (argc == 2)
    {
        if (strcmp(argv[1], "IGNORE") == 0) { signal(SIGINT, SIG_IGN); }
        if (strcmp(argv[1], "USER") == 0) { signal(SIGINT, my_sig); }
        if (strcmp(argv[1], "DEFAULT") == 0) { signal(SIGINT, SIG_DFL); }

        if (pause() < 0)
        {
           perror("ERROR: sygnal nie powoduje zakonczenia procesu");
           exit(EXIT_FAILURE);
        }
    }
 exit(EXIT_SUCCESS);
}
