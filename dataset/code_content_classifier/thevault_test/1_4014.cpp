void CServerSocket::removeConnection( int sockno )
{
   std::deque< int >::iterator fit = \
         std::find( connectedSockets.begin(), connectedSockets.end(), sockno );

   if( fit != connectedSockets.end() )
   {
      CTrace( cout, TRACE_PROCESS ) << \
         "-- CLIENT CONNECTION CLOSED [conn " << *fit << "]" << endl;

      close( sockno );

      // Notify the application
      cbClass->onConnectionClose( *fit );

      // Erase this connection from the list of current client connections
      connectedSockets.erase( fit );
   }
}