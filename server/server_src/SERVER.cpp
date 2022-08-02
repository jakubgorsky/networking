//
// Created by Jakub Górski on 02/08/2022.
//

#include <SERVER.h>

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;
    bool exitted;
    char MESSAGE[1024];
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DLLVERSION = MAKEWORD(2,1);

    // Starting WinSock
    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

    // Creating socket structure
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    // Creating sockets
    SOCKET sock_LISTEN;
    SOCKET sock_CONNECTION;

    // Socket args
    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, 0);

    ADDRESS.sin_addr.s_addr = htons(INADDR_ANY); // set IP addr
    ADDRESS.sin_family = AF_INET; // set addr family
    ADDRESS.sin_port = htons(444); // set port

    sock_LISTEN = socket(AF_INET, SOCK_STREAM, 0);
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
    listen(sock_LISTEN, SOMAXCONN);

    // if connection found:
    std::cout << "\n\t[SERVER] Waiting for client to connect...";

    sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR *) &ADDRESS, &AddressSize);
    while (sock_CONNECTION > 0){
        SetConsoleTextAttribute(hconsole, 3);
        std::cout << "\n\t[SERVER] Connection was found!";
        send(sock_CONNECTION, "You have been successfully connected to the server.", 46, 0);
        SetConsoleTextAttribute(hconsole, 4);
        std::cout << "\n\t[CLIENT]";
        recv(sock_CONNECTION, MESSAGE, sizeof(MESSAGE), 0);
        std::cout << MESSAGE << ' ';
        if(*MESSAGE == '#'){
            exitted = true;
        }

        do {
            SetConsoleTextAttribute(hconsole, 3);
            std::cout << "\n\t[SERVER]" << ' ';
            std::cin.getline(MESSAGE, 1024, '\n');
            send(sock_CONNECTION, MESSAGE, sizeof(MESSAGE), 0);
            if(*MESSAGE == '#'){
                send(sock_CONNECTION, MESSAGE, sizeof(MESSAGE), 0);
                exitted = true;
            }

            SetConsoleTextAttribute(hconsole, 4);
            std::cout << "\n\t[CLIENT]" << ' ';
            recv(sock_CONNECTION, MESSAGE, sizeof(MESSAGE), 0);
            std::cout << MESSAGE;
            if(*MESSAGE == '#'){
                exitted = true;
            }
        } while (!exitted);

        SetConsoleTextAttribute(hconsole, 14);
        std::cout << "[SERVER] Connection with IP address " << inet_ntoa(ADDRESS.sin_addr) << " terminated.";
        exitted = false;
        closesocket(sock_CONNECTION);
    }
    return 0;
}