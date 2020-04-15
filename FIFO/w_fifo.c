#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFSIZE 1024

int main(int argc, char *argv[]){
    int ret;
    int datafd, fifofd;
    int bytes;
    char buffer[BUFSIZE];
    const char *fifoname = "/tmp/fifo";

    if (argc != 2) {
        printf("please input filename\n");
        exit(EXIT_FAILURE);
    }

    if (access(fifoname, F_OK) < 0) {
        ret = mkfifo(fifoname, 0777);
        if (ret < 0) {
            perror("mkfifo error");
            exit(EXIT_FAILURE);
        }
    }
    fifofd = open(fifoname, O_WRONLY);
    datafd = open(argv[1], O_RDONLY);
    if (fifofd < 0) {
        perror("open fifo error");
        exit(EXIT_FAILURE);
    }
    if (datafd < 0) {
        perror("open file error");
        exit(EXIT_FAILURE);
    }

    bytes = read(datafd, buffer, BUFSIZE);
    while (bytes > 0) {
        ret = write(fifofd, buffer, bytes);
        if (ret < 0) {
            perror("write fifo error");
            exit(EXIT_FAILURE);
        }
        bytes = read(datafd, buffer, BUFSIZE);
    }
    close(fifofd);
    close(datafd);
    return 0;
}