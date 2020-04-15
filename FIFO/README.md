# 使用方法
cd FIFO/

make
## 打开两个终端分别运行
./w_fifo test.txt

./r_fifo result.txt

输出：完成test文本内容拷贝到result中

# 实现内容
通过FIFO方式实现非亲属关系进程的通信，在一个进程中写入数据到FIFO，在另进程中将该数据写到另外的文本中，实现文件拷贝

