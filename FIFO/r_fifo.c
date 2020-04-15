#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    char *fifoname = "/tmp/fifo";
    int fifofd, datafd;
    int bytes, ret;
    char buffer[BUFSIZE];

    if (argc != 2) {
        printf("please input a filename");
        exit(EXIT_FAILURE);
    }

    fifofd = open(fifoname, O_RDONLY);
    datafd = open(argv[1], O_WRONLY);
    if (fifofd < 0) {
        perror("open fifo error");
        exit(EXIT_FAILURE);
    }
    if (datafd < 0) {
        perror("open file error");
        exit(EXIT_FAILURE);
    }

    bytes = read(fifofd, buffer, BUFSIZE);
    while(bytes > 0) {
        ret = write(datafd, buffer, bytes);
        if (ret < 0) {
            perror("write file error");
            exit(EXIT_FAILURE);
        }
        bytes = read(fifofd, buffer, BUFSIZE);
    }
    close(datafd);
    close(fifofd);
    return 0;
}