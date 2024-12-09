void CHexEditView::show_prop(FILE_ADDRESS address /*=-1*/)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
	if (address != -2 && aa->refresh_off_) return;

	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	if (address < 0) address = GetPos();
	mm->m_wndProp.Update(this, address);
}