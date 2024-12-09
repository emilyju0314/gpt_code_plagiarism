int
IPNetwork::send(u_char* buf, int len)
{
	struct ip *ip = (struct ip*) buf;
#ifdef __linux__ 
// For raw sockets on linux the send does not work,
// all packets show up only on the loopback device and are not routed
// to the correct host. Using sendto on a closed socket solves this problem
       ip->ip_len = (ip->ip_len);
       ip->ip_off = (ip->ip_off);
        sockaddr_in sin;
       memset((char *)&sin, 0, sizeof(sin));
       sin.sin_family = AF_INET;
        sin.sin_addr = ip->ip_dst;
       return (::sendto(ssock_, (char*)buf, len, 0,(sockaddr *) &sin,sizeof(sin)));
#else
        ip->ip_len = ntohs(ip->ip_len);
        ip->ip_off = ntohs(ip->ip_off);
        return (::send(ssock_, (char*)buf, len, 0));
#endif
}