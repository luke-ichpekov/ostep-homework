#include <_stdio.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int x = 100;
  int fd = open("./text.txt", O_RDWR | O_CREAT, S_IRWXU);
  int rc = fork();
  char writeBuf[25] = "ready";
  char readBuf[25] = "";
  lseek(fd, 0, SEEK_SET);

printf("main pid :%d \n", getpid());
  if (rc == 0) {
    // child
    printf("hello from child\n");
    pid_t rt = wait(&rc);
    printf("after waiting in child : pid : %d  \n", rt);
    printf("%s\n", strerror(errno));
    // char *argv[] = {"/bin/ls", ".", NULL};
    // if (execlp("pwd", "pwd", NULL)) {
    // printf("broken exec call \n");
    //}
  } else {
printf("parent pid :%d \n", rc);
    //printf("waiting for my child (%d) ..... \n ", rc);
  }
}
