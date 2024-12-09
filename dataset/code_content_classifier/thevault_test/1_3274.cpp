CHexEditView *CHexEditDoc::GetBestView()
{
	CView *pbest = NULL;
	CView *pactive = ::GetView();  // returns the hex view associated with the active view

	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView *pview = GetNextView(pos);
		if (pview != NULL && pbest == NULL && pview->IsKindOf(RUNTIME_CLASS(CHexEditView)))
			pbest = pview;
		else if (pview == pactive)
		{
			pbest = pview;
			break;
		}
	}
	return (CHexEditView *)pbest;
}