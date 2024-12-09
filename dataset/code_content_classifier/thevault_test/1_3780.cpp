void CTexture::FixupTexture( const void *pData, int nSize, LoaderError_t loaderError )
{
	if ( loaderError != LOADERERROR_NONE )
	{
		// mark as invalid
		nSize = 0;
	}

	m_nInternalFlags &= ~TEXTUREFLAGSINTERNAL_QUEUEDLOAD;

	// Make sure we've actually allocated the texture handles
	Assert( HasBeenAllocated() );

#if defined( _GAMECONSOLE )
	// hand off the hires data down to the shaderapi to upload directly
	// Purposely bypassing downloading through material system, which is non-reentrant
	// for that operation, to avoid mutexing.

	// NOTE: Strange refcount work here to keep it threadsafe
	int nRefCount = m_nRefCount;
	int nRefCountOld = nRefCount;
	g_pShaderAPI->PostQueuedTexture( 
					pData, 
					nSize, 
					m_pTextureHandles, 
					m_nFrameCount,
					m_nActualWidth,
					m_nActualHeight,
					m_nActualDepth,
					m_nActualMipCount,
					&nRefCount );
	int nDelta = nRefCount - nRefCountOld;
	m_nRefCount += nDelta;
#endif
}