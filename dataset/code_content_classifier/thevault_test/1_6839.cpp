int EWPolicy::applyPolicer(policyTableEntry *, policerTableEntry *policer, Packet *pkt) {
  //printf("enter applyPolicer ");

  // can't count/penalize ACKs:
  //   with resp: may cause inaccurate calculation with TSW(??)
  //   with req:  may cause resp retransmission.
  // just pass them through
  hdr_cmn *th = hdr_cmn::access(pkt);
  hdr_ip* iph = hdr_ip::access(pkt);
  int dst_id = iph->daddr();
  int src_id = iph->saddr();

  if (th->ptype() == PT_ACK)
    return(policer->initialCodePt);

  // for other packets...

  // Get time
  now = Scheduler::instance().clock();

  // keep arrival packet stats
  if (ewP) {
    printf("TRR %d %d %d %d\n", (int)now, src_id, dst_id, th->size());
    ewP->updateStats(PKT_ARRIVAL);
  }

  // For other packets:
  if (dropPacket(pkt)) {
    // keep packet stats
    if (ewP)
      ewP->updateStats(PKT_DROP);
    
    //printf("downgrade!\n");	
    return(policer->downgrade1);
  } else {
    // keep packet stats
    if (ewP)
      ewP->updateStats(PKT_DEPT);

    // conduct EW detection
    if (ewP)
      ewP->run(pkt);
    
    if (ewB)
      ewB->run(pkt);    

    //printf("initial!\n");	
    return(policer->initialCodePt);
  }
}