void PgmAgent::timeout(int type, void *data)
{

  switch(type) {
  case TIMER_NAK_RETRANS:
    timeout_nak_retrans((RepairState *) data);
    break;
  case TIMER_NAK_RPT:
    timeout_nak_rpt((RepairState *) data);
    break;
  case TIMER_NAK_RDATA:
    timeout_nak_rdata((RepairState *) data);
    break;
  case TIMER_NAK_ELIM:
    timeout_nak_elim((RepairState *) data);
    break;
  default:
    printf("ERROR (PgmAgent::timeout()): Invalid timeout type %d.\n", type);
    break;
  }

}