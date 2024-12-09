int cmdGen(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  enum keystore_key_spec keySpec;
  size_t wrappedKeySize = 0;

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
  }
  else if (isAES256(argv[arg]))
  {
    keySpec = KEYSPEC_LENGTH_256;
  }
  else if (isEcc(argv[arg]))
  {
    keySpec = KEYSPEC_LENGTH_ECC_PAIR;
  }
  else
  {
    return errKeySpec(argv[arg]);
  }

  res = ias_keystore_wrapped_key_size(keySpec, &wrappedKeySize, NULL);
  if (res)
  {
    return res;
  }
  ks_fprintf(stderr, "Generating new key with size: %zu\n", wrappedKeySize);

  uint8_t wrappedKey[wrappedKeySize];

  /* api: generateKey */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("keySpec", (uint8_t*) &keySpec, sizeof(keySpec));
  res = ias_keystore_generate_key(clientTicket, keySpec, wrappedKey);

  ks_fprintf(stderr, "generateKey result: %d\n", res);

  if (errApi(res, "generateKey"))
  {
    return res;
  }

  ksutilHexdump("wrappedKey", wrappedKey, wrappedKeySize);

  /* arg 3: *wrapped_key */
  arg++;

  res = writeDataToFile(argv[arg], wrappedKey, wrappedKeySize);

  errWrite(res, argv[arg]);

  return res;
}