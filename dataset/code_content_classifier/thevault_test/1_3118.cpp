void CCompareView::OnCompPrev()
{
	FILE_ADDRESS start, end;  // current selection
	GetSelAddr(start, end);

	std::pair<FILE_ADDRESS, FILE_ADDRESS> locn = GetDocument()->GetPrevOtherDiff(start - 1);
	if (locn.first > -1)
	{
		FILE_ADDRESS len = abs(int(locn.second));
		MoveToAddress(locn.first, locn.first + len);
	}
}