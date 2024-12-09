bool Frame::GetVAUXPack( int packNum, Pack &pack ) const
{
#ifdef WITH_LIBDV
	pack.data[ 0 ] = packNum;
	dv_get_vaux_pack( decoder, packNum, &pack.data[ 1 ] );
	//cerr << "VAUX: 0x"
	//<< setw(2) << setfill('0') << hex << (int) pack.data[0]
	//<< setw(2) << setfill('0') << hex << (int) pack.data[1]
	//<< setw(2) << setfill('0') << hex << (int) pack.data[2]
	//<< setw(2) << setfill('0') << hex << (int) pack.data[3]
	//<< setw(2) << setfill('0') << hex << (int) pack.data[4]
	//<< endl;
	return true;

#else
	/* number of DIF sequences is different for PAL and NTSC */

	int seqCount = IsPAL() ? 12 : 10;

	/* process all DIF sequences */

	for ( int i = 0; i < seqCount; ++i )
	{

		/* there are three DIF blocks in the VAUX section */

		for ( int j = 0; j < 3; ++j )
		{

			/* each block has 15 packets */

			for ( int k = 0; k < 15; ++k )
			{

				/* calculate address: 150 DIF blocks per sequence, 80 bytes
				per DIF block, vaux blocks start at block 3, block has 3
				bytes header, packets have no header and are 5 bytes
				long. */

				const unsigned char *s = &data[ i * 150 * 80 + 3 * 80 + j * 80 + 3 + k * 5 ];
				// printf("vaux %d: %2.2x %2.2x %2.2x %2.2x %2.2x\n",
				// j * 15 + k, s[0],  s[1],  s[2],  s[3],  s[4]);
				if ( s[ 0 ] == packNum )
				{
					pack.data[ 0 ] = s[ 0 ];
					pack.data[ 1 ] = s[ 1 ];
					pack.data[ 2 ] = s[ 2 ];
					pack.data[ 3 ] = s[ 3 ];
					pack.data[ 4 ] = s[ 4 ];
					return true;
				}
			}
		}
	}
	return false;
#endif
}