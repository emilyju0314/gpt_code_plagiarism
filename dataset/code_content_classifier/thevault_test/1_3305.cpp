void CXmlTree::CFrag::SaveKids(CElt *pelt)
{
	ASSERT(m_pfrag != NULL);
	CElt child;

//    for (child = pelt->GetFirstChild(); !child.IsEmpty(); ++child)
//        m_pfrag->appendChild(child.m_pelt->cloneNode(VARIANT_TRUE));

	// First move all the child nodes to the fragment
	for (child = pelt->GetFirstChild(); !child.IsEmpty(); child = pelt->GetFirstChild())
		m_pfrag->appendChild(child.m_pelt);

	// Now clone all the moved nodes and add them back
	MSXML2::IXMLDOMNodePtr pnode;

	for (pnode = m_pfrag->firstChild; pnode != NULL; pnode = pnode->nextSibling)
		pelt->m_pelt->appendChild(pnode->cloneNode(VARIANT_TRUE));
}