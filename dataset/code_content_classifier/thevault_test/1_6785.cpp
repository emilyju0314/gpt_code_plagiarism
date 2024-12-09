void PgmAgent::timeout_nak_rdata(RepairState *rstate)
{

  printf("%s: timeout_nak_rdata expired, removing repair state.\n", uname_);

  // We never got the RDATA for our NAK. We must now remove the repair
  // state entirely.
  remove_repair_state(rstate);

}