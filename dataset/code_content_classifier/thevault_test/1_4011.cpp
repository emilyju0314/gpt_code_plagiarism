CServerSocket::~CServerSocket()
{
   close( listenSocket );
   removeAllConnections();
}