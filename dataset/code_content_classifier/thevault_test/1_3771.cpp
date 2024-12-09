void CTexture::SetTextureRegenerator( ITextureRegenerator *pTextureRegen, bool releaseExisting )
{
	// NOTE: These can only be used by procedural textures
	Assert( IsProcedural() );

	if ( m_pTextureRegenerator && releaseExisting )
	{
		m_pTextureRegenerator->Release();
	}
	m_pTextureRegenerator = pTextureRegen; 
}