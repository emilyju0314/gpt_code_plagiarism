void CClientSocket::manage()
{
   std::stringstream ssSelectTrace;

   int maxsock = clientSocket;
   fd_set  set;
   struct timeval timeout = { 0,0 };

   FD_ZERO( &set );
   FD_SET( clientSocket, &set );

   ssSelectTrace << " - SELECT:FDS:(" << clientSocket << ")" << std::endl;

   int rc = select( maxsock + 1, &set, NULL, NULL, &timeout);

   // If failure, throw an exception:
   if( rc < 0 )
   {
       std::stringstream ss( ssSelectTrace.str() );
       ss << "ERROR waiting for incoming messages! - errno=" << errno << \
              "(" << strerror( errno ) << ")";

       throw std::runtime_error( ss.str() );
   }

   // Check if we have read messages:
#ifdef SOCKDBG
   if( rc > 0 )
   {
      CTrace( cout, TRACE_VERBOSE ) << ssSelectTrace.str() << endl;
   }
#endif

   while( rc > 0 )
   {
#ifdef SOCKDBG
      CTrace( cout, TRACE_VERBOSE ) << " - SELECT:REMAINING " << rc << " EVENTS" << endl;
#endif
      rc--;

      if( FD_ISSET( clientSocket, &set ) )
      {
#ifdef SOCKDBG
          CTrace( cout, TRACE_PROCESS ) << \
              " - - SELECT_RES:incoming data(" << clientSocket << ")" << endl;
#endif

          FD_CLR( clientSocket, &set );

          if( readData( ) == 0 )
          {
              CTrace( cout, TRACE_PROCESS ) << \
                  "-- CLOSED CONNECTION [conn " << clientSocket << "]" << endl;

              close( clientSocket );

              // Notify the application
              cbClass->onConnectionClose( clientSocket );
              clientSocket = 0;
          }
      }
   }
}