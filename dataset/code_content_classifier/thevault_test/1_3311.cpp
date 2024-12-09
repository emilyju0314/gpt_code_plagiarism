void CCalcDlg::StartEdit()
{
	edit_.SetFocus();
	//edit_.SetSel(edit_.GetWindowTextLength(), -1);  // move caret to end
	edit_.SetSel(0, -1);                              // select all
}