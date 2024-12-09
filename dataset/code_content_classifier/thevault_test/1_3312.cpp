void CCalcDlg::save_value_to_macro(CString ss /*= CString()*/)
{
	if (ss.IsEmpty())
		ss = current_str_;

	if (source_ == km_user_str && state_ >= CALCINTEXPR)
		aa_->SaveToMacro(km_expression, ss);
	else if (source_ == km_user_str)
		aa_->SaveToMacro(km_user_str, ss);
	else if (source_ != km_result)
		aa_->SaveToMacro(source_);

	source_ = km_result;   // ensure it is not saved again
}