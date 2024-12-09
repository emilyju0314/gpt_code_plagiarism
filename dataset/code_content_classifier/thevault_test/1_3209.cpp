void CHexEditView::OnUpdateSelNZ(CCmdUI* pCmdUI)
{
	FILE_ADDRESS start_addr, end_addr;              // Current selection
	GetSelAddr(start_addr, end_addr);
	pCmdUI->Enable(start_addr < end_addr);
}