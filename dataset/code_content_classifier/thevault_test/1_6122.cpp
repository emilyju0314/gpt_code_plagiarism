int Frame::ExtractAudio( int16_t **channels ) const
{
	AudioInfo info;

	if ( GetAudioInfo( info ) == true )
		dv_decode_full_audio( decoder, data, channels );
	else
		info.samples = 0;

	return info.samples * info.channels * 2;
}