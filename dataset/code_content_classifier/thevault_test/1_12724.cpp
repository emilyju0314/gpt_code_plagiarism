HRESULT	CDRGObject::CheckAgainstChildren(CDRGObject	*pPotentialParent, CDRGObject *pPotentialChild)
{
	CDRGObject	*pTempObject = pPotentialChild;

	//skip to end of list, comparing against parent object
	while (pTempObject != NULL)
	{
		if(pPotentialChild == pPotentialParent)
			return E_FAIL;

		pTempObject = pTempObject->m_pNext;
	}

	//if we got here, none of the siblings was the potential parent
	if (pPotentialChild->m_pFirstChild == NULL)
		return S_OK;
	else
		return CheckAgainstChildren(pPotentialParent, pPotentialChild->m_pFirstChild);
}