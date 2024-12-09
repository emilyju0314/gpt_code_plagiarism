void PgmAgent::recv(Packet* pkt, Handler*)
{
  hdr_pgm *hp = HDR_PGM(pkt);

  if (!pgm_enabled_) {
    target_->recv(pkt);
    return;
  }

  hdr_cmn *hc = HDR_CMN(pkt);

  if (hc->ptype_ != PT_PGM) {
    printf("%s ERROR (PgmAgent::recv): received non PGM pkt type %d, discarding.\n", uname_, hc->ptype_);
    Packet::free(pkt);
    return;
  }

#ifdef PGM_DEBUG
  display_packet(pkt);
#endif

  // Note, each handle function will free the packet itself or modify the
  // headers and pass it on to the next NS object.

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
    handle_nak(pkt);
    break;
  case PGM_NCF:
    handle_ncf(pkt);
    break;
  default:
    printf("ERROR (PgmAgent::recv): Received PGM packet with unknown type %d.\n", hp->type_);

    Packet::free(pkt);

    break;
  }

}