void PgmSender::sendmsg(int nbytes, const char * /*flags  = 0 */)
{
  odata_seqno_++;

#ifdef PGM_DEBUG
  double now = Scheduler::instance().clock();

  printf("at %f %s sending ODATA seqno %d\n", now, uname_, odata_seqno_);
#endif

  // Create a packet with the given ODATA.
  Packet *pkt = allocpkt();
  // Set the simulated size of the packet to the indicated nbytes.
  hdr_cmn *hc = HDR_CMN(pkt);
  pktSize_ = nbytes + sizeof(hdr_pgm);
  hc->size_ = pktSize_;

  hc->ptype_ = PT_PGM;

  // Fill in the PGM header.
  hdr_pgm *hp = HDR_PGM(pkt);
  hp->type_ = PGM_ODATA;
  hp->tsi_ = here_; // Set transport session ID to addr/port of this agent.
  hp->seqno_ = odata_seqno_;

  hdr_ip *hip = HDR_IP(pkt);
  // Set the color for ODATA packets.
  hip->fid_ = 1;

  // Send out the packet.
  send(pkt, 0);
}