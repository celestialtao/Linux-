此用例注意实现通过共享内存完成进程间的通信
1.shmdata.h文件为读写数据定义了相同的数据结构
2.shmread.c创建共享内存，并读取其中的信息，另一个文件shmwrite.c向共享内存中写入数据

编译及运行过程：
gcc -o shmread.exe shmread.c  -lm
gcc -o shmread.exe shmread.c  -lm
打开两个终端分别运行
 ./shmread.exe
 ./shmwrite.exe