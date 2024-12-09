HttpServer::HttpServer(NetworkInterface* network, int nWorkerThreads, int nWebSocketsMax)  :
    _threadHTTPServer(osPriorityNormal, 2*1024, nullptr, "HTTPServerThread") { 
    _network = network;
    _nWebSockets = 0;
    _nWebSocketsMax = nWebSocketsMax;
    _nWorkerThreads = nWorkerThreads;
}