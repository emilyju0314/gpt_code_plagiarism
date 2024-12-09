void PgmSender::send_spm()
{
  spm_seqno_++;

  // Create a packet with the given ODATA.
  Packet *pkt = allocpkt();
  // Set the simulated size of the packet to the indicated nbytes.
  hdr_cmn *hc = HDR_CMN(pkt);
  hc->size_ = sizeof(hdr_pgm) + sizeof(hdr_pgm_spm);

  hc->ptype_ = PT_PGM;

  hdr_ip *hip = HDR_IP(pkt);
  // Set the color for SPM packets in nam.
  hip->fid_ = 7;
  //  hip->daddr() = group_;

  // Fill in the PGM header.
  hdr_pgm *hp = HDR_PGM(pkt);
  hp->type_ = PGM_SPM;
  hp->tsi_ = here_; // Set transport session ID to addr/port of this agent.
  hp->seqno_ = spm_seqno_;

  // Fill in SPM header.
  hdr_pgm_spm *hs = HDR_PGM_SPM(pkt);
  hs->spm_path_ = here_; // Set current path to the source agent.

#ifdef PGM_DEBUG
  double now = Scheduler::instance().clock();
  printf("at %f %s sending SPM, from %d:%d (here = %d:%d) to %d:%d, TSI %d:%d, type %d\n", now, uname_, hip->saddr(), hip->sport(), addr(), port(), hip->daddr(), hip->dport(), hp->tsi_.addr_, hp->tsi_.port_, hp->type_);
#endif

  // Send out the packet.
  send(pkt, 0);
}