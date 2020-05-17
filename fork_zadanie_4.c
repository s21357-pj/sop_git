#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main ()
{
 int status, exit_status;
 pid_t pid = fork();
 if (pid < 0)
 printf("ERROR! Nie mozna utworzyc nowego procesu\n");
 if (pid == 0) //tutaj wejdzie tylko jako potomek
 {
 printf("Potomek (PID: %d) uspiony...\n", getpid());
 sleep(5);
 exit(0); //wyjscie z potomka
 }
 while (waitpid(pid, &status, WNOHANG) == 0) //tutaj tylko jako rodzic
 {
 printf("Czekam na zakonczenie potomka...\n");
 sleep(1);
 }
 exit_status = WEXITSTATUS(status); //wyciagniecie wartosci ze zwracanej przez waitpid
 printf("Potomek %d zakonczyl dzialanie zwracajac %d\n", pid, exit_status);
 return 0;
}