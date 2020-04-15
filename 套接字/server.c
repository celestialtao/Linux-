#include <sys/type.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>



/* socket
 * bind
 * listen
 * accept
 * send/recv
 */

#define SERVER_PORT 8888
#define BACKLOG     10


int  main(int argc, char **argv)
{
	int iSocketServer;
	struct sockaddr_in tSocketServerAddr;		
	struct sockaddr_in tSocketClientAddr;
	int iSocketClient;
	int iRet;
	int iAddrLen;

	int iRecvLen;
	unsigned char ucRecvBuf[1000];

	int iClientNum = -1;

	signal(SIGCHLD, SIG_IGN); /* 父进程处理僵死进程*/

	iSocketServer = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == iSocketServer)
	{
		printf("socket error!\n");
		return -1;
	}

	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);  /*主机字节序转为网络字节序, host to net, short */
	tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;  /* 电脑上的一个IP地址 */
	memset(tSocketServerAddr.sin_zero, 0, 8);
	
	iRet = bind(iSocketServer, (const struct sockaddr *)&tSocketServerAddr,
				sizeof(struct sockaddr ));

	if(-1 == iRet)
	{
		printf("bind error!\n");
		return -1;
	}

    iRet = list(iSocketServer, BACKLOG);

    while(1)
    {
    	iAddrLen = sizeof(struct sockaddr)
		iSocketClient = accept(iSocketServer, (struct sockaddr *)&tSocketServerAddr, &iAddrLen ))
		if(-1 != iSocketClient)
		{	
			iClientNum++;
			printf("Get connet from client %d : %s \n", iClientNum, inet_ntoa(tSocketClientAddr.sin_addr)); /* 将网络端IP转换成ASCII码输出 */
			if(!fork())
			{
				/* 子进程的源码 */
				while(1)
				{
					/*接收客户端发来的数据并显示 */
					iRecvLen = recv(iSocketClient, ucRecvBuf, 999, 0);
					if (iRecvLen <= 0)
					{
						close(iSocketClient);
						return -1;
					}
					else
					{
						printf("Get Message From Client %d: %s", iClientNum,ucRecvBuf);
					}
					
				}
				
				
			}
		}
    } 

	close(iSocketClient);
	return 0;
}
