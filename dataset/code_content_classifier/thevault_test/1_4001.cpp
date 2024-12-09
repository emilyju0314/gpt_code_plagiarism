CClientSocket::CClientSocket( const std::string& serverName, int portNo, \
      CCallbackInterface* cbDoor ) : cbClass( cbDoor ), clientSocket(0)
{
   struct sockaddr_in serverAddress;
   struct hostent *server;
   std::stringstream ss;

   // Open a client socket
   clientSocket = socket( AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0 );
   if( clientSocket < 0 ) 
   {
       ss << "ERROR opening client socket! errno=" << errno;
       throw std::runtime_error( ss.str() );
   }

   // Get server structure
   server = gethostbyname( serverName.c_str() ); 
   if( server == NULL )
   {
       ss << "ERROR getting server host data! errno=" << errno;
       throw std::runtime_error( ss.str() );
   }

   memset( &serverAddress, 0, sizeof( serverAddress ) );
   serverAddress.sin_family = AF_INET;
   memcpy( &serverAddress.sin_addr.s_addr, (void*)server->h_addr, server->h_length );
   serverAddress.sin_port = htons( portNo );

   // Try to connect to server
   if( connect( clientSocket, \
       (struct sockaddr*)&serverAddress, sizeof( struct sockaddr_in ) ) < 0 && \
       errno != EINPROGRESS )
   {
       ss << "ERROR connecting to server! " << strerror( errno );
       throw std::runtime_error( ss.str() );
   }
}