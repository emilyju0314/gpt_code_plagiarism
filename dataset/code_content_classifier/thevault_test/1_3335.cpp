void CCalcDlg::OnSelLenStore()
{
	// First check that we can perform an integer operation
	if (state_ == CALCERROR)
	{
		make_noise("Calculator Error");
		AvoidableTaskDialog(IDS_CALC_ERROR,
			"You cannot perform this operation on an invalid value.",
			"The previous calculation caused an error.\n\n"
				"Please press the calculator \"Clear\" button to continue.");
		//mm_->StatusBarText("Operation on invalid value.");
		aa_->mac_error_ = 10;
		return;
	}
	else if (state_ > CALCINTEXPR)
	{
		not_int_error();
		return;
	}

	CHexEditView *pview = GetView();
	if (pview == NULL)
	{
		no_file_error();
		return;
	}

	FILE_ADDRESS start, end;
	pview->GetSelAddr(start, end);

	mpz_class eof, addr, len;
	mpz_set_ui64(eof.get_mpz_t(), pview->GetDocument()->length());   // current eof
	mpz_set_ui64(addr.get_mpz_t(), start);
	len = get_norm(current_);

	if (len < 0)
	{
		TaskMessageBox("Negative selection length",
			"The calculator cannot make a selection with length less than zero.");
		aa_->mac_error_ = 10;
		return;
	}
	if (addr + len > eof)
	{
		TaskMessageBox("Selection past EOF",
			"The calculator cannot make a selection which extends past the end of file.");
		aa_->mac_error_ = 10;
		return;
	}
	len += addr;
	pview->MoveToAddress(mpz_get_ui64(addr.get_mpz_t()), mpz_get_ui64(len.get_mpz_t()));

	//if (!aa_->refresh_off_ && IsVisible())
	//{
	//	edit_.SetFocus();
	//	edit_.Put();
	//	// update_file_buttons(); // done indirectly through MoveToAddress
	//}

	save_value_to_macro();
	aa_->SaveToMacro(km_sellenstore);
}