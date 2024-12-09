HRESULT CDRGObject::LoadObject( char *szSource, CDRGObject *pRoot, DWORD dwFlags )
{
	HRESULT hr = S_OK;
    LPDIRECTXFILE           pDXFile;
    LPDIRECTXFILEENUMOBJECT pEnumObj;
    LPDIRECTXFILEDATA       pFileData;
    const GUID*             pGUID;

    // Create the file object, and register the D3DRM templates for .X files
    if( FAILED( DirectXFileCreate( &pDXFile ) ) )
        return E_FAIL;
    if( FAILED( pDXFile->RegisterTemplates( (VOID*)D3DRM_XTEMPLATES,
                                            D3DRM_XTEMPLATE_BYTES ) ) )
    {
        pDXFile->Release();
        return E_FAIL;
    }

	//
	// Open the source file or url
	//
	if( dwFlags & OBJECT_LOAD_FILE )
	{
		// Create an enumerator object, to enumerate through the .X file objects.
		// This will open the file in the current directory.
		hr = pDXFile->CreateEnumObject( szSource, DXFILELOAD_FROMFILE, &pEnumObj );
	}
	else if( dwFlags & OBJECT_LOAD_URL )
	{
		// Create an enumerator object from an URL
		hr = pDXFile->CreateEnumObject( szSource, DXFILELOAD_FROMURL, &pEnumObj );
	}
	else
		hr = E_FAIL;
	if( FAILED(hr) )
	{
		pDXFile->Release();
		return hr;
	}

    // Cycle through each object. Parse meshes and frames as appropriate
    while( SUCCEEDED( hr = pEnumObj->GetNextDataObject( &pFileData ) ) )
    {
        pFileData->GetType( &pGUID );

        if( *pGUID == TID_D3DRMFrame )
            ParseFrame( pFileData, pRoot );

        if( *pGUID == TID_D3DRMMesh )
            ParseMesh( pFileData, pRoot );

        pFileData->Release();
    }

    // Success will result in hr == DXFILEERR_NOMOREOBJECTS
    if( DXFILEERR_NOMOREOBJECTS == hr ) 
        hr = S_OK;

    pEnumObj->Release();
    pDXFile->Release();

	return hr;
}