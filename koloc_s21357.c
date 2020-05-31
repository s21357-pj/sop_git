#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void my_sig(int sig) {
	printf("Otrzymałem SIGUSR2 od innego procesu\n");
	exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[])
{
	char line[1024];
	pid_t mojpid, x, myppid;
	mojpid = getpid();
    myppid = getppid();
    uid_t myuid, myeuid;
    myuid = getuid();
    myeuid = geteuid();
    gid_t gid, geid;
    gid = getgid();
    geid = getegid();
	printf("ID procesu: %u\n", mojpid);
    printf("ID procesu rodzica: %u\n", myppid);
	printf("ID rzeczywiste użytkownika: %u\n", myuid);
    printf("ID efektywne użytkownika: %u\n", myeuid);
    printf("ID rzeczywiste grupy: %u\n", gid);
    printf("ID efektywne grupy: %u\n", geid);
	x = fork();
	if (x == 0)
	{
		printf("Jestem procesem potomnym\n");
		printf("ID procesu: %u\n", getpid());
		printf("ID procesu: %u\n", getppid());
		sleep(5);
		kill(getppid(), SIGUSR2); 
		
	}
	else
	{
		printf("Jestem procesem macierzystym\n");
		printf("ID procesu: %u\n", mojpid);
		printf ("PID procesu potomnego: %d\n", (int) x);
		if (signal(SIGUSR2, my_sig) == SIG_ERR) {
			printf("Funkcja signal ma problem z SIGUSR2.");
		}	
		waitpid(x, NULL, 0);


	    sleep(15);
	    printf ("Press any key...");
	    scanf("%[^\n]", line);
	}
	return 0;
}
