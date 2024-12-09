RTCPAgent::RTCPAgent()
	: Agent(PT_RTCP), session_(0), rtcp_timer_(this)
{
	size_ = 128;
	bind_time("interval_", &interval_);
	bind("random_", &random_);
	bind("seqno_", &seqno_);
	running_ = 0;
}