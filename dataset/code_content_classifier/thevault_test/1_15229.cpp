nsapi_error_t HttpServer::start(uint16_t port) {
    // create client connections
    // needs RAM for buffers!
    _clientConnections.reserve(_nWorkerThreads);
    for(int i=0; i < _nWorkerThreads; i++) {
        string *threadName = new string;
        *threadName = "HTTPClientThread_" + to_string(i);
        ClientConnection *clientCon = new ClientConnection(this, threadName->c_str());
        MBED_ASSERT(clientCon);
        _clientConnections.push_back(clientCon);
    }

    // create server socket and start to listen
    _serverSocket = new TCPSocket();
    MBED_ASSERT(_serverSocket);
    nsapi_error_t ret;

    ret = _serverSocket->open(_network);
    if (ret != NSAPI_ERROR_OK) {
        return ret;
    }

    ret = _serverSocket->bind(port);
    if (ret != NSAPI_ERROR_OK) {
        return ret;
    }

    _serverSocket->listen(_nWorkerThreads); // max. concurrent connections...

    _threadHTTPServer.start(callback(this, &HttpServer::main));

    return NSAPI_ERROR_OK;
}