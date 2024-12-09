void SlamMap::sendSlamMapThread(ServerSocket &sock) {

    std::vector<int> v;
    int nr = 1;

    while (Server::isConnected() && sendMap_) {
        std::cout << "Send map nr: " << nr <<std::endl;
        v = getMapData();
        sock.sending(v);
        sleep(5);
        nr++;
    }

}