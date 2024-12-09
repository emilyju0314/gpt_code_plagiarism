void CCalcDlg::no_file_error()
{
	make_noise("Calculator Error");
	AvoidableTaskDialog(IDS_CALC_NO_FILE,
		"The calculator cannot perform this operation when no file is open.");
	aa_->mac_error_ = 10;
}