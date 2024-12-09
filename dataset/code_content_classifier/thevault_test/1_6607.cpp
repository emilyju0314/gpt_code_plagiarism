void PgmSender::recv(Packet *pkt, Handler *)
{
  hdr_cmn* hc = HDR_CMN(pkt);

  if (hc->ptype_ == PT_PGM) {

#ifdef PGM_DEBUG
    display_packet(pkt);
#endif

    // Identify the type of PGM packet, if it is a NAK process it, otherwise
    // throw an error.
    hdr_pgm *hp = HDR_PGM(pkt);

    if (hp->type_ == PGM_NAK) {
      handle_nak(pkt);
    }
    else {
      printf("ERROR (PgmSender::handle_pgm_pkt): received unexpected PGM packet type %d, discarding.\n", hp->type_);
    }
  }
  else {
    printf ("%s ERROR (PgmSender::recv): received non PGM pkt type %d, discarding.\n", uname_, hc->ptype_);
  }

  // Free all packets that this agent receives.
  Packet::free(pkt);
}