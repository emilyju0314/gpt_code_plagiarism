const std::string CServerSocket::getConnectedSocketList( )
{
   std::stringstream ss;
   std::deque<int>::iterator fit = connectedSockets.begin();

   bool first(true);

   while( fit != connectedSockets.end() )
   {
      if( first == false )
          ss << ",";
      else
         first = false;

      ss << *fit;

      fit++;
   }

   return ss.str();
}