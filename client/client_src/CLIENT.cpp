//
// Created by Jakub Górski on 02/08/2022.
//

#include <CLIENT.h>
#include "IP_VALIDATOR.h"

int main(){
    long SUCCESSFUL;
    WSAData WinSockData;
    bool exitted;
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD DLLVERSION;
    IP_VALIDATOR IPV;

    DLLVERSION = MAKEWORD(2,1);

    // Starting WinSock
    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

    std::string RESPONSE, CONVERTER;
    char MESSAGE[1024];

    // Creating socket structure
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    // Creating sockets
    SOCKET sock;

    // Socket args
    sock = socket(AF_INET, SOCK_STREAM, 0);

    std::string addr;
    std::cout << "\n\t[CLIENT] Provide IP Address:\n";
    std::cin >> addr;

    while (!IPV.validateIP(addr)){
        std::cout << "\n\t[CLIENT] Provided IP Address not valid!\n\tIP Address should have a form of 0.0.0.0\n";
        std::cin >> addr;
    }

    ADDRESS.sin_addr.s_addr = inet_addr(addr.c_str()); // set IP addr
    ADDRESS.sin_family = AF_INET; // set addr family
    ADDRESS.sin_port = htons(444); // set port

    std::cout << "\n\t[CLIENT] Do you want to connect to remote host at " << inet_ntoa(ADDRESS.sin_addr) << "? (Y/N)\n";
    std::cin >> RESPONSE;

    RESPONSE[0] = tolower(RESPONSE[0]);

    if (RESPONSE == "n"){
        std::cout << "\n\t[CLIENT] Quitting...";
    }
    else if (RESPONSE == "y"){
        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

        SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), 0);

        CONVERTER = MESSAGE;

        SetConsoleTextAttribute(hconsole, 4);
        std::cout << "\n\t[SERVER MESSAGE]\n\n\t" << CONVERTER << "\n";
        do{
            SetConsoleTextAttribute(hconsole, 3);
            std::cout << "\n\t[CLIENT]" << ' ';
            std::cin.getline(MESSAGE, 1024, '\n');
            send(sock, MESSAGE, sizeof(MESSAGE), 0);
            if(*MESSAGE == '#'){
                send(sock, MESSAGE, sizeof(MESSAGE), 0);
                exitted = true;
            }

            SetConsoleTextAttribute(hconsole, 4);
            std::cout << "\n\t[SERVER]" << ' ';
            recv(sock, MESSAGE, sizeof(MESSAGE), 0);
            std::cout << MESSAGE;
            if(*MESSAGE == '#'){
                exitted = true;
            }
        } while (!exitted);

    }
    else {
        std::cout << "\n\tType Y (yes) to connect or N (no) to quit.\n";
    }

    std::cout << "\n\n\t";
    system("PAUSE");
    return 0;
}