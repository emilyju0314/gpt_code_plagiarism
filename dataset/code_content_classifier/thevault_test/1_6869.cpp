void
PingResponder::reflect(ip* iph)
{
	in_addr daddr = iph->ip_dst;
	int iplen = ntohs(iph->ip_len);
	int iphlen = (*((char*)iph) & 0x0f) << 2;

	/* swap src and dest IP addresses on IP header */
	iph->ip_dst = iph->ip_src;
	iph->ip_src = daddr;
	iph->ip_sum = 0;
	iph->ip_sum = Internet::in_cksum((u_short*) iph, iphlen);

	/* recompute the icmp cksum */
	icmp* icp = (icmp*)(iph + 1);	// just past standard IP header
	icp->icmp_cksum = 0;
	icp->icmp_cksum = Internet::in_cksum((u_short*)icp, iplen - iphlen);
}