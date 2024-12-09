CChildFrame *CHexEditView::GetFrame() const
{
	CWnd *pp = GetParent();
	while (pp != NULL && !pp->IsKindOf(RUNTIME_CLASS(CChildFrame)))
		pp = pp->GetParent();
	ASSERT_KINDOF(CChildFrame, pp);

	return (CChildFrame *)pp;
}