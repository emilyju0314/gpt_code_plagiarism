int CMatLightmaps::GetMaxLightmapPageWidth() const
{
	// FIXME: It's unclear which we want here.
	// It doesn't drastically increase primitives per DrawIndexedPrimitive
	// call at the moment to increase it, so let's not for now.
	
	// If we're using dynamic textures though, we want bigger that's for sure.
	// The tradeoff here is how much memory we waste if we don't fill the lightmap

	// We need to go to 512x256 textures because that's the only way bumped
	// lighting on displacements can work given the 128x128 allowance..
	int nWidth = 512;
	if ( nWidth > HardwareConfig()->MaxTextureWidth() )
		nWidth = HardwareConfig()->MaxTextureWidth();

	return nWidth;
}