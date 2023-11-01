#include "../../headers/main.hpp"
#include "../../headers/request.hpp"

sockaddr_in Request::returnSocketAddr(std::string address, unsigned short port)
{
	struct sockaddr_in sock{};

	sock.sin_addr.S_un.S_addr = inet_addr(address.c_str());
	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);

	return sock;
}

SOCKET Request::createSocketConnection(std::string address, unsigned short port, unsigned long timeout)
{
	WSADATA wsaData{};
	DWORD toggle = 1;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET SOCKET_ = socket(AF_INET, SOCK_STREAM, 0);

	if (SOCKET_ == INVALID_SOCKET)
		exit(1);

	if (setsockopt(SOCKET_, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) == INVALID_SOCKET)
		exit(2);

	sockaddr_in sock = returnSocketAddr(address, port);

	if (connect(SOCKET_, (sockaddr*)&sock, sizeof(sock)) == INVALID_SOCKET)
		exit(3);


	return SOCKET_;
}