void PgmSender::timeout(int type, void *data)
{
  switch(type) {
  case TIMER_SPM:
    if (spm_running_) {
      send_spm();
      spm_heartbeat_.resched(spm_interval_);
    }
    break;
  case TIMER_RDATA:
    send_rdata((RdataItem *)data);
    break;
  default:
    printf("ERROR (PgmSender::timeout): invalid timeout type.\n");
    break;
  }

}