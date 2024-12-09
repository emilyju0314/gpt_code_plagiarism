void PgmReceiver::recv(Packet *pkt, Handler *)
{
  hdr_pgm *hp = HDR_PGM(pkt);

  hdr_cmn *hc = HDR_CMN(pkt);

  if (hc->ptype_ != PT_PGM) {
    printf("%s ERROR (PgmReceiver::recv): received non PGM pkt type %d, discarding.\n", uname_, hc->ptype_);
    Packet::free(pkt);
    return;
  }

#ifdef PGM_DEBUG
  display_packet(pkt);
#endif

  switch(hp->type_) {
  case PGM_SPM:
    handle_spm(pkt);
    break;
  case PGM_ODATA:
    handle_odata(pkt);
    break;
  case PGM_RDATA:
    handle_rdata(pkt);
    break;
  case PGM_NAK:
    // We only receive a NAK if it is multicast from another receiver
    // who is not directly connected to a PGM router.
    handle_nak(pkt);
    break;
  case PGM_NCF:
    handle_ncf(pkt);
    break;
  default:
    printf("ERROR (PgmReceiver::recv): Received invalid PGM type %d.\n",
	   hp->type_);
    break;
  }

  Packet::free(pkt);
}