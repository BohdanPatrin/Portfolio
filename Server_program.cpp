#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <Winsock2.h>
#include <random>
#include <cstdio>
#include <string>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")
#define SERVER_IP "127.0.0.1"
typedef int socklen_t;
const int PORT = 8888;
int valread;
char operation;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string input;
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock failed to initialize\n";
        return 1;
    }
    srand(time(NULL));

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Failed to create a socket\n";
        return -1;
    }


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);


    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Failed to bind a socket to a server address\n";
        return -1;
    }


    if (listen(server_fd, 1) < 0) {
        std::cerr << "Unable to start listening to the connection\n";
        return -1;
    }

    std::cout << "The server is up and running. Waiting for a connection...\n";
    std::ofstream MyFile("filename.txt");
    socklen_t addr_len = sizeof(client_addr);
    MyFile << "The server is up and running.";

    if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
        std::cerr << "Connection failed to accept\n";
        MyFile << "Connection failed to accept\n";
        return -1;
    }
    char buffer[1024] = { 0 };
    std::cout << "Connection established\n";
    MyFile << "Connection established\n";
    while (true) {
        char recvBuf[1024];
        int recvbuflen = 1024;
        int bytesReceived = recv(client_fd, recvBuf, sizeof(recvBuf), 0);
        if (bytesReceived == SOCKET_ERROR) {
            std::cerr << "Failed to receive a command from the client\n";
            MyFile << "Failed to receive a command from the client\n";
            closesocket(client_fd);
            closesocket(sockfd);
            WSACleanup();
            return 1;
        }
        if (bytesReceived > 0) {
            std::cout << "Command received" << std::endl;
                srand(time(NULL));
                int number = rand() % 9000 + 1000;
                std::cout << "A guessed number: " << number << std::endl;
                MyFile << "Command received.A guessed number:" << number << std::endl;
                std::stringstream ss;
                ss << number;
                std::string message = ss.str();
                send(client_fd, message.c_str(), message.length(), 0);
                std::getline(std::cin, input);
                if (input == "who") {
                    std::cout << SERVER_IP << std::endl;
                }
            }
        }
       
        struct sockaddr_in addr;
        socklen_t len = sizeof(addr);
        if (getsockname(sockfd, (struct sockaddr*)&addr, &len) == -1) {
            perror("getsockname");
            exit(EXIT_FAILURE);
        }
    
    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
