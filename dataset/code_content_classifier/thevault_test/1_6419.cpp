void SrmNode::remove(int seqno, int flag)
{
	SRM_Request *curr, *prev;
	SRM_Event *ev;

	if (!pending_)
		return;
	for (curr=pending_, prev=0; curr; curr=curr->next_) 
	{
		ev = curr->event_;
		if (ev->seqno() == seqno) {
			if (!prev) 
				pending_ = curr->next_;
			else {
				prev->next_ = curr->next_;
				prev = curr;
			}
			if (flag == SRM_SUPPRESS) {
				curr->cancel_timer();
			}
			delete curr;
		}
	}
}