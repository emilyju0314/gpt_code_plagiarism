void PgmAgent::send_nak(ns_addr_t &upstream_node, ns_addr_t &tsi, int seqno, ns_addr_t &source, ns_addr_t &group)
{

#ifdef PGM_DEBUG
  double now = Scheduler::instance().clock();
  printf("at %f %s sending NAK for seqno %d upstream.\n", now, uname_, seqno);
#endif

  Packet *nak_pkt = allocpkt();
  // Set the simulated size of the NAK packet.
  hdr_cmn *nak_hc = HDR_CMN(nak_pkt);
  nak_hc->size_ = sizeof(hdr_pgm) + sizeof(hdr_pgm_nak);
  nak_hc->ptype_ = PT_PGM;

  // Set the destination address to be our upstream node.
  hdr_ip *nak_hip = HDR_IP(nak_pkt);
  nak_hip->dst() = upstream_node;

  // Set the color of NAK packet to be black in nam.
  nak_hip->fid_ = 8;

  // Fill in the PGM header for the NAK packet.
  hdr_pgm *nak_hp = HDR_PGM(nak_pkt);
  nak_hp->type_ = PGM_NAK;
  nak_hp->tsi_ = tsi;
  nak_hp->seqno_ = seqno;

  // Fill in the PGM NAK header for the NAK packet.
  hdr_pgm_nak *nak_hpn = HDR_PGM_NAK(nak_pkt);
  nak_hpn->source_ = source;
  nak_hpn->group_ = group;

  // Send out the packet.
  send(nak_pkt, 0);
}