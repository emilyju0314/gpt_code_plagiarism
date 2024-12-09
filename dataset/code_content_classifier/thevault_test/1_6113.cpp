Frame::Frame() : bytesInFrame( 0 )
{
	memset( data, 0, 144000 );

#ifdef HAVE_LIBDV

	decoder = dv_decoder_new( 0, 0, 0 );
	decoder->quality = DV_QUALITY_COLOR | DV_QUALITY_AC_1;
	dv_set_audio_correction ( decoder, DV_AUDIO_CORRECT_AVERAGE );
// VIDEOBOX PATCH BEGINS MOD005
	encoder = dv_encoder_new( 0, 0, 0 );
// VIDEOBOX PATCH ENDS
#else

	if ( maps_initialized == false )
	{

		for ( int n = 0; n < 1944; ++n )
		{
			int sequence1 = ( ( n / 3 ) + 2 * ( n % 3 ) ) % 6;
			int sequence2 = sequence1 + 6;
			int block = 3 * ( n % 3 ) + ( ( n % 54 ) / 18 );

			block = 6 + block * 16;
			{
				register int byte = 8 + 2 * ( n / 54 );
				palmap_ch1[ n ] = sequence1 * 150 * 80 + block * 80 + byte;
				palmap_ch2[ n ] = sequence2 * 150 * 80 + block * 80 + byte;
				byte += ( n / 54 );
				palmap_2ch1[ n ] = sequence1 * 150 * 80 + block * 80 + byte;
				palmap_2ch2[ n ] = sequence2 * 150 * 80 + block * 80 + byte;
			}
		}
		for ( int n = 0; n < 1620; ++n )
		{
			int sequence1 = ( ( n / 3 ) + 2 * ( n % 3 ) ) % 5;
			int sequence2 = sequence1 + 5;
			int block = 3 * ( n % 3 ) + ( ( n % 45 ) / 15 );

			block = 6 + block * 16;
			{
				register int byte = 8 + 2 * ( n / 45 );
				ntscmap_ch1[ n ] = sequence1 * 150 * 80 + block * 80 + byte;
				ntscmap_ch2[ n ] = sequence2 * 150 * 80 + block * 80 + byte;
				byte += ( n / 45 );
				ntscmap_2ch1[ n ] = sequence1 * 150 * 80 + block * 80 + byte;
				ntscmap_2ch2[ n ] = sequence2 * 150 * 80 + block * 80 + byte;
			}
		}
		for ( int y = 0x700; y <= 0x7ff; ++y )
			compmap[ y ] = ( y - 0x600 ) << 6;
		for ( int y = 0x600; y <= 0x6ff; ++y )
			compmap[ y ] = ( y - 0x500 ) << 5;
		for ( int y = 0x500; y <= 0x5ff; ++y )
			compmap[ y ] = ( y - 0x400 ) << 4;
		for ( int y = 0x400; y <= 0x4ff; ++y )
			compmap[ y ] = ( y - 0x300 ) << 3;
		for ( int y = 0x300; y <= 0x3ff; ++y )
			compmap[ y ] = ( y - 0x200 ) << 2;
		for ( int y = 0x200; y <= 0x2ff; ++y )
			compmap[ y ] = ( y - 0x100 ) << 1;
		for ( int y = 0x000; y <= 0x1ff; ++y )
			compmap[ y ] = y;
		for ( int y = 0x800; y <= 0xfff; ++y )
			compmap[ y ] = -1 - compmap[ 0xfff - y ];
		maps_initialized = true;
	}
#endif
	for ( int n = 0; n < 4; n++ )
		audio_buffers[ n ] = ( int16_t * ) malloc( 2 * DV_AUDIO_MAX_SAMPLES * sizeof( int16_t ) );
}