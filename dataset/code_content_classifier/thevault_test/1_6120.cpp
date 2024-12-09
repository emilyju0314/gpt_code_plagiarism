bool Frame::IsNormalSpeed() const
{
	bool normal_speed = true;

#ifdef HAVE_LIBDV
	/* don't do audio if speed is not 1 */
	if ( decoder->std == e_dv_std_iec_61834 )
	{
		normal_speed = ( decoder->audio->aaux_asc.pc3.speed == 0x20 );
	}
	else if ( decoder->std == e_dv_std_smpte_314m )
	{
		if ( decoder->audio->aaux_as.pc3.system )
			/* PAL */
			normal_speed = ( decoder->audio->aaux_asc.pc3.speed == 0x64 );
		else
			/* NTSC */
			normal_speed = ( decoder->audio->aaux_asc.pc3.speed == 0x78 );
	}
#endif

	return ( normal_speed );
}