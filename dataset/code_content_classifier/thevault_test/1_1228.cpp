int cmdLoad(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  enum keystore_key_spec keySpec;
  size_t wrappedKeySize = 0;
  uint32_t slotId;

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
  /* Wrapped Key */
  res = ias_keystore_wrapped_key_size(keySpec, &wrappedKeySize, NULL);
  if (res)
  {
    return res;
  }
  uint8_t wrappedKey[wrappedKeySize];


  /* arg 3: wrapped_key */
  arg++;

  res = readDataFromFile(argv[arg], wrappedKey, wrappedKeySize);
  if (errRead(res, wrappedKeySize, argv[arg]))
    return res;

  ks_fprintf(stderr, "Wrapped key size: %zu\n", wrappedKeySize);

  /* api: loadKey */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("wrappedKey", wrappedKey, wrappedKeySize);
  res = ias_keystore_load_key(clientTicket, wrappedKey, wrappedKeySize, &slotId);

  ks_fprintf(stderr, "loadKey result: %d\n", res);

  if (errApi(res, "loadKey"))
  {
    if (res == -EAGAIN) {
      ksutilHexdump("re-wrappedKey", wrappedKey, wrappedKeySize);
      writeDataToFile(argv[arg], wrappedKey, wrappedKeySize);
    }

    return res;
  }

  ksutilHexdump("slotId", (uint8_t*) &slotId, sizeof(slotId));

  /* arg 4: *slot_file */
  arg++;
  res = writeNumToFile(argv[arg], slotId);

  errWrite(res, argv[arg]);

  return res;
}