bool Frame::GetRecordingDate( struct tm &recDate ) const
{
#ifdef HAVE_LIBDV
	return dv_get_recording_datetime_tm( decoder, ( struct tm * ) &recDate );
#else

	Pack pack62;
	Pack pack63;

	if ( GetSSYBPack( 0x62, pack62 ) == false )
		return false;

	int day = pack62.data[ 2 ];
	int month = pack62.data[ 3 ];
	int year = pack62.data[ 4 ];

	if ( GetSSYBPack( 0x63, pack63 ) == false )
		return false;

	int sec = pack63.data[ 2 ];
	int min = pack63.data[ 3 ];
	int hour = pack63.data[ 4 ];

	sec = ( sec & 0xf ) + 10 * ( ( sec >> 4 ) & 0x7 );
	min = ( min & 0xf ) + 10 * ( ( min >> 4 ) & 0x7 );
	hour = ( hour & 0xf ) + 10 * ( ( hour >> 4 ) & 0x3 );
	year = ( year & 0xf ) + 10 * ( ( year >> 4 ) & 0xf );
	month = ( month & 0xf ) + 10 * ( ( month >> 4 ) & 0x1 );
	day = ( day & 0xf ) + 10 * ( ( day >> 4 ) & 0x3 );

	if ( year < 25 )
		year += 2000;
	else
		year += 1900;

	recDate.tm_sec = sec;
	recDate.tm_min = min;
	recDate.tm_hour = hour;
	recDate.tm_mday = day;
	recDate.tm_mon = month - 1;
	recDate.tm_year = year - 1900;
	recDate.tm_wday = -1;
	recDate.tm_yday = -1;
	recDate.tm_isdst = -1;

	/* sanity check of the results */

	if ( mktime( &recDate ) == -1 )
		return false;
	return true;
#endif
}