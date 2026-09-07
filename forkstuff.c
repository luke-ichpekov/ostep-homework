#include <_stdio.h>
#include <assert.h>
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
  if (rc == 0) {
    // child
    printf("hello\n");
    write(fd, writeBuf, strlen(writeBuf));
  } else {
    // parent
    lseek(fd, 0, SEEK_SET);
    int ret = read(fd, readBuf, strlen(writeBuf));
    while (strcmp(readBuf, "ready") != 0) {
      sleep(1);
      printf("waiting...\n");
      lseek(fd, 0, SEEK_SET);
      int ret = read(fd, readBuf, strlen(writeBuf));
      printf("readbuf : %s \n ", readBuf);
    }
    printf("goodbye\n");
    fclose(fopen("./text.txt", "w"));
  }
}
