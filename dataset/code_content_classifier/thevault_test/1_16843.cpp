void Server::run() {

    waitForClient();

    try {

            //sendDataAtStart();
            while (true) {
                // receiving command from client
                sock->receiving(cmd);
                // execute this command
                actions(cmd);

            }

        } catch (SocketException& e) {

            std::cout << "SocketException was caught: " << e.description() << std::endl;
            connected = false;
            // stop slammap thread
            run();
        }
}