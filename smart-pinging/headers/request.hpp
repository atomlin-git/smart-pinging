#pragma once


class Request
{
	public:
		static sockaddr_in returnSocketAddr(std::string address, unsigned short port);
		static SOCKET createSocketConnection(std::string address, unsigned short port, unsigned long timeout);
};