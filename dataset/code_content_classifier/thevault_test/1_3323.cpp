void CCalcDlg::OnGo()                   // Move cursor to current value
{
	CHexEditView *pview = GetView();
	if (pview == NULL)
	{
		// This should not happen unless we are playing back a macro
		no_file_error();
		return;
	}

	if (state_ == CALCERROR)
	{
		make_noise("Calculator Error");
		AvoidableTaskDialog(IDS_CALC_ERROR,
			"You cannot perform this operation on an invalid value.",
			"The previous calculation caused an error.\n\n"
				"Please press the calculator \"Clear\" button to continue.");
		//mm_->StatusBarText("Jump with invalid value.");
		aa_->mac_error_ = 10;
		return;
	}
	else if (state_ > CALCINTEXPR)
	{
		not_int_error();
		return;
	}
	else if (state_ == CALCINTEXPR)
	{
		state_ = edit_.update_value(true);           // re-eval the expression allowing side-effects now
		ASSERT(state_ == CALCINTEXPR);
		state_ = CALCINTLIT;   // This is so that edit_.put() [below] will use current_ instead of current_str_
	}

	// First work out if we are jumping by address or sector
	bool sector = ctl_go_.m_nMenuResult == ID_GOSECTOR;

	// If the value in current_ is not there as a result of a calculation then
	// save it before it is lost.
	save_value_to_macro();

	calc_binary();
	check_for_error();   // check for overflow/error
	edit_.put();

	add_hist();
	// xxx make sure it also gets added to hex or dec jump list
	edit_.put();

	CString ss;
	edit_.GetWindowText(ss);
	if (sector)
	{
		ss = "Go To sector " + ss + " ";
	}
	else if (radix_ == 16)
	{
		mm_->NewHexJump(ss);             // update jump tools with new address
		ss = "Go To (hex) " + ss + " ";
	}
	else if (radix_ == 10)
	{
		mm_->NewDecJump(ss);
		ss = "Go To (decimal) " + ss + " ";
	}
	else
	{
		ss = "Go To (calc) " + ss + " ";
	}

	mpz_class addr, eof, sector_size;
	addr = get_norm(current_);
	if (addr < 0)
	{
		TaskMessageBox("Jump to negative address",
			"The calculator cannot jump to an address before the start of file.");
		aa_->mac_error_ = 10;
		return;
	}

	mpz_set_ui64(eof.get_mpz_t(), pview->GetDocument()->length());
	mpz_set_ui64(sector_size.get_mpz_t(), pview->GetDocument()->GetSectorSize());

	if (sector && sector_size > 0)
		addr *= sector_size;

	if (addr > eof)
	{
		TaskMessageBox("Jump past EOF",
			"The calculator cannot jump to an address past the end of file.");
		aa_->mac_error_ = 10;
		return;
	}

	pview->MoveWithDesc(ss, mpz_get_ui64(addr.get_mpz_t()));

	// Give view the focus
	if (pview != pview->GetFocus())
		pview->SetFocus();

	state_ = CALCINTRES;
	//orig_radix_ = radix_;    // remember starting radix

	source_ = km_result;
	aa_->SaveToMacro(km_go);
}