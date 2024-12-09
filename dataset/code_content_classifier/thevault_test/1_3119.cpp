void CCompareView::OnCompNext()
{
	FILE_ADDRESS start, end;  // current selection
	GetSelAddr(start, end);

	std::pair<FILE_ADDRESS, FILE_ADDRESS> locn = GetDocument()->GetNextOtherDiff(start < end ? end - 1 : end);
	if (locn.first > -1)
	{
		FILE_ADDRESS len = abs(int(locn.second));
		MoveToAddress(locn.first, locn.first + len);
	}
}