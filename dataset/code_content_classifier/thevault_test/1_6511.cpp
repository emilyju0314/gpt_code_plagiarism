void
CBQueue::recv(Packet* p, Handler*)
{

	if (pending_pkt_ != NULL)
		abort();

	blocked_ = 1;
	pending_pkt_ = p;
}