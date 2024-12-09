void PgmReceiver::handle_nak(Packet *pkt)
{
  hdr_pgm *hp = HDR_PGM(pkt);

  // Check that the TSI is correct.
  if ( (have_tsi_state_ == true) && !(hp->tsi_.isEqual (tsi_)) ) {
    printf("%s received NAK with incorrect TSI, discarding.\n", uname_);
    return;
  }

  // Locate the nak state for the given multicast NAK.
  map<int, NakItem>::iterator result = naks_.find(hp->seqno_);

  if (result == naks_.end()) {
    // No state was found. Discard the NCF.
    printf("%s received multicast NAK but no NAK state found, discarding.\n", uname_);
    return;
  }

  NakItem *nitem = &((*result).second);

  switch( nitem->nak_state() ) {
  case BACK_OFF_STATE:
    // Move to WAIT_NCF_STATE.
    nitem->nak_state() = WAIT_NCF_STATE;

    // Reset the timer.
    nitem->nak_timer().resched(nak_rpt_ivl_);

    break;
  case WAIT_NCF_STATE:
    // Stay in the same state.

    // Reset the timer.
    nitem->nak_timer().resched(nak_rpt_ivl_);

    break;
  case WAIT_DATA_STATE:
    // Stay in the same state.

    // Reset the timer.
    nitem->nak_timer().resched(nak_rdata_ivl_);

    break;
  default:
    printf("ERROR (PgmReceiver::handle_nak): Unknown nak state %d.\n", nitem->nak_state());
    break;
  }

}