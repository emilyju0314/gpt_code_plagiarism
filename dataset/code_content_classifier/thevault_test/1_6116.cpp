bool Frame::GetTimeCode( TimeCode &timeCode ) const
{
#ifdef HAVE_LIBDV
	int timestamp[ 4 ];

	dv_get_timestamp_int( decoder, timestamp );

	timeCode.hour = timestamp[ 0 ];
	timeCode.min = timestamp[ 1 ];
	timeCode.sec = timestamp[ 2 ];
	timeCode.frame = timestamp[ 3 ];
#else

	Pack tc;

	if ( GetSSYBPack( 0x13, tc ) == false )
		return false;

	int frame = tc.data[ 1 ];
	int sec = tc.data[ 2 ];
	int min = tc.data[ 3 ];
	int hour = tc.data[ 4 ];

	timeCode.frame = ( frame & 0xf ) + 10 * ( ( frame >> 4 ) & 0x3 );
	timeCode.sec = ( sec & 0xf ) + 10 * ( ( sec >> 4 ) & 0x7 );
	timeCode.min = ( min & 0xf ) + 10 * ( ( min >> 4 ) & 0x7 );
	timeCode.hour = ( hour & 0xf ) + 10 * ( ( hour >> 4 ) & 0x3 );
#endif

	return true;
}