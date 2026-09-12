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
    // char *argv[] = {"/bin/ls", ".", NULL};
    // if (execlp("pwd", "pwd", NULL)) {
    // printf("broken exec call \n");
    //}
  } else {
printf("parent pid :%d \n", rc);
    waitpid(-1, &rc, WUNTRACED);
    printf("after waiting in parent : pid : %d  \n", rc);
    printf("%s\n", strerror(errno));
    //printf("waiting for my child (%d) ..... \n ", rc);
  }
}
