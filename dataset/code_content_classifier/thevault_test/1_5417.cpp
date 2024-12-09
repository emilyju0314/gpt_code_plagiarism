HRESULT D3DUtil_CreateVertexShader( LPDIRECT3DDEVICE8 pd3dDevice, 
                                    TCHAR* strFilename, DWORD* pdwVertexDecl,
                                    DWORD* pdwVertexShader )
{
    LPD3DXBUFFER pCode;
    TCHAR        strPath[MAX_PATH];
    HRESULT      hr;

    // Get the path to the vertex shader file
    //DXUtil_FindMediaFile( strPath, strFilename );

    // Assemble the vertex shader file
    if( FAILED( hr = D3DXAssembleShaderFromFile( strPath, 0, NULL, &pCode, NULL ) ) )
        return hr;

    // Create the vertex shader
    hr = pd3dDevice->CreateVertexShader( pdwVertexDecl, 
                                         (DWORD*)pCode->GetBufferPointer(),
                                         pdwVertexShader, 0 );
    pCode->Release();
    return hr;
}