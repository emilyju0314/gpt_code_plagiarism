int Frame::ExtractAudio( void *sound ) const
{
	AudioInfo info;

	if ( GetAudioInfo( info ) == true )
	{
#ifdef HAVE_LIBDV

		int n, i;
		int16_t* s = ( int16_t * ) sound;

		dv_decode_full_audio( decoder, data, ( int16_t ** ) audio_buffers );
		for ( n = 0; n < info.samples; ++n )
			for ( i = 0; i < info.channels; i++ )
				*s++ = audio_buffers[ i ][ n ];

	}
	else
		info.samples = 0;

#else
		/* Collect the audio samples */
		char* s = ( char * ) sound;

		switch ( info.frequency )
		{
		case 32000:

			/* This is 4 channel audio */

			if ( IsPAL() )
			{
				short * p = ( short* ) sound;
				for ( int n = 0; n < info.samples; ++n )
				{
					register int r = ( ( unsigned char* ) data ) [ palmap_2ch1[ n ] + 1 ]; // LSB
					*p++ = compmap[ ( ( ( unsigned char* ) data ) [ palmap_2ch1[ n ] ] << 4 ) + ( r >> 4 ) ];   // MSB
					*p++ = compmap[ ( ( ( unsigned char* ) data ) [ palmap_2ch1[ n ] + 1 ] << 4 ) + ( r & 0x0f ) ];
				}


			}
			else
			{
				short* p = ( short* ) sound;
				for ( int n = 0; n < info.samples; ++n )
				{
					register int r = ( ( unsigned char* ) data ) [ ntscmap_2ch1[ n ] + 1 ]; // LSB
					*p++ = compmap[ ( ( ( unsigned char* ) data ) [ ntscmap_2ch1[ n ] ] << 4 ) + ( r >> 4 ) ];   // MSB
					*p++ = compmap[ ( ( ( unsigned char* ) data ) [ ntscmap_2ch1[ n ] + 1 ] << 4 ) + ( r & 0x0f ) ];
				}
			}
			break;

		case 44100:
		case 48000:

			/* this can be optimized significantly */

			if ( IsPAL() )
			{
				for ( int n = 0; n < info.samples; ++n )
				{
					*s++ = ( ( char* ) data ) [ palmap_ch1[ n ] + 1 ]; /* LSB */
					*s++ = ( ( char* ) data ) [ palmap_ch1[ n ] ];     /* MSB */
					*s++ = ( ( char* ) data ) [ palmap_ch2[ n ] + 1 ]; /* LSB */
					*s++ = ( ( char* ) data ) [ palmap_ch2[ n ] ];     /* MSB */
				}
			}
			else
			{
				for ( int n = 0; n < info.samples; ++n )
				{
					*s++ = ( ( char* ) data ) [ ntscmap_ch1[ n ] + 1 ]; /* LSB */
					*s++ = ( ( char* ) data ) [ ntscmap_ch1[ n ] ];     /* MSB */
					*s++ = ( ( char* ) data ) [ ntscmap_ch2[ n ] + 1 ]; /* LSB */
					*s++ = ( ( char* ) data ) [ ntscmap_ch2[ n ] ];     /* MSB */
				}
			}
			break;

			/* we can't handle any other format in the moment */

		default:
			info.samples = 0;
		}

	}