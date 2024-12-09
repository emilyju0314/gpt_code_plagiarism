void CCalcDlg::OnGetHexHist()
{
	if (ctl_hex_hist_.m_nMenuResult != 0)
	{
		// Get the text of the menu item selected
		CMenu menu;
		menu.Attach(ctl_hex_hist_.m_hMenu);
		CString ss = get_menu_text(&menu, ctl_hex_hist_.m_nMenuResult);
		menu.Detach();
		ss.Replace(" ", "");    // get rid of padding

		// We clear the current edit box before adding the chars in 2 cases:
		// 1. Displaying result - probably want to start a new calculation
		// 2. Currently just displaying a numeric value - replace it as adding extra digits is just confusing
		//    and otherwise adding more digits may cause an overflow which would be really confusing
		//if (state_ != CALCOTHER)
		if (state_ <= CALCINTLIT || state_>= CALCOTHRES)
		{
			edit_.SetWindowText("");
			state_ = CALCINTUNARY;
		}

		if (radix_ != 16)
		{
			// We need to convert the hex digits to digits in the current radix
			__int64 ii = ::_strtoui64(ss, NULL, 16);
			char buf[72];
			::_i64toa(ii, buf, radix_);
			ss = buf;
		}

		CString strCurr;
		edit_.GetWindowText(strCurr);

		edit_.SetFocus();
		edit_.SetSel(edit_.GetWindowTextLength(), -1);

		if (!strCurr.IsEmpty() && !isspace(strCurr[strCurr.GetLength()-1]))
			edit_.SendMessage(WM_CHAR, (TCHAR)' ');
		for (int ii = 0; ii < ss.GetLength (); ii++)
			edit_.SendMessage(WM_CHAR, (TCHAR)ss[ii]);

		//SetDlgItemText(IDC_OP_DISPLAY, "");
		inedit(km_user_str);
	}
}