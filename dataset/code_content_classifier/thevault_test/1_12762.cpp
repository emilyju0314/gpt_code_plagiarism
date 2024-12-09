HRESULT CDRGTexture::Restore(LPDIRECT3DDEVICE7 pd3dDevice )
{
    // Check params
    if( NULL == pd3dDevice )
        return DDERR_INVALIDPARAMS;

	// Release previously created object
    SAFE_RELEASE( ptexTexture );
    
	// Restore the texture surface from the bitmap image. At this point, code
	// can be added to handle other texture formats, such as those created from
	// .dds files, .jpg files, or whatever else.
	return RestoreFromBitmap( pd3dDevice );
}