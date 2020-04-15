#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "debug.h"

#define MAXLINE 256

int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0)
    {
        debug_error("pipe error");
        exit(-1);
    }
    if ((pid = fork()) < 0) 
    {
        debug_error("fork error");
        exit(-1);
    } 
    else if (pid > 0) 
    { /* 父进程 */
        close(fd[0]);
        write(fd[1], "pipe success\n", 12);
    }
    else { /* 子进程 */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);//把line中的数据写到标准输出中
    }

    exit(0);
}



