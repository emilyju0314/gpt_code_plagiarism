void
TCPTapAgent::recvpkt()
{
  if (net_->mode() != O_RDWR && net_->mode() != O_RDONLY) {
    fprintf(stderr,
	    "TCPTapAgent(%s): recvpkt called while in write-only mode!\n",
	    name());
    return;
  }
  
  int cc = net_->recv(pkt_handler, this);
  if (cc <= 0) {
    if (cc < 0) {
      perror("recv");
    }
    return;
  }
  TDEBUG4("%f: TCPTapAgent(%s): recvpkt, cc:%d\n", now(), name(), cc);

  // nothing to do coz pkt_handler would have called processpkt()
  // that would have injected packets into the simulator
}