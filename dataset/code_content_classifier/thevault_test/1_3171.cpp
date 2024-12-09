FILE_ADDRESS CHexEditView::GoAddress(FILE_ADDRESS start_addr, FILE_ADDRESS end_addr /*=-1*/)
{
	// Get row from top 2 bits of start_address (vert_display mode)
	int row = int(start_addr>>62) & 0x3;
	start_addr &= 0x3fffFFFFffffFFFF;

	if (end_addr < 0 || end_addr > GetDocument()->length())
		end_addr = start_addr;
	if (start_addr < 0 || start_addr > GetDocument()->length())
		start_addr = end_addr = GetDocument()->length();

	ASSERT(row == 0 || (row < 3 && display_.vert_display && start_addr == end_addr));
	SetSel(addr2pos(start_addr, row), addr2pos(end_addr, row));

	return start_addr;
}