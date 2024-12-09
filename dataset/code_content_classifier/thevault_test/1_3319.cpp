void CCalcDlg::do_digit(char digit)
{
	// Since digit buttons are "enabled" (but greyed) even when invalid we need to check for invalid digits
	int val = isdigit(digit) ? (digit - '0') : digit - 'A' + 10;
	if (val >= radix_)
	{
#ifdef SYS_SOUNDS
		if (!CSystemSound::Play("Invalid Character"))
#endif
			::Beep(5000,200);
		return;
	}

	edit_.SendMessage(WM_CHAR, digit, 1);
}