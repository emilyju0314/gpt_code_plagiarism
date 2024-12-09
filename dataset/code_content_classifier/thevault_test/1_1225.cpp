int cmdUnreg(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];

  /* arg 1: client_ticket */
  arg = 0;

  res = readDataFromFile(argv[arg], clientTicket, sizeof(clientTicket));
  if (errRead(res, sizeof(clientTicket), argv[arg]))
    return res;

  /* api: unregisterClient */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  res = ias_keystore_unregister_client(clientTicket);
  ks_fprintf(stderr, "unregisterClient result: %d\n", res);

  errApi(res, "unregisterClient");

  return res;
}