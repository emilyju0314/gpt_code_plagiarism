FOR_EACH_VEC( m_pBackBufferSurfaces, i )
	{
		if ( m_pBackBufferSurfaces[i] != NULL )
		{
			IDirect3DSurface9* backBufferSurface = m_pBackBufferSurfaces[i];
			m_pBackBufferSurfaces[i] = NULL;

			// Default back buffer may have a reference held by DirectX.
			int nRemainingReferences = backBufferSurface->Release();
			Assert(nRemainingReferences == 0 || i == BACK_BUFFER_INDEX_DEFAULT && nRemainingReferences <= 1);
		}
	}