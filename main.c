#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
  printf("I will fork\n");
  int pid1;
  int pid2;
  pid1 = fork();
  srand(time(NULL));
  if (pid1){
    pid2 = fork();
    srand(time(NULL));
  }
  if (pid1 && pid2){
    int status;
    int child_pid = wait(&status);
    int time = WEXITSTATUS(status);
    printf("Child pid: %d\t Time Asleep: %d\n", child_pid, time);
    child_pid = wait(&status);
    time = WEXITSTATUS(status);
    printf("Child pid: %d\t Time Asleep: %d\n", child_pid, time);
    printf("Parent is done\n");
  }
  else{
    printf("Child pid: %d\n", getpid());
    int sleep_time = rand() % 4 + 2;
    sleep(sleep_time);
    printf("Child is done\n");
    return sleep_time;
  }
}