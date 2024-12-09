int cmdWrap(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  enum keystore_key_spec keySpec;
  size_t wrappedKeySize = 0;
  size_t appKeySize = 0;

  /* arg 1: client_ticket */
  arg = 0;

  res = readDataFromFile(argv[arg], clientTicket, sizeof(clientTicket));
  if (errRead(res, sizeof(clientTicket), argv[arg]))
    return res;

  /* arg 2: key_spec */
  arg++;
  if (isAES128(argv[arg]))
  {
    keySpec = KEYSPEC_LENGTH_128;
    appKeySize = 16;
  }
  else if (isAES256(argv[arg]))
  {
    keySpec = KEYSPEC_LENGTH_256;
    appKeySize = 32;
  }
  else if (isEcc(argv[arg]))
  {
    keySpec = KEYSPEC_LENGTH_ECC_PAIR;
    appKeySize = sizeof(struct ias_keystore_ecc_keypair);
  }
  else
  {
    return errKeySpec(argv[arg]);
  }

  /* Wrapped Key */
  res = ias_keystore_wrapped_key_size(keySpec, &wrappedKeySize, NULL);
  if (res)
  {
    return res;
  }
  ks_fprintf(stderr, "Wrapped key size: %zu\n", wrappedKeySize);

  uint8_t wrappedKey[wrappedKeySize];


  /* arg 3: app_key */
  uint8_t appKey[appKeySize];
  arg++;
  res = readDataFromFile(argv[arg], appKey, sizeof(appKey));
  if (errRead(res, appKeySize, argv[arg]))
    return res;

  /* api: wrapKey */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("appKey", appKey, appKeySize);
  ksutilHexdump("keySpec", (uint8_t*) &keySpec, sizeof(keySpec));
  res = ias_keystore_wrap_key(clientTicket, appKey, appKeySize, keySpec, wrappedKey);

  ks_fprintf(stderr, "wrapKey result: %d\n", res);

  if (errApi(res, "wrapKey"))
  {
    return res;
  }

  ksutilHexdump("wrappedKey", wrappedKey, wrappedKeySize);

  /* arg 4: *wrapped_key */
  arg++;

  res = writeDataToFile(argv[arg], wrappedKey, wrappedKeySize);

  errWrite(res, argv[arg]);

  return res;
}