void Mac802_3::resume() {
	PRNT_MAC_FUNCS(this);
	assert(!mhRecv_.busy());
	assert(!mhSend_.busy());
	assert(!mhIFS_.busy());

	state_= MAC_IDLE;

	if (mhRetx_.packet()) {
		if (!mhRetx_.busy()) {
			// we're not backing off and not sensing carrier right now: send
			transmit(mhRetx_.packet());
		}
	} else {
		if (callback_ && !mhRetx_.busy()) {
			//WARNING: calling callback_->handle may change the value of callback_
			Handler* h= callback_; 
			callback_= 0;
			h->handle(0);
		}
	}
}