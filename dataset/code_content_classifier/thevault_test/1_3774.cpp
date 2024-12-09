void CTexture::SetFilteringAndClampingMode()
{
	if( !HasBeenAllocated() )
		return;

	int nCount = m_nFrameCount;
	if ( IsX360() && IsRenderTarget() )
	{
		// 360 render targets have a reserved surface
		nCount--;
	}

	for ( int iFrame = 0; iFrame < nCount; ++iFrame )
	{
		Modify( iFrame );			// Indicate we're changing state with respect to a particular frame
		SetWrapState();				// Send the appropriate wrap/clamping modes to the shaderapi.
		SetFilterState();			// Set the filtering mode for the texture after downloading it.
									// NOTE: Apparently, the filter state cannot be set until after download
	}
}