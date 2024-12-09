bool Frame::IsNewRecording() const
{
#ifdef HAVE_LIBDV
	return ( decoder->audio->aaux_asc.pc2.rec_st == 0 );
#else

	Pack aauxSourceControl;

	/* if we can't find the packet, we return "no new recording" */

	if ( GetAAUXPack( 0x51, aauxSourceControl ) == false )
		return false;

	unsigned char recStartPoint = aauxSourceControl.data[ 2 ] & 0x80;

	return recStartPoint == 0 ? true : false;
#endif
}