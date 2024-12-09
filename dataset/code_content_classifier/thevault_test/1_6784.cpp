void PgmAgent::timeout_nak_rpt(RepairState *rstate)
{

  printf("%s: timeout_nak_rpt expired, removing repair state.\n", uname_);

  // We never got a confirmation for our NAK packet. We must now
  // remove the repair state entirely.
  remove_repair_state(rstate);

}