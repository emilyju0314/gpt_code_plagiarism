void CBQClass::update(Packet* p, double now)
{
	double idle, avgidle;

	hdr_cmn* hdr = hdr_cmn::access(p);
	int pktsize = hdr->size();

	double tx_time = cbq_->link()->txtime(p);
	double fin_time = now + tx_time;

	idle = (fin_time - last_time_) - (pktsize / maxrate_);
	avgidle = avgidle_;
	avgidle += (idle - avgidle) / POWEROFTWO;
	if (maxidle_ < 0) {
		fprintf(stderr,
			"CBQClass: warning: maxidle_ not configured!\n");
	} else if (avgidle > maxidle_)
		avgidle = maxidle_;
	avgidle_ = avgidle;

	if (avgidle <= 0) {
		undertime_ = fin_time + tx_time *
			(1.0 / allotment_ - 1.0);
		undertime_ += (1-POWEROFTWO) * avgidle;
	}
	last_time_ = fin_time;
	// tail-recurse up to root of tree performing updates
	if (lender_)
		lender_->update(p, now);

	return;
}