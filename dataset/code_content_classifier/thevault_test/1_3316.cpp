void CCalcDlg::check_for_error()
{
	if (state_ > CALCINTLIT) return;

	// Check we have not overflowed bits (if we don't already have an error)
	if (state_ >= CALCINTRES &&
		bits_ > 0 &&                                // can't overflow infinite bits (bits_ == 0)
		(current_ < min_val_ || current_ > max_val_))
	{
		state_ = CALCOVERFLOW;
	}

	if (state_ == CALCERROR)
	{
		make_noise("Calculator Error");
		AvoidableTaskDialog(IDS_CALC_ERROR, (CString)current_str_);
		//mm_->StatusBarText();
		aa_->mac_error_ = 10;
	}
	else if (state_ == CALCOVERFLOW)
	{
		make_noise("Calculator Overflow");
		AvoidableTaskDialog(IDS_CALC_OVERFLOW,
			"The last operation overflowed the current number of bits.\n\n"
				"The displayed result was adjusted for the current settings.\n"
				"To see the complete result please adjust the display settings.",
			"The current calculator value is too large (either positive or negative) or "
				"it is a large negative value and the current settings are for unsigned values.\n\n"
				"To see the full result modify the \"Bits\" and/or \"Signed\" settings, or simply "
				"use \"Inf\" for infinite precision (Bits = 0) to display any value without overflow."
			);
		//mm_->StatusBarText("Overflow");
		aa_->mac_error_ = 2;
	}
}