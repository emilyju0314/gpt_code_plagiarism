void CTexture::SwapContents( ITexture *pOther )
{
	if( (pOther == NULL) || (pOther == this) )
		return;

	ICallQueue *pCallQueue = materials->GetRenderContext()->GetCallQueue();
	if ( pCallQueue )
	{
		pCallQueue->QueueCall( this, &CTexture::SwapContents, pOther );
		return;
	}

	AssertMsg( dynamic_cast<CTexture *>(pOther) != NULL, "Texture swapping broken" );

	CTexture *pOtherAsCTexture = (CTexture *)pOther;

	CTexture *pTemp = (CTexture *)stackalloc( sizeof( CTexture ) );
	
	//swap everything
	memcpy( (void *)pTemp, (void *)this, sizeof( CTexture ) );
	memcpy( (void *)this, (void *)pOtherAsCTexture, sizeof( CTexture ) );
	memcpy( (void *)pOtherAsCTexture, (void *)pTemp, sizeof( CTexture ) );

	//we have the other's name, give it back
	memcpy( &pOtherAsCTexture->m_Name, &m_Name, sizeof( m_Name ) );

	//pTemp still has our name
	memcpy( &m_Name, &pTemp->m_Name, sizeof( m_Name ) );
}