void CTrace::hexdmp( unsigned char* ptr, int sze )
{
   int cnt=0;
   int line = 0;
   int line_prv = 0;
   int i;

   CTrace dmp( cout, 0 );
   dmp << "DMP [" << sze << " bytes] @ 0x" << hex << ptr << endl;
   while( cnt < sze )
   {
      dmp << setw(6) << setfill('0') << hex << cnt << " | ";

      while( 1 )
      {
         if( cnt < sze )
            dmp << setw(2) << setfill('0') << ptr[ cnt&0x0F ];
         else
            dmp << "   ";
         cnt++;
         line = cnt>>4;
         if( line != line_prv ) { break; }
      }

      line_prv = line;

      dmp << "| ";

      for( i=0; i<16; i++ )
         if( cnt-15+i > sze ) dmp << " ";
         else if( ptr[i] < 0x20 || ptr[i] > 0x7F ) dmp << ".";
         else                                      dmp << ptr[i];

      dmp << " |" << endl;

      ptr += 16;
   }

   dmp << endl;
}