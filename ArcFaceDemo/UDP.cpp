#include"UDP.h"

UDPNetWork::UDPNetWork(const char* address_server, const char* address_receiver, int port) :netWorkAddress_Server(address_server), netWorkAddress_Receiver(address_receiver), netWorkPort(port)
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return;
	}

	serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (serSocket == INVALID_SOCKET)
	{
		printf("socket error !");
		return;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(netWorkPort);
	serAddr.sin_addr.S_un.S_addr = inet_addr(netWorkAddress_Server);
	if (bind(serSocket, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("bind error !");
		closesocket(serSocket);
		return;
	}
}

UDPNetWork::~UDPNetWork()
{
	closesocket(serSocket);
	WSACleanup();
}

void UDPNetWork::send(char* sendData)
{
	const char* data = sendData;
	sockaddr_in remoteAddr;
	remoteAddr.sin_family = AF_INET;
	remoteAddr.sin_port = htons(netWorkPort);
	remoteAddr.sin_addr.S_un.S_addr = inet_addr(netWorkAddress_Receiver);
	int nAddrLen = sizeof(remoteAddr);
	sendto(serSocket, sendData, strlen(sendData), 0, (sockaddr*)&remoteAddr, nAddrLen);
}