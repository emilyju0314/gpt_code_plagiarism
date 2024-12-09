void PgmSender::send_rdata(RdataItem *item)
{

  // Locate the sequence number of this rdata in the list of sent
  // retransmissions.
  int count = 0;
  list<ReplyItem>::iterator iter = reply_.begin();
  while (iter != reply_.end()) {
    if ((*iter).seqno() == item->seqno()) {
      (*iter).retransmissions() += 1;

      if ((*iter).retransmissions() > stats_.max_num_repeated_rdata_) {
	stats_.max_num_repeated_rdata_ = (*iter).retransmissions();
      }

      break;
    }

    count++;
    iter++;
  }

  if (iter == reply_.end()) {
    // This is the first time we're sending out this RDATA. Append it to
    // the back of the reply list.
    if (count >= MAX_REPLY_LIST_SIZE) {
      // Pop off the front-most element if we've reached the max size of
      // the reply list.
      reply_.pop_front();
    }

    reply_.push_back(ReplyItem(item->seqno()));
  }

  stats_.num_rdata_sent_++;

  // Send the packet to each of the interfaces.
  if (!item->iface_list().empty()) {
    list<int>::iterator iter = item->iface_list().begin();
    int flag = 0;   // Used to determine when we need to make additional copies of the packet.
    while (iter != item->iface_list().end()) {
      NsObject *tgt;
      tgt = iface2link(*iter);
      Packet *pkt = item->rdata_pkt();
      if (flag) {
	// Make a copy of each packet before sending it, so we don't free()
	// the same packet at the different receivers causing a deallocation
	// problem.
	pkt = pkt->copy();
      } else {
	trace_event("SEND RDATA", HDR_IP(pkt)->daddr(), 0);
	flag = 1;
      }
      tgt->recv(pkt);

      iter++;
    }

  }

  if (!item->agent_list().empty()) {
    list<NsObject *>::iterator iter = item->agent_list().begin();
    int flag = 0;
    while (iter != item->agent_list().end()) {
      Packet *pkt = item->rdata_pkt();
      if (flag) {
	pkt = pkt->copy ();
      } else {
	flag = 1;
      }
      (*iter)->recv(pkt);

      iter++;
    }
  }

  hdr_pgm *hp = HDR_PGM(item->rdata_pkt());

  // Remove this sequence number from the pending RDATA list, since
  // we have now sent that RDATA.
  if (!pending_rdata_.erase(hp->seqno_)) {
    printf("ERROR (PgmSender::send_rdata): Did not erase RdataItem from map.\n");
  }

}