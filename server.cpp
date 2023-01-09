//
// Created by kashann on 09/01/2023.
//

////
//// Created by kashann on 21/12/2022.
////
//
//#include "server.h"
//#include "Menu.h"
//#include "server.h"
//
//server::server(const int port) : m_port(port), m_socket_fd(-1), m_client_socket_fd(-1) {}
//
//
//void server::initlize() {
//
//    // Create a socket
//    m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
//    if (m_socket_fd < 0) {
//        std::perror("Error creating socket");
//    }
//    // Set up the sockaddr_in struct
//    struct sockaddr_in addr;
//    memset(&addr, 0, sizeof(addr));
//    addr.sin_family = AF_INET;
//    addr.sin_addr.s_addr = INADDR_ANY;
//    addr.sin_port = htons(m_port);
//
//    // Bind the socket to an address and port
//    int bind_result = bind(m_socket_fd, (struct sockaddr *) &addr, sizeof(addr));
//    if (bind_result < 0) {
//        std::perror("Error binding socket");
//    }
//
//    // Start listening for incoming connections
//    int listen_result = listen(m_socket_fd, BACKLOG);
//    if (listen_result < 0) {
//        std::perror("Error listening socket");
//    }
//
//}
//
//void server::communicatClient() {
//    std::string stringMenu = "Welcome to KNN Classifier Server. Please choose an option:\n1. upload an unclassified csv data file\n2. algorithm setting\n3. classify data\n4. display results\n5. download results\n8.exit";
//    Menu *menu = new Menu();
//    int flag = 0;
//    while (flag) {
//        ///send the menu to client
//        int sent_bytes = send(m_client_socket_fd, stringMenu, stringMenu.length(), 0);
//        if (sent_bytes < 0) {
//            perror("error sending to client");
//        }
//        ///read the number the client sent
//        string str = "";
//        char buffer[2056];
//        int expected_data_len = sizeof(buffer);
//        int read_bytes = recv(m_client_socket_fd, buffer, expected_data_len, 0);
//        if (read_bytes == 0) {
//            break;
//
//        } else if (read_bytes < 0) {
//            std::cerr << "Error reading data from client" << std::endl;
//        } else {
//            int num = stoi(buffer);
//            switch (num) {
//                case 1:
//                    menu->m_commands[0]->execute();
//                    break;
//                case 2:
//                    menu->m_commands[1]->execute();
//                    break;
//                case 3:
//                    menu->m_commands[2]->execute();
//                    break;
//                case 4:
//                    menu->m_commands[3]->execute();
//                    break;
//                case 5:
//                    menu->m_commands[4]->execute();
//                    break;
//                case 8:
//                    flag = 1;
//                    close(m_client_socket_fd);
//                    break;
//                default:
//                    break;
//            }
//
//        }
//    }
//}
//
//
//void server::connectClient() {
//    while (true) {
//        struct sockaddr_in client_addr;
//        unsigned int addr_len = sizeof(client_addr);
//        m_client_socket_fd = accept(m_socket_fd, (struct sockaddr *) &client_addr, &addr_len);
//        if (m_client_socket_fd < 0) {
//            perror("error accepting client");
//        }
//        communicatClient();
//    }
//}
//
//int main(int argc, char **argv) {
//    const int port = stoi(argv[1]);
//    server myServer(port);
//    myServer.initlize();
//    myServer.connectClient();
//    close(myServer.m_socket_fd);
//}
//
//
//
//
//
//
//
//
//
//
//
//
