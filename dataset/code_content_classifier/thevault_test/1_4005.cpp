envi_raw_msg::envi_raw_msg( const string& raw_msg, sqlite_db* db, u_int8_t* data, CServerSocket* cs ) :
      theMsg( raw_msg ), theDB( db ), displayData( data ),
      liveData( false ), liveDataFd( -1 ), sSock( cs )

{
#ifdef DEBUG_ENVI
   cout << "envi_raw_msg::" << theMsg << endl;
#endif
}