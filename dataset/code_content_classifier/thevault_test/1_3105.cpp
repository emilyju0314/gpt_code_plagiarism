void CHexEditApp::StopSearches()
{
	POSITION posn = m_pDocTemplate->GetFirstDocPosition();
	while (posn != NULL)
	{
		CHexEditDoc *pdoc = dynamic_cast<CHexEditDoc *>(m_pDocTemplate->GetNextDoc(posn));
		ASSERT(pdoc != NULL);
		pdoc->StopSearch();
	}
}