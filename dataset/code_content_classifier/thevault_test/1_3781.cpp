void CTexture::ReconstructTexture( void *pSourceData, int nSourceDataSize )
{
	int oldWidth = m_nActualWidth;
	int oldHeight = m_nActualHeight;
	int oldDepth = m_nActualDepth;
	int oldMipCount = m_nActualMipCount;
	int oldFrameCount = m_nFrameCount;

	// FIXME: Should RenderTargets be a special case of Procedural?
	char *pResolvedFilename = NULL;
	IVTFTexture *pVTFTexture = NULL;

	if ( IsProcedural() )
	{
		// This will call the installed texture bit regeneration interface
		pVTFTexture = ReconstructProceduralBits();
	}
	else if ( IsRenderTarget() )
	{
		// Compute the actual size + format based on the current mode
		ComputeActualSize( true );
	}
	else
	{
		pVTFTexture = LoadTexttureBitsFromFileOrData( pSourceData, nSourceDataSize, &pResolvedFilename );
	}

	if ( !HasBeenAllocated() ||
		m_nActualWidth != oldWidth ||
		m_nActualHeight != oldHeight ||
		m_nActualDepth != oldDepth ||
		m_nActualMipCount != oldMipCount ||
		m_nFrameCount != oldFrameCount )
	{
		if ( HasBeenAllocated() )
		{
			// This is necessary for the reload case, we may discover there
			// are more frames of a texture animation, for example, which means
			// we can't rely on having the same number of texture frames.
			FreeShaderAPITextures();
		}

		// Create the shader api textures, except temp render targets on 360.
		if ( !( IsX360() && IsTempRenderTarget() ) )
		{
			if ( !AllocateShaderAPITextures() )
				return;
		}
	}

	// Render Targets just need to be cleared, they have no upload
	if ( IsRenderTarget() )
	{
		// Clear the render target to opaque black
#if !defined( _GAMECONSOLE )

		// Only clear if we're not a depth-stencil texture
		if ( !IsDepthTextureFormat( m_ImageFormat ) )
		{
			CMatRenderContextPtr pRenderContext( MaterialSystem() );
			ITexture *pThisTexture = GetEmbeddedTexture( 0 );
			pRenderContext->PushRenderTargetAndViewport( pThisTexture );						// Push this texture on the stack
			g_pShaderAPI->ClearColor4ub( 0, 0, 0, 0xFF );										// Set the clear color to opaque black
			g_pShaderAPI->ClearBuffers( true, false, false, m_nActualWidth, m_nActualHeight );	// Clear the target
			pRenderContext->PopRenderTargetAndViewport();										// Pop back to previous target
		}
#else
		// 360 may not have RT surface during init time
		// avoid complex conditionalizing, just cpu clear it, which always works
		ClearTexture( 0, 0, 0, 0xFF );
#endif
		// no upload
		return;
	}

	if ( IsGameConsole() && IsProcedural() && !pVTFTexture )
	{
		// 360 explicitly inhibited this texture's procedural generation, so no upload needed
		return;
	}

	// Blit down the texture faces, frames, and mips into the board memory
	int nFirstFace, nFaceCount;
	GetDownloadFaceCount( nFirstFace, nFaceCount );
	
	if ( IsPC() )
	{
		WriteDataToShaderAPITexture( m_nFrameCount, nFaceCount, nFirstFace, m_nActualMipCount, pVTFTexture, m_ImageFormat );
	}

#if defined( _GAMECONSOLE )
	bool bDoUpload = true;
	if ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_QUEUEDLOAD )
	{
		// the vtf didn't load any d3d bits, the hires bits will arrive before gameplay
		bDoUpload = false;
	}

	if ( bDoUpload )
	{
		for ( int iFrame = 0; iFrame < m_nFrameCount; ++iFrame )
		{
			Modify( iFrame );
			for ( int iFace = 0; iFace < nFaceCount; ++iFace )
			{
				for ( int iMip = 0; iMip < m_nActualMipCount; ++iMip )
				{
					unsigned char *pBits;
					int nWidth, nHeight, nDepth;
					pVTFTexture->ComputeMipLevelDimensions( iMip, &nWidth, &nHeight, &nDepth );
#ifdef _PS3
					// PS3 textures are pre-swizzled at tool time
					pBits = pVTFTexture->ImageData( iFrame, iFace + nFirstFace, iMip, 0, 0, 0 );
					g_pShaderAPI->TexImage2D( iMip, iFace, m_ImageFormat, nDepth > 1 ? nDepth : 0, nWidth, nHeight,
						pVTFTexture->Format(), false, pBits );
#else // _PS3
					pBits = pVTFTexture->ImageData( iFrame, iFace + nFirstFace, iMip, 0, 0, 0 );
					g_pShaderAPI->TexImage2D( iMip, iFace, m_ImageFormat, 0, nWidth, nHeight, 
						pVTFTexture->Format(), pVTFTexture->IsPreTiled(), pBits );
#endif // !_PS3
				}
			}
		}
	}

#ifdef _X360
	if ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_CACHEABLE )
	{
		// Make sure we've actually allocated the texture handles
		Assert( HasBeenAllocated() );

		// a cacheing texture needs to know how to get its bits back
		g_pShaderAPI->SetCacheableTextureParams( m_pTextureHandles, m_nFrameCount, pResolvedFilename, m_nMipSkipCount );
	}
#endif // _X360

	if ( m_nInternalFlags & TEXTUREFLAGSINTERNAL_QUEUEDLOAD )
	{
		// the empty hires version was setup
		// the hires d3d bits will be delivered before gameplay (or render)
		LoaderPriority_t priority = LOADERPRIORITY_BEFOREPLAY;
		
		// add the job 
		LoaderJob_t loaderJob;
		loaderJob.m_pFilename = pResolvedFilename;
		loaderJob.m_pCallback = QueuedLoaderCallback;
		loaderJob.m_pContext = (void *)this;
		loaderJob.m_Priority =  priority;
		g_pQueuedLoader->AddJob( &loaderJob );
	}

	if ( IsProcedural() && m_pTextureRegenerator && m_pTextureRegenerator->HasPreallocatedScratchTexture() )
	{
		// nothing to free; we used the pre-allocated scratch texture
	}
	else
	{
		// hint the vtf system to release memory associated with its load
		pVTFTexture->ReleaseImageMemory();
	}
#endif // _GAMECONSOLE

	//lwss - This is actually done with malloc(). Goes through about 15 function calls, unsure where exactly but it was flagged by ASAN
	//delete [] pResolvedFilename;
	free( pResolvedFilename );
	//lwss end

	// the 360 does not persist a large buffer
	// the pc can afford to persist a large buffer
	FreeOptimalReadBuffer( IsGameConsole() ? 32*1024 : 6*1024*1024 );
}