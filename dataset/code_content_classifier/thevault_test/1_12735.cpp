HRESULT	CDRGShader::CheckAgainstChildren(CDRGShader	*pPotentialParent, CDRGShader *pPotentialChild)
{
	CDRGShader	*pTempShader = pPotentialChild;

	//skip to end of list, comparing against parent Shader
	while (pTempShader != NULL)
	{
		if(pPotentialChild == pPotentialParent)
			return E_FAIL;

		pTempShader = pTempShader->m_pNext;
	}

	//if we got here, none of the children was the potential parent, no circular list
	if (pPotentialChild->m_pNext == NULL)
		return S_OK;
	else
		return CheckAgainstChildren(pPotentialParent, pPotentialChild->m_pNext);
}