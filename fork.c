#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(){
  int pid = getpid();
  printf("%d about to create 2 child processes", pid);
  pid_t a, b;
  fork();
  (a = fork()) && (b = fork());
  if (a == 0 || b == 0){
    int* bob = malloc(sizeof(int));
    int random = open("/dev/urandom", O_RDONLY);
    int joe = read(random, bob, sizeof(int));
    int bob1 = bob;
    bob = bob % 5;
    printf("%d %dsec", getpid(), bob);
    sleep(bob);
    printf("%d finished after %d second(s)", getpid(), bob);
  }
  else{
    wait();
  }
}
