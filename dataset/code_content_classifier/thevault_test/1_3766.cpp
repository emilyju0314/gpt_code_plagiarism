void CTexture::FreeOptimalReadBuffer( int nMaxSize )
{
	if ( s_pOptimalReadBuffer && s_nOptimalReadBufferSize >= nMaxSize )
	{
		if ( mat_spewalloc.GetBool() )
		{
			Msg( "Freeing optimal read buffer of %d bytes @ 0x%p\n", s_nOptimalReadBufferSize, s_pOptimalReadBuffer );
		}
		g_pFullFileSystem->FreeOptimalReadBuffer( s_pOptimalReadBuffer );
		s_pOptimalReadBuffer = NULL;
		s_nOptimalReadBufferSize = 0;
	}
}