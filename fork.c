#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
int main(){
  int bob1 = 0;
  int pid = getpid();
  printf("%d about to create 2 child processes\n", pid);
  pid_t a, b;
  (a = fork()) && (b = fork());
  if (a == 0 || b == 0){
    int* bob = malloc(sizeof(int));
    int random = open("/dev/urandom", O_RDONLY);
    int joe = read(random, bob, sizeof(int));
    bob1 = (bob[0] % 5 + 4) % 5 + 1;
    free(bob);
    printf("%d %dsec\n", getpid(), bob1);
    sleep(bob1);
    printf("%d finished after %d second(s)\n", getpid(), bob1);
    return bob1;
  }
  else{
    int *status = malloc(sizeof(int));
    int child = wait(status);
    if (child == -1){
      err();
    }
    if (WIFEXITED(*status)){
    printf("Main Process %d is done. Child %d slept for %d sec\n", pid, child, WEXITSTATUS(*status));
    }
  }
}
