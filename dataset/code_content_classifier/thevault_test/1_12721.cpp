HRESULT CDRGObject::SetupIndexedVertexBuffer()
{
	HRESULT hr;

	if (m_pIndexedVertexBuffer != NULL)
		SAFE_RELEASE(m_pIndexedVertexBuffer);
	
	// Define the vertex buffer descriptor for creating the
	// vertex buffer for DrawIndexedPrimitiveVB
    D3DVERTEXBUFFERDESC vbIndexedDesc;
    ZeroMemory(&vbIndexedDesc, sizeof(D3DVERTEXBUFFERDESC));
    vbIndexedDesc.dwSize        = sizeof(D3DVERTEXBUFFERDESC);
	
	// need to specify SysMem if on the RGB software renderer or regular HAL
	if ((m_pWrapper->m_bHardware) && 
		(m_pWrapper->m_pCurrentDevice->ddDeviceDesc.dwDevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT ))
	{
		//for TnL HAL, need to let the driver decide where to put it
		vbIndexedDesc.dwCaps        = 0l;
	}
	else
	{
		//for regular hal, or rgb sw, need to specify sysmem
		vbIndexedDesc.dwCaps        = D3DVBCAPS_SYSTEMMEMORY ;
	}
	
    vbIndexedDesc.dwFVF         = D3DFVF_VERTEX;

    vbIndexedDesc.dwNumVertices = m_iNumVertices;
    
    // Create a vertex buffer using D3D7 interface
	if(m_pWrapper)
	{
		if (m_pWrapper->m_pD3D7)
		{
		if ( FAILED( hr = m_pWrapper->m_pD3D7->CreateVertexBuffer(&vbIndexedDesc, 
		                                                    &m_pIndexedVertexBuffer, 0)))
			return hr;
 
		D3DVERTEX	*pTemp;

		if ( FAILED( hr = m_pIndexedVertexBuffer->Lock( DDLOCK_WAIT, (VOID **)&pTemp, NULL ) ) )
			return hr;

		memcpy(pTemp,m_pVertices,m_iNumVertices * sizeof(D3DVERTEX));

		if ( FAILED( hr = m_pIndexedVertexBuffer->Unlock() ) )
			return hr;
		}
	}

	return S_OK;
}