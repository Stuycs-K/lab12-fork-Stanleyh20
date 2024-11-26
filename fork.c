#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(){
  int pid = getpid();
  printf("%d about to create 2 child processes\n", pid);
  pid_t a, b;
  fork();
  (a = fork()) && (b = fork());
  if (a == 0){
    int* bob = malloc(sizeof(int));
    int random = open("/dev/urandom", O_RDONLY);
    int joe = read(random, bob, sizeof(int));
    int bob1 = bob[0] % 4 + 1;
    free(bob);
    printf("%d %dsec\n", getpid(), bob1);
    sleep(bob1);
    printf("%d finished after %d second(s)\n", getpid(), bob1);
  }
  else{
    wait(NULL);
  }
}
