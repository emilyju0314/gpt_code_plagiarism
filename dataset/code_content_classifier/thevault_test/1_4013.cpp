int CServerSocket::sendBytes( const void* data, size_t len, int flags, int sockno )
{
   int rc = 0;

   if( len == 0 ) return 0;

   rc = send( sockno, data, len, flags );
#ifdef SOCKDBG
CTrace::hexdmp( (unsigned char*)data, len );
#endif

   // If error, remove connection:
   if( rc <= 0 )
   {
//XXX throw excep
       removeConnection( sockno );
#ifdef SOCKDBG
      std::stringstream ss;
      ss << "-- SEND FAIL " << len << \
            " BYTES [have " << connectedSockets.size() << " connections]" << endl;
      CTrace( cout, TRACE_ERROR ) << ss.str() << endl;
#endif
   }

   return rc;
}