void CTexture::SetFilterState()
{
	// Turns off filtering when we're point sampling
	if( m_nFlags & TEXTUREFLAGS_POINTSAMPLE )
	{
		g_pShaderAPI->TexMinFilter( SHADER_TEXFILTERMODE_NEAREST );
		g_pShaderAPI->TexMagFilter( SHADER_TEXFILTERMODE_NEAREST );
		return;
	}

	// NOTE: config.bMipMapTextures and config.bFilterTextures is handled in ShaderAPIDX8
	bool bEnableMipmapping = ( m_nFlags & TEXTUREFLAGS_NOMIP ) ? false : true;
	if( !bEnableMipmapping )
	{
		g_pShaderAPI->TexMinFilter( SHADER_TEXFILTERMODE_LINEAR );
		g_pShaderAPI->TexMagFilter( SHADER_TEXFILTERMODE_LINEAR );
		return;
	}

	// Determing the filtering mode
	bool bIsAnisotropic = false; bool bIsTrilinear = false;
	if ( (g_config.m_nForceAnisotropicLevel > 1) && (HardwareConfig()->MaximumAnisotropicLevel() > 1) )
	{
		bIsAnisotropic = true;
	}
	else
	{
		bIsAnisotropic = (( m_nFlags & TEXTUREFLAGS_ANISOTROPIC ) != 0) && (HardwareConfig()->MaximumAnisotropicLevel() > 1);
		bIsTrilinear = ( g_config.m_nForceAnisotropicLevel == 1 ) || ( ( m_nFlags & TEXTUREFLAGS_TRILINEAR ) != 0 );
	}

	if ( bIsAnisotropic )
	{		    
		g_pShaderAPI->TexMinFilter( SHADER_TEXFILTERMODE_ANISOTROPIC );
		g_pShaderAPI->TexMagFilter( SHADER_TEXFILTERMODE_ANISOTROPIC );
	}
	else
	{
		if ( bIsTrilinear )
		{
			g_pShaderAPI->TexMinFilter( SHADER_TEXFILTERMODE_LINEAR_MIPMAP_LINEAR );
			g_pShaderAPI->TexMagFilter( SHADER_TEXFILTERMODE_LINEAR );
		}
		else
		{
			g_pShaderAPI->TexMinFilter( SHADER_TEXFILTERMODE_LINEAR_MIPMAP_NEAREST );
			g_pShaderAPI->TexMagFilter( SHADER_TEXFILTERMODE_LINEAR );
		}
	}
}