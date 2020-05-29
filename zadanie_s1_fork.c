#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char* argv[])
{
	pid_t mojpid, x;
	mojpid = getpid();
	printf("[%u]: Run zadanie_s1\n", mojpid);
	x = fork();
	if (x == 0)
	{
		if (execl("/home/PJWSTK/s21357/SOP_C/sop_git/zadanie_s1", "zadanie_s1", "IGNORE", NULL) == -1)
		{
			printf("Uruchomienie nie powiodlo sie\n");
		}				
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
