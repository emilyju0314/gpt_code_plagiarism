void MultihopMac::send(Packet *p)
{
	Scheduler& s = Scheduler::instance();
	if (mode_ != MAC_SND)
		return;

	double txt = txtime(p);
	hdr_mac::access(p)->txtime() = txt;
	channel_->send(p, txt); // target is peer's mac handler
	s.schedule(callback_, &intr_, txt); // callback to higher layer (LL)
	mode_ = MAC_IDLE;
}