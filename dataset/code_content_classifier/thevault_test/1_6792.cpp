char* SctpCMTAgent::PrintDestStatus(SctpDest_S* spDest)
{
  switch(spDest->eStatus)
    {
    case SCTP_DEST_STATUS_ACTIVE:
      return "ACTIVE";
    case SCTP_DEST_STATUS_INACTIVE:
      return "INACTIVE";
    case SCTP_DEST_STATUS_POSSIBLY_FAILED:
      return "PF";
    case SCTP_DEST_STATUS_UNCONFIRMED:
      return "UNCONFIRMED";
    default:
      return "UNKNOWN";
    }
}