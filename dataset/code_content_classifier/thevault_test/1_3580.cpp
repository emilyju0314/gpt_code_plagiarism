void CShaderAPIDx8::AdvanceCurrentCopy( ShaderAPITextureHandle_t hTexture )
{
	// May need to switch textures....
	Texture_t& tex = GetTexture( hTexture );
	if (tex.m_NumCopies > 1)
	{
		if (++tex.m_CurrentCopy >= tex.m_NumCopies)
			tex.m_CurrentCopy = 0;

		// When the current copy changes, we need to make sure this texture
		// isn't bound to any stages any more; thereby guaranteeing the new
		// copy will be re-bound.
		UnbindTexture( hTexture );
	}
}