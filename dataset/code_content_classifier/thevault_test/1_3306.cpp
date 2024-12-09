void CXmlTree::CFrag::InsertKids(CElt *pelt, const CElt *before)
{
	ASSERT(m_powner != NULL && m_pfrag != NULL);
	ASSERT(before == NULL || before->m_powner == m_powner);
	if (before != NULL)
		pelt->m_pelt->insertBefore(m_pfrag, _variant_t((IDispatch *)(before->m_pelt)));
	else
		pelt->m_pelt->insertBefore(m_pfrag, _variant_t());
	pelt->GetOwner()->SetModified(true);
}