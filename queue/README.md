#使用方法
cd queue/
make
./_queue

输出: 

int_handler set for SIGINT

go to sleep.

^C
SIGINT signal handler.

exit.

# 实现内容
通过signal()函数来为一个信号设置默认处理函数。一般情况下用户按下CTRL+C时，shell将会发出SIGINT信号，而此信号的默认处理函数是执行进程的退出代码，本示例中将SIGINT的响应函数设置为int_handler函数，打印输出相关信息。

