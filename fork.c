#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int a = getpid();
  fork();
  if (a == getpid()){
    fork();
  }
}
