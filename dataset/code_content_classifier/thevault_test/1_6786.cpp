void PgmAgent::timeout_nak_elim(RepairState *rstate)
{

  // Allow one duplicate NAK to come in to be processed and forwarded.
  rstate->nak_elimination() = false;

}