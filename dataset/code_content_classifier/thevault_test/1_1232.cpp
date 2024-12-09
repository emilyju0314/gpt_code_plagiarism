int cmdDecrypt(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  enum keystore_algo_spec algoSpec;
  uint32_t slotId;
  uint8_t *initVec = NULL;
  size_t initVecSize;
  uint8_t *encryptedDataBlob;
  uint8_t *encryptedData;
  size_t encryptedDataSize;
  size_t encryptedDataBlobSize;
  size_t plainDataSize;
  off_t fileSize;

  /* arg 1: client_ticket */
  arg = 0;

  res = readDataFromFile(argv[arg], clientTicket, sizeof(clientTicket));
  if (errRead(res, sizeof(clientTicket), argv[arg]))
    return res;

  /* arg 2: slot_id */
  arg++;
  slotId = -1;
  res = readNumFromFile(argv[arg], &slotId);
  if (errReadNum(res, argv[arg]))
  {
    return res;
  }

  /* arg 3: algo_spec */
  arg++;
  if (isAES_CCM(argv[arg]))
  {
    algoSpec = ALGOSPEC_AES_CCM;
    initVecSize = 16;
  }
  else if (isAES_GCM(argv[arg]))
  {
    algoSpec = ALGOSPEC_AES_GCM;
    initVecSize = 16;
  }
  else if (isEcc(argv[arg]))
  {
    algoSpec = ALGOSPEC_ECIES;
    initVecSize = 0;
  }
  else
  {
    return errAlgo(argv[arg]);
  }

  /* arg 4: input data */
  arg++;
  fileSize = getFileSize(argv[arg]);
  encryptedDataBlob = NULL;
  if (fileSize > 0)
    encryptedDataBlob = (uint8_t*) malloc(fileSize);
  res = readAllDataFromFile(argv[arg], encryptedDataBlob, fileSize);
  if (errReadAll(res, argv[arg]))
  {
    free(encryptedDataBlob);
    return res;
  }

  encryptedDataBlobSize = res;
  if (encryptedDataBlobSize >= MAX_ENC_DEC_DATA_LEN)
  {
    warnDataSize(argv[arg]);
  }

  initVec = &encryptedDataBlob[1];
  encryptedData = &encryptedDataBlob[DAL_KEYSTORE_GCM_IV_SIZE + 1];
  encryptedDataSize = encryptedDataBlobSize - DAL_KEYSTORE_GCM_IV_SIZE - 1;
  plainDataSize = encryptedDataSize - 8;

  res = ias_keystore_decrypt_size(algoSpec, encryptedDataSize, &plainDataSize);
  if (errApi(res, "decrypt_size"))
  {
    free(encryptedDataBlob);
    return res;
  }

  uint8_t *plainData = (uint8_t*) malloc(plainDataSize);
  if (!plainData)
  {
    free(encryptedDataBlob);
    return -ENOMEM;
  }

  /* api: decrypt */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("slotId", (uint8_t*) &slotId, sizeof(slotId));
  ksutilHexdump("algoSpec", (uint8_t*) &algoSpec, sizeof(algoSpec));
  ksutilHexdump("initVec", initVec, initVecSize);
  ksutilHexdump("encryptedDataBlob", encryptedDataBlob, dumpLimit(encryptedDataBlobSize));
  ksutilHexdump("encryptedData", encryptedData, dumpLimit(encryptedDataSize));

  res = ias_keystore_decrypt(clientTicket, slotId, algoSpec,
                             (initVecSize > 0) ? initVec : NULL, initVecSize,
                             encryptedData, encryptedDataSize, plainData);

  ks_fprintf(stderr, "decrypt result: %d\n", res);

  free(encryptedDataBlob);

  if (errApi(res, "decrypt"))
  {
    free(plainData);
    return res;
  }

  ksutilHexdump("plainData", plainData, dumpLimit(plainDataSize));

  /* arg 5: *output data */
  arg++;

  res = writeDataToFile(argv[arg], plainData, plainDataSize);
  free(plainData);

  errWrite(res, argv[arg]);

  return res;
}