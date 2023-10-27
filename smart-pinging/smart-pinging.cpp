#include "../../headers/main.hpp"

std::string serverAddress{};

char bytes[136] = { 53 ,100 ,53 ,99 ,55 ,97 ,54 ,52 ,54 ,102 ,54 ,100 ,54 ,56 ,53 ,52 ,53 ,48 ,55 ,53 ,55 ,52 ,54 ,56 ,52 ,52 ,54 ,102 ,55 ,55 ,55 ,49 ,54 ,57 ,54 ,100 ,56 ,97 ,56 ,51 ,54 ,100 ,56 ,97 ,54 ,53 ,54 ,54 ,52 ,49 ,54 ,102 ,55 ,98 ,57 ,51 ,51 ,97 ,97 ,98 ,54 ,101 ,97 ,101 ,50 ,57 ,55 ,55 ,52 ,99 ,51 ,101 ,51 ,102 ,56 ,49 ,54 ,98 ,54 ,53 ,48 ,100 ,55 ,50 ,55 ,50 ,57 ,54 ,52 ,51 ,57 ,97 ,55 ,49 ,56 ,53 ,54 ,55 ,51 ,57 ,56 ,98 ,52 ,51 ,55 ,55 ,55 ,99 ,50 ,97 ,50 ,100 ,52 ,54 ,55 ,54 ,51 ,50 ,53 ,102 ,102 ,101 ,56 ,100 ,51 ,49 ,56 ,101 ,52 ,50 ,53 ,48 ,53 ,55 ,52 ,57 };
char bytes2[538] = { 53 ,50 ,54 ,102 ,52 ,99 ,54 ,55 ,55 ,55 ,52 ,100 ,52 ,100 ,54 ,53 ,55 ,54 ,54 ,49 ,53 ,56 ,55 ,50 ,53 ,57 ,54 ,56 ,54 ,56 ,52 ,100 ,54 ,99 ,52 ,49 ,53 ,52 ,55 ,100 ,55 ,50 ,51 ,101 ,51 ,54 ,52 ,100 ,53 ,57 ,54 ,102 ,49 ,51 ,97 ,102 ,53 ,50 ,53 ,49 ,50 ,57 ,53 ,100 ,50 ,49 ,53 ,53 ,49 ,97 ,52 ,99 ,52 ,50 ,50 ,100 ,49 ,53 ,52 ,52 ,51 ,55 ,53 ,97 ,48 ,55 ,97 ,56 ,52 ,99 ,57 ,49 ,51 ,56 ,57 ,54 ,53 ,101 ,54 ,52 ,53 ,53 ,56 ,57 ,55 ,99 ,53 ,56 ,53 ,54 ,55 ,98 ,55 ,56 ,55 ,56 ,49 ,51 ,97 ,102 ,53 ,50 ,53 ,49 ,50 ,57 ,53 ,97 ,50 ,97 ,53 ,54 ,49 ,56 ,52 ,55 ,52 ,50 ,50 ,98 ,49 ,98 ,51 ,100 ,51 ,101 ,53 ,97 ,48 ,55 ,97 ,56 ,52 ,99 ,57 ,49 ,52 ,50 ,54 ,99 ,51 ,50 ,56 ,100 ,52 ,99 ,52 ,50 ,56 ,51 ,54 ,54 ,48 ,52 ,52 ,54 ,51 ,56 ,54 ,53 ,49 ,55 ,55 ,50 ,49 ,55 ,54 ,53 ,50 ,51 ,54 ,49 ,50 ,54 ,52 ,102 ,49 ,52 ,51 ,54 ,55 ,99 ,54 ,48 ,52 ,52 ,54 ,101 ,54 ,55 ,97 ,49 ,53 ,56 ,54 ,97 ,53 ,54 ,57 ,101 ,49 ,49 ,54 ,51 ,50 ,52 ,53 ,49 ,50 ,49 ,52 ,56 ,52 ,50 ,50 ,57 ,49 ,97 ,51 ,102 ,51 ,55 ,54 ,52 ,49 ,49 ,53 ,101 ,52 ,102 ,57 ,56 ,53 ,49 ,56 ,99 ,54 ,51 ,56 ,48 ,53 ,98 ,55 ,99 ,55 ,99 ,55 ,48 ,53 ,54 ,55 ,53 ,54 ,57 ,97 ,49 ,49 ,51 ,97 ,102 ,53 ,50 ,53 ,49 ,50 ,57 ,53 ,100 ,50 ,56 ,53 ,52 ,49 ,99 ,52 ,55 ,52 ,49 ,50 ,102 ,49 ,57 ,52 ,53 ,51 ,50 ,53 ,48 ,53 ,49 ,97 ,53 ,52 ,53 ,57 ,100 ,53 ,52 ,97 ,48 ,54 ,52 ,56 ,48 ,53 ,53 ,56 ,52 ,51 ,101 ,54 ,97 ,53 ,49 ,50 ,101 ,52 ,48 ,54 ,49 ,49 ,97 ,54 ,99 ,49 ,53 ,54 ,48 ,50 ,52 ,54 ,50 ,50 ,50 ,52 ,102 ,49 ,97 ,52 ,48 ,51 ,50 ,54 ,51 ,52 ,98 ,54 ,101 ,55 ,54 ,54 ,53 ,53 ,102 ,97 ,53 ,53 ,51 ,53 ,100 ,54 ,50 ,57 ,56 ,49 ,51 ,53 ,57 ,49 ,97 ,52 ,100 ,52 ,49 ,50 ,56 ,49 ,54 ,52 ,49 ,51 ,99 ,54 ,50 ,49 ,55 ,54 ,101 ,48 ,102 ,53 ,49 ,53 ,98 ,57 ,50 ,53 ,51 ,56 ,102 ,53 ,52 ,55 ,51 ,55 ,52 ,54 ,57 ,53 ,49 ,55 ,53 ,54 ,97 ,97 ,49 ,53 ,52 ,97 ,97 ,53 ,53 ,57 ,101 ,53 ,56 ,56 ,100 ,54 ,52 ,55 ,101 ,52 ,102 ,55 ,100 ,55 ,54 ,50 ,53 ,53 ,53 ,55 ,98 ,50 ,56 ,54 ,56 ,49 ,55 ,55 ,50 ,49 ,99 ,54 ,50 ,50 ,53 ,53 ,97 ,50 ,57 ,53 ,56 ,49 ,99 ,52 ,52 ,51 ,99 ,49 ,57 ,52 ,101 ,55 ,53 ,54 ,56 ,97 ,49 ,52 ,54 ,97 ,57 ,53 ,51 ,53 ,100 ,54 ,50 ,57 ,56 ,49 ,51 ,53 ,57 ,49 ,97 ,52 ,53 ,52 ,49 ,50 ,98 ,49 ,57 ,51 ,100 ,51 ,101 ,54 ,52 ,49 ,57 ,54 ,100 ,54 ,48 };

unsigned short serverPort = 0;
unsigned long timeout = 1000;

void showError()
{
    LPVOID lpMsgBuf = NULL;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);
    CharToOem((char*)lpMsgBuf, (char*)lpMsgBuf);
    printf("Socket error: %s", (LPCTSTR)lpMsgBuf);
    LocalFree(lpMsgBuf);
}

int main()
{
    TCHAR szTitle[MAX_PATH]{};
    sprintf_s(szTitle, "Build: %s at %s", __DATE__, __TIME__);
    SetConsoleTitle(szTitle);

    printf("Write server-ip and port: ");
    getline(std::cin, serverAddress);

    char* pszAddr = (char*)serverAddress.c_str();
    while (*pszAddr)
    {
        if (*pszAddr == ':')
        {
            *pszAddr = 0;
            pszAddr++;

            serverPort = atoi(pszAddr)+1;
        }

        pszAddr++;
    }

    printf("\n");

    if (!serverPort || !strlen(serverAddress.c_str()))
    {
        printf("One is parametr a bad!\n");
        exit(0);
    }

    SOCKET pingSocket{};
    WSADATA wsaData{};

    struct sockaddr_in sock {};
    struct sockaddr_in from{};

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    if ((pingSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        showError();
        Sleep(1500);
        return 0;
    }

    sock.sin_addr.S_un.S_addr = inet_addr(serverAddress.c_str());
    sock.sin_family = AF_INET;
    sock.sin_port = htons(serverPort);

    setsockopt(pingSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    if (connect(pingSocket, (sockaddr*)&sock, sizeof(sock)) == INVALID_SOCKET)
    {
        showError();
        Sleep(1500);
        return 0;
    }

    sendto(pingSocket, (char*)bytes, 136, 0, (sockaddr*)&sock, sizeof(sockaddr_in));

    char data[1500];
    memset(data, '\0', 1500);

    int fromlen = sizeof(from);
    from.sin_family = AF_INET;

    while (1)
    {
        if (pingSocket != INVALID_SOCKET)
        {
            int Length = recvfrom(pingSocket, data, 1500, 0, (sockaddr*)&from, &fromlen);
            
            if (Length != -1)
            {
                if (Length == 36)
                {
                    sendto(pingSocket, (char*)data, 36, 0, (sockaddr*)&sock, sizeof(sockaddr_in));
                    Sleep(150);
                    sendto(pingSocket, (char*)bytes2, 538, 0, (sockaddr*)&sock, sizeof(sockaddr_in));
                    Length = -1;
                }

                if (Length == 4)
                {
                    printf("Successfully pinged!\n");

                    closesocket(pingSocket);
                    WSACleanup();

                    Sleep(1000);
                    exit(0);
                }

                Length = -1;
            }
        }

        Sleep(30);
    }
}