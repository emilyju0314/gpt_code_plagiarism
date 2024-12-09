void PgmReceiver::timeout(int type, void *data)
{

  switch(type) {
  case NAK_TIMER:
    timeout_nak((NakItem *) data);
    break;
  default:
    printf("ERROR (PgmReceiver::timeout): Unknown timeout type %d.\n", type);
    break;
  }

}