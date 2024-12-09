void CShaderAPIDx8::ReleaseShaderObjects( bool bReleaseManagedResources /*= true*/ )
{
	ReleaseInternalRenderTargets();
	EvictManagedResourcesInternal();	

	// FIXME: Move into shaderdevice when textures move over.

#ifdef _DEBUG
	// Helps to find the unreleased textures.
	if ( TextureCount() > 0 && bReleaseManagedResources )
	{
		ShaderAPITextureHandle_t hTexture;
		for ( hTexture = m_Textures.Head(); hTexture != m_Textures.InvalidIndex(); hTexture = m_Textures.Next( hTexture ) )
		{
			if ( GetTexture( hTexture ).m_NumCopies == 1 )
			{
				if ( GetTexture( hTexture ).GetTexture() )
				{
					Warning( "Didn't correctly clean up texture 0x%8.8x (%s)\n", hTexture, GetTexture( hTexture ).m_DebugName.String() ); 
				}
			}
			else
			{
				for ( int k = GetTexture( hTexture ).m_NumCopies; --k >= 0; )
				{
					if ( GetTexture( hTexture ).GetTexture( k ) != 0 )
					{
						Warning( "Didn't correctly clean up texture 0x%8.8x (%s)\n", hTexture, GetTexture( hTexture ).m_DebugName.String() ); 
						break;
					}
				}
			}
		}
	}
#endif

	Assert( !bReleaseManagedResources || TextureCount() == 0 );
}