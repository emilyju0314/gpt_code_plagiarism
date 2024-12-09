void envi_raw_msg::procesa_msgs( void )
{
   string bloque_msg;

   RE re( "<msg>(.*?)</msg>", RE_Options().set_multiline(true) );
   while( re.PartialMatch( theMsg, &bloque_msg ) )
   {
      // Quitar de buf el mensaje:
      int pos = theMsg.find( "<msg>" + bloque_msg );
      if( pos != string::npos )
      {
         theMsg.erase( pos, bloque_msg.length() + 11 );  // se añaden longitudes de etiq msg
         msg( bloque_msg );
      }
   }
}