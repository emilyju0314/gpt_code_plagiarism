void CHexEditView::OnCompNext()
{
	FILE_ADDRESS start, end;  // current selection
	GetSelAddr(start, end);

	std::pair<FILE_ADDRESS, FILE_ADDRESS> locn = GetDocument()->GetNextDiff(start < end ? end - 1 : end);
	if (locn.first  > -1)
	{
		FILE_ADDRESS len = abs(int(locn.second));
		MoveToAddress(locn.first, locn.first + len);
	}
}