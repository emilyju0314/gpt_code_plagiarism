int
TCPTapAgent::sendpkt(Packet* p)
{
  int byteswritten, datalen;
  unsigned char *packet;
  unsigned char received_ttl;
  int hlength = IP_HEADER_LEN + TCP_HEADER_LEN;
  struct tcphdr *tcpheader;

  if (net_->mode() != O_RDWR && net_->mode() != O_WRONLY) {
    fprintf(stderr,
	    "TCPTapAgent(%s): sendpkt called while in read-only mode!\n",
	    name());
    return (-1);
  }
  
  // send packet into the live network
  hdr_cmn* ns_cmnhdr = HDR_CMN(p);
  if (net_ == NULL) {
    fprintf(stderr,
	    "TCPTapAgent(%s): sendpkt attempted with NULL net\n",
	    name());
    drop(p);
    return (-1);
  }
  
  hdr_tcp* ns_tcphdr = HDR_TCP(p);

  hdr_ip * ns_iphdr = HDR_IP(p);
  received_ttl = ns_iphdr->ttl_;

  // Here we check if ns has sent any data in the packet.
  datalen = ns_cmnhdr->size() - ns_tcphdr->hlen();
  packet = (unsigned char *) calloc (1, sizeof(unsigned char) * 
				     (hlength + datalen));
  if (packet == NULL) {
    fprintf(stderr,
	    "TCPTapAgent(%s) : Error %d allocating memory.\n", name(), errno);
    return (-1);
  }


  // Create real world tcp packet.
  ip_gen((char *)packet, (unsigned char) IPPROTO_TCP, 
	 nsnode.sin_addr, extnode.sin_addr, 
	 hlength + datalen, received_ttl);

  tcpheader = (struct tcphdr*) (packet + IP_HEADER_LEN);

  tcp_gen((char *)tcpheader, nsnode.sin_port, extnode.sin_port, p);

#ifndef LINUX_TCP_HEADER
  tcpheader->th_sum = trans_check(IPPROTO_TCP, (char *) tcpheader,
				  sizeof(struct tcphdr) + datalen,
				  nsnode.sin_addr, extnode.sin_addr);
#else 
  tcpheader->check = trans_check(IPPROTO_TCP, (char *) tcpheader,
				  sizeof(struct tcphdr) + datalen,
				  nsnode.sin_addr, extnode.sin_addr);

#endif 

  /* 
     Limits the packets going out to only IP + TCP header. 
     ns will act as an ACK machine.
   */
  byteswritten = net_->send(packet, hlength + datalen);
  if (byteswritten < 0) {
    fprintf(stderr,"TCPTapAgent(%s): sendpkt (%p, %d): %s\n",
	    name(), p->accessdata(), ns_cmnhdr->size(), strerror(errno));
    Packet::free(p);
    free(packet);
    return (-1);
    
  }
  
  free(packet);
  TDEBUG3("TCPTapAgent(%s): sent packet (sz: %d)\n", name(), byteswritten);
  return 0;
}