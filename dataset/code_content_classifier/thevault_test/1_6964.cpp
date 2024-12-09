Packet*
Agent::allocpkt(int n) const
{
        Packet* p = allocpkt();

	if (n > 0)
	        p->allocdata(n);

	return(p);
}