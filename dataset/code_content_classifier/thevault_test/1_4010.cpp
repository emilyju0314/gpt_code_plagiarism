CServerSocket::CServerSocket( int portNo, CCallbackInterface* cbDoor ) : \
       acceptActive( false ), cbClass( cbDoor )
{
   // Opent listening socket:
   listenSocket = socket( AF_INET, SOCK_STREAM, 0 );
   if( listenSocket < 0 ) 
   {
       std::stringstream ss;
       ss << "ERROR opening listening socket! errno=" << errno;
       throw std::runtime_error( ss.str() );
   }

   // Socket options:
   fcntl( listenSocket, F_SETFL, O_NONBLOCK );

   // Bind to the address/port specified:
   struct sockaddr_in serverAddress;

   memset( &serverAddress, 0, sizeof( serverAddress ) );
   serverAddress.sin_family = AF_INET;
   serverAddress.sin_addr.s_addr = htonl( INADDR_ANY );
   serverAddress.sin_port = htons( portNo );
 
   if( bind( listenSocket, ( struct sockaddr *)&serverAddress, sizeof( serverAddress ) ) < 0 )
   {
       std::stringstream ss;
       ss << "ERROR binding to port " << portNo << "! errno=" << errno << \
          " (" << strerror( errno ) << ")" << std::endl;
       throw std::runtime_error( ss.str() );
   }

   // Start listening for connections:
   if( listen( listenSocket, 10 ) < 0 )
   {
       std::stringstream ss;
       ss << "ERROR listening for connections on port " << portNo << "! errno=" << errno;
       throw std::runtime_error( ss.str() );
   }
}