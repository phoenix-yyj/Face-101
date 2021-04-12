#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

class UDPNetWork 
{
public:
	//构造函数
	UDPNetWork(const char* address_server,const char* address_receiver, int port);
	//析构函数
	~UDPNetWork();
	//sendto
	void send(char *sendData);
private:
	SOCKET serSocket;
	const char* netWorkAddress_Server;
	const char* netWorkAddress_Receiver;
	int netWorkPort;
};