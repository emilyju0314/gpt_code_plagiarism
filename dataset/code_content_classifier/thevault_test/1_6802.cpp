void MultihopMac::recv(Packet* p, Handler *h)
{
	if (h == 0) {		/* from MAC classifier (pass pkt to LL) */
		mode_ = MAC_IDLE;
		Scheduler::instance().schedule(target_, p, delay_);
		return;
	}
	callback_ = h;
	hdr_mac* mh = hdr_mac::access(p);
	mh->macSA() = addr_;
	if (mh->ftype() == MF_ACK) {
		mode_ = MAC_SND;
		send(p);
	} else {
		mh->ftype() = MF_DATA;
		poll(p);		/* poll first */
	}
}