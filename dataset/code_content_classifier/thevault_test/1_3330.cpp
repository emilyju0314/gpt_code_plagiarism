void CCalcDlg::build_menus()
{
	static clock_t last_hex_hist_build = (clock_t)0;
	static clock_t last_dec_hist_build = (clock_t)0;
	static clock_t last_var_build = (clock_t)0;
	CMenu mm, msub;

	if (last_hex_hist_build < mm_->hex_hist_changed_)
	{
		// Hex jump tool history menu
		mm.CreatePopupMenu();
		if (mm_->hex_hist_.size() == 0)
		{
			// Display a single disabled menu item, since
			// disabling the button itself looks ugly
			mm.AppendMenu(MF_STRING | MF_GRAYED, 0, "(none)");
		}
		else
		{
			for (size_t ii = 0; ii < mm_->hex_hist_.size(); ++ii)
			{
				// Store filter and use index as menu item ID (but add 1 since 0 means no ID used).
				mm.AppendMenu(MF_STRING, ii + 1, mm_->hex_hist_[ii]);
			}
		}
		if (ctl_hex_hist_.m_hMenu != (HMENU)0)
		{
			::DestroyMenu(ctl_hex_hist_.m_hMenu);
			ctl_hex_hist_.m_hMenu = (HMENU)0;
		}
		ctl_hex_hist_.m_hMenu = mm.GetSafeHmenu();
		mm.Detach();

		last_hex_hist_build = mm_->hex_hist_changed_;
	}

	if (last_dec_hist_build < mm_->dec_hist_changed_)
	{
		// Decimal jump tool history
		mm.CreatePopupMenu();
		if (mm_->dec_hist_.size() == 0)
		{
			// Display a single disabled menu item, since
			// disabling the button itself looks ugly
			mm.AppendMenu(MF_STRING | MF_GRAYED, 0, "(none)");
		}
		else
		{
			for (size_t ii = 0; ii < mm_->dec_hist_.size(); ++ii)
			{
				// Store filter and use index as menu item ID (but add 1 since 0 means no ID used).
				mm.AppendMenu(MF_STRING, ii + 1, mm_->dec_hist_[ii]);
			}
		}
		if (ctl_dec_hist_.m_hMenu != (HMENU)0)
		{
			::DestroyMenu(ctl_dec_hist_.m_hMenu);
			ctl_dec_hist_.m_hMenu = (HMENU)0;
		}
		ctl_dec_hist_.m_hMenu = mm.GetSafeHmenu();
		mm.Detach();

		last_dec_hist_build = mm_->dec_hist_changed_;
	}

	if (last_var_build < mm_->expr_.VarChanged())
	{
		int ii = 1;                // Just used to make sure each menu item has a unique ID
		vector <CString> varNames;
		mm.CreatePopupMenu();

		varNames = mm_->expr_.GetVarNames(CJumpExpr::TYPE_INT);
		if (!varNames.empty())
		{
			msub.CreatePopupMenu();
			for (vector<CString>::const_iterator ps = varNames.begin(); ps != varNames.end(); ++ps)
			{
				msub.AppendMenu(MF_STRING, ii++, *ps);
			}
			if (msub.GetMenuItemCount() > 0)
				mm.AppendMenu(MF_POPUP, (UINT)msub.m_hMenu, "&Integer");
			msub.DestroyMenu();
		}

		varNames = mm_->expr_.GetVarNames(CJumpExpr::TYPE_REAL);
		if (!varNames.empty())
		{
			msub.CreatePopupMenu();
			for (vector<CString>::const_iterator ps = varNames.begin(); ps != varNames.end(); ++ps)
			{
				msub.AppendMenu(MF_STRING, ii++, *ps);
			}
			if (msub.GetMenuItemCount() > 0)
				mm.AppendMenu(MF_POPUP, (UINT)msub.m_hMenu, "&Real");
			msub.DestroyMenu();
		}

		varNames = mm_->expr_.GetVarNames(CJumpExpr::TYPE_STRING);
		if (!varNames.empty())
		{
			msub.CreatePopupMenu();
			for (vector<CString>::const_iterator ps = varNames.begin(); ps != varNames.end(); ++ps)
			{
				msub.AppendMenu(MF_STRING, ii++, *ps);
			}
			if (msub.GetMenuItemCount() > 0)
				mm.AppendMenu(MF_POPUP, (UINT)msub.m_hMenu, "&String");
			msub.DestroyMenu();
		}

		varNames = mm_->expr_.GetVarNames(CJumpExpr::TYPE_BOOLEAN);
		if (!varNames.empty())
		{
			msub.CreatePopupMenu();
			for (vector<CString>::const_iterator ps = varNames.begin(); ps != varNames.end(); ++ps)
			{
				msub.AppendMenu(MF_STRING, ii++, *ps);
			}
			if (msub.GetMenuItemCount() > 0)
				mm.AppendMenu(MF_POPUP, (UINT)msub.m_hMenu, "&Boolean");
			msub.DestroyMenu();
		}

		varNames = mm_->expr_.GetVarNames(CJumpExpr::TYPE_DATE);
		if (!varNames.empty())
		{
			msub.CreatePopupMenu();
			for (vector<CString>::const_iterator ps = varNames.begin(); ps != varNames.end(); ++ps)
			{
				msub.AppendMenu(MF_STRING, ii++, *ps);
			}
			if (msub.GetMenuItemCount() > 0)
				mm.AppendMenu(MF_POPUP, (UINT)msub.m_hMenu, "&Date");
			msub.DestroyMenu();
		}

		if (mm.GetMenuItemCount() == 0)
		{
			// If there are no vars then display a single disabled
			// menu item, since disabling the button itself looks ugly.
			mm.AppendMenu(MF_STRING | MF_GRAYED, 0, "(none)");
		}
		else
		{
			// Add menu item to allow all varibales to be deleted
			mm.AppendMenu(MF_STRING, ID_VARS_CLEAR, "&Clear variables...");
		}
		if (ctl_vars_.m_hMenu != (HMENU)0)
		{
			::DestroyMenu(ctl_vars_.m_hMenu);
			ctl_vars_.m_hMenu = (HMENU)0;
		}
		ctl_vars_.m_hMenu = mm.GetSafeHmenu();
		mm.Detach();

		last_var_build = mm_->expr_.VarChanged();
	}
}