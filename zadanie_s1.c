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
	if (argc == 3)
    {
        if (argv[1] == "IGNORE") { signal(argv[2],SIG_IGN); }
        if (argv[1] == "USER") { signal(argv[2], my_sig); }
        if (argv[1] == "DEFAULT") { signal(argv[2], SIG_DFL); }
    }
    if (pause() < 0){
       perror("ERROR: sygnal nie powoduje zakonczenia procesu");
       exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
