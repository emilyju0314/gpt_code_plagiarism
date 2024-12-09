void CCalcDlg::OnSelAt()                // Value in file at cursor
{
	if (!get_bytes(-3))                // get data at cursor/selection
	{
		state_ = CALCERROR;
		return;
	}
	ASSERT(state_ == CALCINTUNARY);

	//check_for_error();   // overflow should not occur?
	edit_.put();
	edit_.get();
	set_right();
	inedit(km_selat);
}