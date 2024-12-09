bool xiProtoBase::SetBlocking( const bool blocking ) {
   if ( nativeHandle == 0 ) {
	   return false;
   }

#if defined( __WIN_API__ )
   unsigned long mode = blocking ? 0 : 1;
   return ( ioctlsocket( nativeHandle, FIONBIO, &mode ) == 0) ? true : false;
#elif defined( __POSIX__ )
   int flags = fcntl( nativeHandle, F_GETFL, 0 );
   if ( flags < 0 ) {
	   return false;
   }
   flags = blocking ? ( flags & ~O_NONBLOCK ) : ( flags | O_NONBLOCK );
   return ( fcntl( nativeHandle, F_SETFL, flags ) == 0 ) ? true : false;
#endif
}