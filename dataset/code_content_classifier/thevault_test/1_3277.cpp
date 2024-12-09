void CPropBitmapPage::hide_disk_info(bool hide)
{
	GetDlgItem(IDC_BMP_DESC_DISK)->ShowWindow(hide ? SW_HIDE : SW_SHOW);
	GetDlgItem(IDC_BMP_FORMAT_DISK)->ShowWindow(hide ? SW_HIDE : SW_SHOW);
	GetDlgItem(IDC_BMP_BPP_DISK)->ShowWindow(hide ? SW_HIDE : SW_SHOW);
	GetDlgItem(IDC_BMP_WIDTH_DISK)->ShowWindow(hide ? SW_HIDE : SW_SHOW);
	GetDlgItem(IDC_BMP_HEIGHT_DISK)->ShowWindow(hide ? SW_HIDE : SW_SHOW);
}