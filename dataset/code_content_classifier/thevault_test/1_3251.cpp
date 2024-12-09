int CHexEditDoc::CompareProgress()
{
	CSingleLock sl(&docdata_, TRUE);
	if (comp_state_ != SCANNING || length_ == 0)
		return 100;

	return 1 + int((comp_progress_ * 99)/length_);  // 1-100 (don't start at zero)
}