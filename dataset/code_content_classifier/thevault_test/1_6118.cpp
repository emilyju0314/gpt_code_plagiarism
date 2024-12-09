bool Frame::IsPAL( void ) const
{
	unsigned char dsf = data[ 3 ] & 0x80;
	bool pal = ( dsf == 0 ) ? false : true;
#ifdef HAVE_LIBDV

	if ( !pal )
	{
		pal = ( dv_system_50_fields ( decoder ) == 1 ) ? true : pal;
	}
#endif
	return pal;
}