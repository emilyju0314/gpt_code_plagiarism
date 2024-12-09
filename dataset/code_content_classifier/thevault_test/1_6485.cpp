int ScoreBoard1::GetNextRetran()
{
	while ((nxt_to_retrx_) && (nxt_to_retrx_->GetFlag() != SKB_FLAG_LOST))
		nxt_to_retrx_ = nxt_to_retrx_->GetNext();
	if (nxt_to_retrx_) {
		return nxt_to_retrx_->GetStart();
	} else
		return -1;
}