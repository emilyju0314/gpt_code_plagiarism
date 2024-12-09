bool CCalcDlg::get_bytes(FILE_ADDRESS addr)
{
	if (bits_ == 0 || bits_%8 != 0)
	{
		current_str_ = "Bits must be divisible by 8";
		return false;
	}

	const char * err_mess = mpz_set_bytes(current_.get_mpz_t(), addr, bits_/8);
	if (err_mess != NULL)
	{
		if (GetView() == NULL)
			no_file_error();
		current_str_ = err_mess;
		return false;
	}

	state_ = CALCINTUNARY;
	return true;
}