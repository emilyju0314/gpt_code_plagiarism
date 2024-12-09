static auto CurrentDialogItemA(HANDLE hDlg, int ItemNumber)
{
	const auto current = FindDialogData(hDlg);
	return current ? &current->diA[ItemNumber] : nullptr;
}