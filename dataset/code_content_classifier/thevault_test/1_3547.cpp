inline void CShaderAPIDx8::SetScissorRect( const int nLeft, const int nTop, const int nRight, const int nBottom, const bool bEnableScissor )
{
	Assert( (nLeft <= nRight) && (nTop <= nBottom) ); //360 craps itself if this isn't true
	if ( !g_pHardwareConfig->Caps().m_bScissorSupported )
		return;

	DWORD dwEnableScissor = bEnableScissor ? TRUE : FALSE;
	RECT newScissorRect;
	newScissorRect.left = nLeft;
	newScissorRect.top = nTop;
	newScissorRect.right = nRight;
	newScissorRect.bottom = nBottom;

	// If we're turning it on, check the validity of the rect
	if ( bEnableScissor )
	{
		int nWidth, nHeight;
		ITexture *pTexture = GetRenderTargetEx( 0 );
		if ( pTexture == NULL )
		{
			GetBackBufferDimensions( nWidth, nHeight );
		}
		else
		{
			nWidth  = pTexture->GetActualWidth();
			nHeight = pTexture->GetActualHeight();
		}

		Assert( (nRight <= nWidth) && (nBottom <= nHeight) && ( nTop >= 0 ) && (nLeft >= 0) );

		newScissorRect.left   = clamp( newScissorRect.left,   0, nWidth );
		newScissorRect.top    = clamp( newScissorRect.top,    0, nHeight );
		newScissorRect.right  = clamp( newScissorRect.right,  0, nWidth );
		newScissorRect.bottom = clamp( newScissorRect.bottom, 0, nHeight );
	}

	if ( !m_bResettingRenderState )
	{
		bool bEnableChanged = m_DesiredState.m_RenderState[D3DRS_SCISSORTESTENABLE] != dwEnableScissor;
		bool bRectChanged = memcmp( &newScissorRect, &m_DesiredState.m_ScissorRect, sizeof(RECT) ) != 0;

		if ( !bEnableChanged && !bRectChanged )
			return;
	}

	m_DesiredState.m_RenderState[D3DRS_SCISSORTESTENABLE] = dwEnableScissor;
	memcpy( &m_DesiredState.m_ScissorRect, &newScissorRect, sizeof(RECT) );

	ADD_COMMIT_FUNC( COMMIT_PER_DRAW, CommitSetScissorRect );
}