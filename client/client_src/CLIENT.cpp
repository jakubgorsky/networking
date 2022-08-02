//
// Created by Jakub Górski on 02/08/2022.
//

#include <CLIENT.h>

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;

    DLLVERSION = MAKEWORD(2,1);

    // Starting WinSock
    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

    std::string RESPONSE, CONVERTER;
    char MESSAGE[200];

    // Creating socket structure
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    // Creating sockets
    SOCKET sock;

    // Socket args
    sock = socket(AF_INET, SOCK_STREAM, 0);

    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); // set IP addr
    ADDRESS.sin_family = AF_INET; // set addr family
    ADDRESS.sin_port = htons(444); // set port

    std::cout << "\n\tCLIENT: Do you want to connect to this SERVER? (Y/N)";
    std::cin >> RESPONSE;

    RESPONSE[0] = tolower(RESPONSE[0]);

    if (RESPONSE == "n"){
        std::cout << "\n\tCLIENT: Quitting...";
    }
    else if (RESPONSE == "y"){
        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

        SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), 0);

        CONVERTER = MESSAGE;

        std::cout << "\n\tSERVER MESSAGE:\n\n\t" << CONVERTER << "\n";
    }
    else {
        std::cout << "\n\tType Y (yes) to connect or N (no) to quit.";
    }

    std::cout << "\n\n\t";
    system("PAUSE");
    return 0;
}