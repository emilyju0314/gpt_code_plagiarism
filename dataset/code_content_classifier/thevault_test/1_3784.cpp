bool CTexture::FinishAsyncDownload( AsyncTextureContext_t *pContext, void *pData, int nNumReadBytes, bool bAbort, float flMaxTimeMs )
{
	// The temp exclusions/restores are expected/desgined to be serviced at the only safe interval at the end of the frame
	// and end of any current QMS jobs before QMS queues and start on it's next frame. Texture downloading is not thead safe
	// and does not need to be made so. Instead, while the texture access pattens are quiescent and stable, the download
	// (expected to be few in number) is deferred to this safe interval.
	Assert( ThreadInMainThread() );

	// For non-exclude async downloads, never abort
	if ( m_nFlags & TEXTUREFLAGS_ASYNC_DOWNLOAD )
	{
		bAbort = false;
	}

	// aborting just discards the data
	// whatever state the texture bits were in, they stay that way
	bool bDownloadCompleted = true;
	if ( !bAbort && g_pShaderAPI->CanDownloadTextures() )
	{
		// the delayed async nature of this download may have invalidated the original/expected state at the moment of queuing
		// prevent an update of the texture to the wrong state
		// the temp exclusion monitor is responsible for rescheduling
		if ( ( m_nFlags & TEXTUREFLAGS_ASYNC_DOWNLOAD ) || // general async download (non-exclude)
			( ( ( pContext->m_nInternalFlags & TEXTUREFLAGSINTERNAL_SHOULDTEMPEXCLUDE ) == ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_SHOULDTEMPEXCLUDE ) ) &&
			  ( pContext->m_nDesiredTempDimensionLimit == m_nDesiredTempDimensionLimit ) ) )
		{
			// the download will put the texture in the expected state
			MaterialLock_t hLock = MaterialSystem()->Lock();
			if ( m_nFlags & TEXTUREFLAGS_ASYNC_DOWNLOAD )
			{
				bDownloadCompleted = DownloadAsyncTexture( pContext, pData, nNumReadBytes, flMaxTimeMs );
			}
			else
			{
				DownloadTexture( NULL, pData, nNumReadBytes );
			}
			MaterialSystem()->Unlock( hLock );
		}
		else
		{
			// the texture wants to be in a different state than this download can achieve
			bool bDesiredTempExclude = ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_SHOULDTEMPEXCLUDE ) != 0;
			bool bActualTempExclude = ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_TEMPEXCLUDED ) != 0;
			if ( bDesiredTempExclude == bActualTempExclude && m_nDesiredTempDimensionLimit == m_nActualDimensionLimit )
			{
				// the current desired temp exclude state now matches the actual
				// the discarded download does not need to happen
				m_nInternalFlags &= ~TEXTUREFLAGSINTERNAL_TEMPEXCLUDE_UPDATE;
			}
		}
	}

	if ( bDownloadCompleted )
	{
		// ownership of the data is expected to have been handed off
		g_pFullFileSystem->FreeOptimalReadBuffer( pData );
		g_pFullFileSystem->AsyncRelease( m_hAsyncControl );
		// texture can be rescheduled
		m_hAsyncControl = NULL;

		delete pContext;

		if (m_nFlags & TEXTUREFLAGS_ASYNC_DOWNLOAD)
		{
			m_nInternalFlags |= TEXTUREFLAGSINTERNAL_ASYNC_DONE; // signal we're done
			m_nFlags &= ~TEXTUREFLAGS_ASYNC_DOWNLOAD; // no longer want this flag
		}
	}

	return bDownloadCompleted;
}