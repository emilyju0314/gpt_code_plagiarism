void CCalcDlg::OnSelGet()
{
	CHexEditView *pview = GetView();
	if (pview == NULL)
	{
		no_file_error();
		return;
	}

	FILE_ADDRESS start, end;
	pview->GetSelAddr(start, end);
	mpz_class val;
	mpz_set_ui64(val.get_mpz_t(), start);

	current_ = val;
	state_ = CALCINTUNARY;

	check_for_error();   // check for overflow & display error messages
	edit_.put();
	edit_.get();
	set_right();
	inedit(km_selget);
}