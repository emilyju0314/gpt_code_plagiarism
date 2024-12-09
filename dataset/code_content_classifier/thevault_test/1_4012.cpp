void CServerSocket::manage()
{
   std::stringstream ssSelectTrace;

   int maxsock = listenSocket;
   fd_set  set;
   struct timeval timeout = { 0,0 };

   FD_ZERO( &set );
   FD_SET( listenSocket, &set );

   ssSelectTrace << " - SELECT:FDS:(" << listenSocket;

   // Include the client connections to the set:
   std::deque< int >::iterator dequeit = connectedSockets.begin();
   while( dequeit != connectedSockets.end() )
   {
      ssSelectTrace << "," << *dequeit;

      FD_SET( (*dequeit), &set );

      if( *dequeit > listenSocket ) maxsock = *dequeit;

      dequeit++;
   }

   ssSelectTrace << ")" << std::endl;

   int rc = select( maxsock + 1, &set, NULL, NULL, &timeout);

   // If failure, throw an exception:
   if( rc < 0 )
   {
       std::stringstream ss( ssSelectTrace.str() );
       ss << "ERROR checking for incoming messages or new connections! - errno=" << errno << \
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

      // Check if we have a new connection request:
      if( FD_ISSET( listenSocket, &set ) )
      {
         try {
            __accept_internal();
         } catch( std::runtime_error& e )
         {
             CTrace( cout, TRACE_ERROR ) << (char*)e.what() << endl;
             break;
         };

         FD_CLR( listenSocket, &set );
      }

      // Check if we have activity on a connected socket:
      dequeit = connectedSockets.begin();
      while( dequeit != connectedSockets.end() )
      {
#ifdef SOCKDBG
          CTrace( cout, TRACE_PROCESS ) << " - - SELECT_RES:test(" << *dequeit << ")" << endl;
#endif

          if( FD_ISSET( (*dequeit), &set ) )
          {
#ifdef SOCKDBG
              CTrace( cout, TRACE_PROCESS ) << \
                  " - - SELECT_RES:incoming data(" << *dequeit << ")" << endl;
#endif

              FD_CLR( *dequeit, &set );

              if( readData( (*dequeit) ) == 0 )
              {
                 CTrace( cout, TRACE_PROCESS ) << \
                    "-- CLIENT CLOSED CONNECTION [conn " << *dequeit << "]" << endl;

                 close( *dequeit );

                 // Notify the application
                 cbClass->onConnectionClose( *dequeit );

                 // Erase this connection
                 dequeit = connectedSockets.erase( dequeit );
              }
          }
          else
          {
              dequeit++;
          }
      }
   }
}