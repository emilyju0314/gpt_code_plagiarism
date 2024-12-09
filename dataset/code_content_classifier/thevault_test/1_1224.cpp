int cmdReg(char *argv[])
{
  int arg, res;
  enum keystore_seed_type seed_type = SEED_TYPE_DEVICE;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];

  /* arg 1: seed type */
  /* api: registerClient */
  arg = 0;
  if (argv[arg] == NULL)
  {
     return -1;
  }

  if (strcasecmp(argv[arg], "device") == 0)
  {
     seed_type = SEED_TYPE_DEVICE;
  }
  else if (strcasecmp(argv[arg], "user") == 0)
  {
     seed_type = SEED_TYPE_USER;
  }
  else
  {
     fprintf(stderr, "Unknown SEED type (expect device or user, got: %s)\n", argv[arg]);
     fprintf(stderr, "Will assume a DEVICE seed is required.\n");
     seed_type = SEED_TYPE_DEVICE;
  }

  res = ias_keystore_register_client(seed_type, clientTicket);

  ks_fprintf(stderr, "registerClient result: %d\n", res);

  if (errApi(res, "registerClient"))
  {
    return res;
  }
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));

  /* arg 2: *client_ticket */
  arg++;
  res = writeDataToFile(argv[arg], clientTicket, sizeof(clientTicket));

  errWrite(res, argv[arg]);

  return res;
}