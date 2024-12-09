HRESULT CDRGText::ResizeAllStrings()
{
	DRGString	*pCurrString = pFirstString;

	float Hdifference = (float)pDRGWrapper->m_dwRenderWidth / (float)dwLastScreenHRes;
	float Vdifference = (float)pDRGWrapper->m_dwRenderHeight / (float)dwLastScreenVRes;


	while (pCurrString !=NULL) //while not null
	{
		for (int i = 0; i<pCurrString->iStringLen*6; i++)
		{
			//offset verts by change in resolution X current position
			pCurrString->pVerts[i].sx = (Hdifference * pCurrString->pVerts[i].sx);
			pCurrString->pVerts[i].sy = (Vdifference * pCurrString->pVerts[i].sy);
		}
		pCurrString = pCurrString->pNext;
	}

	dwLastScreenHRes = pDRGWrapper->m_dwRenderWidth;
	dwLastScreenVRes = pDRGWrapper->m_dwRenderHeight;
	
	return S_OK; //return the last DrawPrim result.	
}