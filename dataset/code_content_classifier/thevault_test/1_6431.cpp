void
TapAgent::recv(Packet* p, Handler*)
{
	(void) sendpkt(p);
	Packet::free(p);
	return;
}