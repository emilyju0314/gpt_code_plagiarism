int CTexture::GetOptimalReadBuffer( FileHandle_t hFile, int nSize, CUtlBuffer &optimalBuffer )
{
	// get an optimal read buffer, only resize if necessary
	int minSize = IsGameConsole() ? 0 : 2 * 1024 * 1024;	// 360 has no min, PC uses 2MB min to avoid fragmentation
	nSize = MAX(nSize, minSize);
	int nBytesOptimalRead = g_pFullFileSystem->GetOptimalReadSize( hFile, nSize );
	if ( nBytesOptimalRead > s_nOptimalReadBufferSize )
	{
		FreeOptimalReadBuffer( 0 );

		s_nOptimalReadBufferSize = nBytesOptimalRead;
		s_pOptimalReadBuffer = g_pFullFileSystem->AllocOptimalReadBuffer( hFile, nSize );
		if ( mat_spewalloc.GetBool() )
		{
			Msg( "Allocated optimal read buffer of %d bytes @ 0x%p\n", s_nOptimalReadBufferSize, s_pOptimalReadBuffer );
		}
	}

	// set external buffer and reset to empty
	optimalBuffer.SetExternalBuffer( s_pOptimalReadBuffer, s_nOptimalReadBufferSize, 0, CUtlBuffer::READ_ONLY );

	// return the optimal read size
	return nBytesOptimalRead;
}