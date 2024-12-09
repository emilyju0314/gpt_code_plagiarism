bool CTexture::ConvertToActualFormat( IVTFTexture *pVTFTexture )
{
	if ( !g_pShaderDevice->IsUsingGraphics() )
		return false;

	bool bConverted = false;

	ImageFormat fmt = m_ImageFormat;
	ImageFormat dstFormat = ComputeActualFormat( pVTFTexture->Format() );
#ifdef PLATFORM_OSX
	if ( IsVolumeTexture() && ImageLoader::IsCompressed( dstFormat ) )
	{
		// OSX does not support compressed 3d textures
		dstFormat = IMAGE_FORMAT_RGBA8888;
	}
#endif
	if ( fmt != dstFormat )
	{
		Assert( !IsGameConsole() );
		pVTFTexture->ConvertImageFormat( dstFormat, false );
		m_ImageFormat = dstFormat;
		bConverted = true;
	}
#ifndef _PS3
	// No reason to do this conversion on PS3
	else if ( HardwareConfig()->GetHDRType() == HDR_TYPE_INTEGER &&
		     fmt == dstFormat && dstFormat == IMAGE_FORMAT_RGBA16161616F )
	{
		// This is to force at most the precision of int16 for fp16 texture when running the integer path.
		pVTFTexture->ConvertImageFormat( IMAGE_FORMAT_RGBA16161616, false );
		pVTFTexture->ConvertImageFormat( IMAGE_FORMAT_RGBA16161616F, false );
		bConverted = true;
	}
#endif // !_PS3

	return bConverted;
}