//
// Created by Jakub Górski on 02/08/2022.
//

#include <SERVER.h>

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;

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

    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); // set IP addr
    ADDRESS.sin_family = AF_INET; // set addr family
    ADDRESS.sin_port = htons(444); // set port

    sock_LISTEN = socket(AF_INET, SOCK_STREAM, 0);
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
    listen(sock_LISTEN, SOMAXCONN);

    // if connection found:
    for(;;){
        std::cout << "\n\tSERVER: Waiting for client to connect...";

        sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR *) &ADDRESS, &AddressSize);
        if (sock_CONNECTION){
            std::cout << "\n\tSERVER: Connection was found!";

            SUCCESSFUL = send(sock_CONNECTION, "You have been successfully connected to the server.", 46, 0);
        }
    }

    return 0;
}