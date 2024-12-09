void
ArpAgent::doreply(ether_arp* ea)
{
	/*
	 * reply will be from the replier's point of view,
	 * so, look in the sender ha/pa fields for the info
	 * we want
	 */
	in_addr t;
	ether_addr e;
	memcpy(&t, ea->arp_spa, 4);	// copy IP address
	memcpy(&e, ea->arp_sha, ETHER_ADDR_LEN);
	insert(t, e, 'D');
	return;
}