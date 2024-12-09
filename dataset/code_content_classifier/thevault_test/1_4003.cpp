int CClientSocket::sendBytes( const void* data, size_t len, int flags )
{
   int rc = 0;

   if( len == 0 || clientSocket == 0 ) return 0;

   rc = send( clientSocket, data, len, flags );

   // If error, break connection:
   if( rc <= 0 )
   {
       std::stringstream ss;
       ss << "ERROR writing message! - errno=" << errno <<  " (" << \
             strerror( errno ) << ")" << endl;

       throw std::runtime_error( ss.str() );

       close( clientSocket );
       clientSocket = 0;
   }

   return rc;
}