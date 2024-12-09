void Server::waitForClient() {

    std::cout << "Listening for new client ..." << std::endl;
    serverSocket->accept(*sock);
    connected = true;

}