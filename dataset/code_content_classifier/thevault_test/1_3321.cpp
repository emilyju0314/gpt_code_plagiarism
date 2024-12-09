void CCalcDlg::update_digit_buttons()
{
	// Enable/disable digit keys depending on base
	button_colour(GetDlgItem(IDC_DIGIT_2), radix_ > 2, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_3), radix_ > 3, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_4), radix_ > 4, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_5), radix_ > 5, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_6), radix_ > 6, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_7), radix_ > 7, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_8), radix_ > 8, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_9), radix_ > 9, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_A), radix_ > 10, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_B), radix_ > 11, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_C), radix_ > 12, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_D), radix_ > 13, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_E), radix_ > 14, RGB(0x40, 0x40, 0x40));
	button_colour(GetDlgItem(IDC_DIGIT_F), radix_ > 15, RGB(0x40, 0x40, 0x40));
}