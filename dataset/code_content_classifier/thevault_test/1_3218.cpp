void CHexEditView::OnCompLast()
{
	std::pair<FILE_ADDRESS, FILE_ADDRESS> locn = GetDocument()->GetLastDiff();
	if (locn.first > -1)
	{
		FILE_ADDRESS len = abs(int(locn.second));
		MoveToAddress(locn.first, locn.first + len);
	}
}