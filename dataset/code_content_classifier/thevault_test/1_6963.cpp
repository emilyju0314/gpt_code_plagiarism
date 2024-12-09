Packet*
Agent::allocpkt() const
{
	Packet* p = Packet::alloc();
	initpkt(p);
	return (p);
}