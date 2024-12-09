void CCalcDlg::OnMarkAt()
{
	if (!get_bytes(-2))  // get data at mark
	{
		state_ = CALCERROR;
		return;
	}
	ASSERT(state_ == CALCINTUNARY);

	//check_for_error();   // overflow should not happen?
	edit_.put();
	edit_.get();
	set_right();
	inedit(km_markat);
}