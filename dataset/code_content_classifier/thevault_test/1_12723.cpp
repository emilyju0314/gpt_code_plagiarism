HRESULT CDRGObject::Render( DRGMatrix& drgMxWorld, bool bRenderChildren)
{
	
	HRESULT hr = S_OK;

	//Setting the material and matrix here is not the most efficient way to do it (redundant calls
	// while stepping down hierarchy) but gets around some issues with the .x file hierarchy 
	// we build right now. It's at least functional, and will be improved in a later version of 
	// the appwizard
	
	// Set the world matrix to the local matrix
	m_MxLocalToWorld =  drgMxWorld * m_MxLocalToParent ;

	int	renderpasses = 0;

	CDRGShader	*pTempShader = m_pShader;

	do
	{		
		//we don't do a apply state block if there is no shader at all at the first level
		if (m_pShader != NULL) 
		{
			m_pWrapper->m_pD3DDevice7->ApplyStateBlock(pTempShader->m_dwStateBlock);
			//You can use these for debugging			
			//OutputDebugString(pTempShader->m_strShaderName);
			//OutputDebugString(" - shader activated\n");
		}

		
		if (m_iNumVertices && m_pWrapper && m_pWrapper->m_pD3DDevice7 && m_bVisible)
		{
			m_pWrapper->m_pD3DDevice7->SetTransform( D3DTRANSFORMSTATE_WORLD, &m_MxLocalToWorld.m_Mx );
	
			// Draw the object
			// the first 0 is for where to start in the VB. For now, we are assuming one VB per object
			hr = m_pWrapper->m_pD3DDevice7->DrawIndexedPrimitiveVB( m_d3dPrimType, 
																	 m_pIndexedVertexBuffer,
																	 0, 
																	 m_iNumVertices,
																	 m_pIndices, 
																	 m_iNumIndices, 
																	 0 );
			renderpasses++;
		}
		
	
		//if the object has children, and we want to render them, now is the time
		if (bRenderChildren)
		{
			CDRGObject	*pTempObject = m_pFirstChild;
			while (pTempObject != NULL)
			{
				hr |= pTempObject->Render(m_MxLocalToWorld, true);

				// if the child we just rendered had a shader, and the next child does not,
				// then we have to reapply the parent's shader (if the parent had one)
				if ((pTempObject->m_pShader) && 
					(pTempObject->m_pNext) &&
					(pTempObject->m_pNext->m_pShader == NULL) && 
					(m_pShader != NULL) )
				{
					m_pWrapper->m_pD3DDevice7->ApplyStateBlock(m_pShader->m_dwStateBlock);
					//can be used for debugging			
					//OutputDebugString(pTempShader->m_strShaderName);
					//OutputDebugString(" - shader re-activated\n");
				}

				pTempObject = pTempObject->m_pNext;
			}
		}

		//restore world matrix
		m_pWrapper->m_pD3DDevice7->SetTransform( D3DTRANSFORMSTATE_WORLD, &drgMxWorld.m_Mx );

		//again, the if is there to ignore this the 1st time through if there is no shader
		if (m_pShader)
			pTempShader=pTempShader->m_pNext;
	}
	while (pTempShader != NULL);

	//more stuff usefull for debugging
	//char	str[255];
	//sprintf(str,"Object rendered in %d passes\n",renderpasses);
	//OutputDebugString(str);

	return hr;
}