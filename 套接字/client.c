#include <sys/type.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

/* socket
 * connet
 * send/recv
 */

 
#define SERVER_PORT 8888

int main(int argc, char **argv)
{	
	int iSocketClient;
	struct sockaddr_in tSocketServerAddr;
	
	int iRet;
	unsigned char ucSendBuf[1000];
	int iSendLen;
	
	if(argc != 2)
	{
		printf("Usage : n \");
		printf(" %s <server_ip>\n", argv[0]);
		return -1;
	}
	
	iSocketClient = socket(AF_INET, SOCK_STREAM, 0);

	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);  /*主机字节序转为网络字节序, host to net, short */
	//tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;  /* 电脑上的一个IP地址 */
	if (0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr)
	{
		printf("invalid server_ip\n");
		return -1;
	}
	memset(tSocketServerAddr.sin_zero, 0, 8);

	iRet = connet (iSocketClient，( const struct sockaddr *)&tSocketServerAddr, 
					sizeof(struct sockaddr);
	if(-1 == iRet)
	{
		printf("connect error!\n")
	}

	while(1)
	{
		if(fgets(ucSendBuf, 999, stdin))
		{
			iSendLen = send(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0);
			if(iSendLen <= 0)
			{
			 	close(iSocketClient);
			 	return -1;
			}
		}
		
	}
	
	return 0;
}
