void CHexEditApp::StartSearches(CHexEditDoc *pp)
{
	POSITION posn = m_pDocTemplate->GetFirstDocPosition();
	while (posn != NULL)
	{
		CHexEditDoc *pdoc = dynamic_cast<CHexEditDoc *>(m_pDocTemplate->GetNextDoc(posn));
		ASSERT(pdoc != NULL);
		if (pdoc != pp)
		{
			CHexEditView *pview = pdoc->GetBestView();
			ASSERT(pview != NULL);
			pdoc->base_addr_ = theApp.align_rel_ ? pview->GetSearchBase() : 0;
			pdoc->StartSearch();
		}
	}
}