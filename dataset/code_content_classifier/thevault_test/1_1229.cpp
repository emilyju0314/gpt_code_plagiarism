int cmdUnload(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  uint32_t slotId;

  /* arg 1: client_ticket */
  arg = 0;

  res = readDataFromFile(argv[arg], clientTicket, sizeof(clientTicket));
  if (errRead(res, sizeof(clientTicket), argv[arg]))
    return res;

  /* arg 2: slot_id */
  arg++;
  slotId = 0;
  res = readNumFromFile(argv[arg], &slotId);
  if (errReadNum(res, argv[arg]))
  {
    return res;
  }

  /* api: unloadKey */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("slotId", &slotId, sizeof(slotId));
  res = ias_keystore_unload_key(clientTicket, slotId);

  ks_fprintf(stderr, "unloadKey result: %d\n", res);

  errApi(res, "unloadKey");

  return res;
}