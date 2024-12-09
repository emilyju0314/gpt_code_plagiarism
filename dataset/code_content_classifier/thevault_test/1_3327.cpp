void CCalcDlg::set_right()
{
	// If there is nothing in the left operand yet we can change the expression radix
	if (left_.IsEmpty())
		orig_radix_ = radix_;
	previous_unary_op_ = unary_none;

	if (state_ == CALCERROR)
		right_ = "***";
	else if (radix_ == orig_radix_ || state_ > CALCINTLIT)
		right_ = current_str_;
	else
	{
		// Add number in original radix
		int numlen = mpz_sizeinbase(current_.get_mpz_t(), orig_radix_) + 3;
		char *numbuf = new char[numlen];
		numbuf[numlen-1] = '\xCD';

		// Get the number as a string
		mpz_get_str(numbuf, theApp.hex_ucase_? -orig_radix_ : orig_radix_, current_.get_mpz_t());
		ASSERT(numbuf[numlen-1] == '\xCD');

		right_ = numbuf;
		delete[] numbuf;
	}
}