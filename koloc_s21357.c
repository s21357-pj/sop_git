#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char* argv[])
{
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
		kill(getppid(), SIGUSR2); 
		sleep(5);
	}
	else
	{
		printf ("PID procesu potomnego: %d\n", (int) x);
		sleep(5);
	    kill(x, SIGINT); 
		waitpid(x, NULL, 0);
		printf("[%u]: zadanie_s1 zakonczony\n", mojpid);
	}
	return 0;
}
