int
ArpAgent::sendresp(ether_addr& dest, in_addr& tip, ether_addr& tea)
{
	int pktsz = sizeof(eh_template_) + sizeof(ea_template_);
	if (pktsz < 64)
		pktsz = 64;
	u_char* buf = new u_char[pktsz];
	memset(buf, 0, pktsz);

	ether_header* eh = (ether_header*) buf;
	ether_arp* ea = (ether_arp*) (buf + sizeof(eh_template_));

	// destination link layer address is back to sender
	// (called dest here)
	*eh = eh_template_;	/* set ether header */
	memcpy(eh->ether_dhost, &dest, ETHER_ADDR_LEN);

	// set code as ARP reply
	*ea = ea_template_;	/* set ether/IP arp pkt */
	ea->ea_hdr.ar_op = htons(ARPOP_REPLY);

	// make it look like a regular arp reply
	memcpy(ea->arp_tpa, ea->arp_spa, sizeof(in_addr));
	memcpy(ea->arp_tha, ea->arp_sha, sizeof(in_addr));

	memcpy(ea->arp_sha, &tea, ETHER_ADDR_LEN);
	memcpy(ea->arp_spa, &tip, ETHER_ADDR_LEN);

	if (net_->send(buf, pktsz) < 0) {
                fprintf(stderr,
                    "ArpAgent(%s): sendpkt (%p, %d): %s\n",
                    name(), buf, pktsz, strerror(errno));
                return (-1);
	}
	delete[] buf;
	return (0);
}