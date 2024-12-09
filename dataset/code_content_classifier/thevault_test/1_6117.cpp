bool Frame::GetAudioInfo( AudioInfo &info ) const
{
#ifdef HAVE_LIBDV
	info.frequency = decoder->audio->frequency;
	info.samples = decoder->audio->samples_this_frame;
	info.frames = ( decoder->audio->aaux_as.pc3.system == 1 ) ? 50 : 60;
	info.channels = decoder->audio->num_channels;
	info.quantization = ( decoder->audio->aaux_as.pc4.qu == 0 ) ? 16 : 12;
	return true;
#else

	int af_size;
	int smp;
	int flag;
	Pack pack50;


	info.channels = 2;
	info.quantization = 16;

	/* Check whether this frame has a valid AAUX source packet
	(header == 0x50). If so, get the audio samples count. If not,
	skip this audio data. */

	if ( GetAAUXPack( 0x50, pack50 ) == true )
	{

		/* get size, sampling type and the 50/60 flag. The number of
		audio samples is dependend on all of these. */

		af_size = pack50.data[ 1 ] & 0x3f;
		smp = ( pack50.data[ 4 ] >> 3 ) & 0x07;
		flag = pack50.data[ 3 ] & 0x20;

		if ( flag == 0 )
		{
			info.frames = 60;
			switch ( smp )
			{
			case 0:
				info.frequency = 48000;
				info.samples = 1580 + af_size;
				break;
			case 1:
				info.frequency = 44100;
				info.samples = 1452 + af_size;
				break;
			case 2:
				info.frequency = 32000;
				info.samples = 1053 + af_size;
				info.quantization = 12;
				break;
			}
		}
		else
		{ // 50 frames (PAL)
			info.frames = 50;
			switch ( smp )
			{
			case 0:
				info.frequency = 48000;
				info.samples = 1896 + af_size;
				break;
			case 1:
				info.frequency = 44100;
				info.samples = 0; // I don't know
				break;
			case 2:
				info.frequency = 32000;
				info.samples = 1264 + af_size;
				info.quantization = 12;
				break;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
#endif
}