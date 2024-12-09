void envi_raw_msg::update_msg( const string& msg )
{
   if( envi_msg_completo( msg ) == true )
   {
#ifdef DEBUG_ENVI
cout << "envi_raw_msg::update_msg:theMsg vale (" << theMsg << ") msg:" << msg << endl;
#endif
      theMsg = msg;
   }
}