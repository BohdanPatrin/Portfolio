#include <iostream>
#include <string>
#include <sstream>
#include <WS2tcpip.h>
#include <fstream>
#include <WinSock2.h> // For Windows socket functions
#pragma comment(lib, "Ws2_32.lib") // Connect the required library

#define PORT 8888
#define SERVER_IP "127.0.0.1"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    WSADATA wsa;
    SOCKET client_fd;
    struct sockaddr_in server_addr = { 0 };
    char buffer[1024];
    int message1 = 0;
    char operation;
    int valread, number, guess, correct_cyfras;
    string numberguess;
    const int ARRAY_LENGTH = 4;
    // Initializing the Windows socket library
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "Windows sockets failed to initialize\n";
        return -1;
    }

    // Creating a socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cerr << "Failed to create a socket\n";
        WSACleanup(); // Ending work with Windows sockets
        return -1;
    }

    // Setting up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);


    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        cerr << "Failed to resolve server IP address\n";
        closesocket(client_fd); // Closing a socket
        WSACleanup(); // Ending work with Windows sockets
        return -1;
    }

    // Connecting to the server
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cerr << "Unable to connect to the server\n";
        closesocket(client_fd); // Closing a socket
        WSACleanup(); // Ending work with Windows sockets
        return -1;
    }

    cout << "Connected to the server\n";
    ofstream MyFile("filename.txt");
    while (true) {
        cout << "Enter the command( s - start the game; e - end the game):" << endl;
        cin >> operation;
        if (operation == 'e') {
            MyFile << "The session is over.\n";
            closesocket(client_fd);
            WSACleanup();
            break;
        }
        else if (operation == 's') {
            const char* message1 = "start";
            send(client_fd, message1, strlen (message1), 0);
            // Getting the specified number from the server
            valread = recv(client_fd, buffer, 1024, 0);
            string message(buffer, valread);
            stringstream ss(message);
            ss >> number;
            MyFile << "A guessed number:" << number << endl;
            while (true) {
                cout << "How will we set the number (input - manual input, generate - number generation)?" << endl;
                cin >> numberguess;
                if (numberguess == "input") {
                    while (true) {
                        cout << "Enter a four-digit number:  ";
                        cin >> guess;
                        MyFile << "The number entered:" << guess << endl;
                        if (guess >= 1000 && guess <= 9999) {
                            if (number == guess) {
                                MyFile << "The number is guessed\n";
                                cout << "You guessed the number. Would you like to try again?" << endl;
                                break;
                            }
                            else {
                                int correct_cyfras = 0;
                                int th = number / 1000;
                                int hnd = (number / 100) % 10;
                                int tns = (number / 10) % 10;
                                int ons = number % 10;
                                int gth = guess / 1000;
                                int ghnd = (guess / 100) % 10;
                                int gtns = (guess / 10) % 10;
                                int gons = guess % 10;
                                if (th == gth) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (hnd == ghnd) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (tns == gtns) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (ons == gons) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                cout << "The number of correct digits:" << correct_cyfras << endl;
                                MyFile << "The number of correct digits:"<< correct_cyfras << endl;
                                cout << "Continue the game (c) or end the game (e)?" << endl;
                                cin >> operation;
                                if (operation == 'c') {
                                }
                                else if (operation == 'e') {
                                    break;
                                }
                            }
                        }
                        else {
                            cout << "Invalid number. Please try again." << endl;
                        }
                    }
                    break;
                }
                else if (numberguess == "generate") {
                    srand(time(NULL));
                    int guess = rand() % 9000 + 1000;
                    while (true) {
                        if (guess >= 1000 && guess <= 9999) {
                            cout << guess << endl;
                            MyFile << "The number entered:" << guess << endl;
                            if (number == guess) {
                                MyFile << "The number is guessed\n";
                                cout << "You guessed the number. Would you like to try again?" << endl;
                                break;
                            }
                            else {
                                int correct_cyfras = 0;
                                int th = number / 1000;
                                int hnd = (number / 100) % 10;
                                int tns = (number / 10) % 10;
                                int ons = number % 10;
                                int gth = guess / 1000;
                                int ghnd = (guess / 100) % 10;
                                int gtns = (guess / 10) % 10;
                                int gons = guess % 10;
                                if (th == gth) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (hnd == ghnd) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (tns == gtns) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                if (ons == gons) {
                                    correct_cyfras = correct_cyfras + 1;
                                }
                                MyFile << "The number of correct digits:" << correct_cyfras << endl;
                                cout << "The number of correct digits:" << correct_cyfras << endl;
                                cout << "Continue the game (c) or end the game (e)?" << endl;
                                cin >> operation;
                                if (operation == 'c') {
                                }
                                else if (operation == 'e') {
                                    break;
                                }
                            }
                        }
                    }
                }
                else {
                    cout << "Incorrect input" << endl;
                }
            }
        }
        else {
            cout << "Wrong command." << endl;
        }
    }
    return 0;
}      
