void PgmAgent::timeout_nak_retrans(RepairState *rstate)
{

  stats_.num_naks_transmitted_++;

  // Send out a new NAK packet.
  send_nak(rstate->sinfo()->upstream_node(), rstate->sinfo()->tsi(), rstate->seqno(), rstate->source(), rstate->group());

  // Reset the retransmission timer.
  rstate->nak_retrans_timer().resched(nak_retrans_ival_);

}