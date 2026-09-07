#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("hey from fork program \n");
    int x= 100;
    int rc = fork();
    FILE *fd = fopen("./cpu-api/README.md", "w+" );
    if (rc == 0){
        // child
        char buf[1024];
        int fc = fwrite("hey man", 4,1, fd);
        int oc = fread(buf, 1, 1024, fd);
        assert(fc);
        assert(oc);
        printf("-------------child ------------------\n");
        printf("buf %s child \n", buf);
        printf("-------------child ------------------\n");
        x= 1;

    }
    else {
        // parent
        char buf[1024];
        int fc = fwrite("hey man", 4,1, fd);
        int oc = fread(buf, 1, 1024, fd);
        assert(fc);
        printf("-------------paretn ------------------\n");
        printf("buf %s parent \n", buf);
        printf("-------------paretn ------------------\n");
    }


}
