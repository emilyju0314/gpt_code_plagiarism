void CClientSocket::closeConnection( )
{
   close( clientSocket );
   clientSocket = 0;
}