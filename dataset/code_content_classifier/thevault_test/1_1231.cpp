int cmdEncrypt(char *argv[])
{
  int arg, res;
  uint8_t clientTicket[KEYSTORE_CLIENT_TICKET_SIZE];
  enum keystore_algo_spec algoSpec;
  uint32_t slotId;
  uint8_t initVec[DAL_KEYSTORE_GCM_IV_SIZE];
  size_t initVecSize;
  uint8_t *plainData;
  size_t plainDataSize;
  size_t encryptedDataSize;
  size_t encryptedDataBlobSize;
  off_t fileSize;
  uint32_t copy_len = 0;

  memset(initVec, 0, sizeof(initVec));

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

  /* arg 4: init_vec */
  arg++;

  if (initVecSize > 0)
  {
    res = readDataFromFile(argv[arg], initVec, initVecSize);
    if (errRead(res, initVecSize, argv[arg]))
      return res;
  }

  /* arg 5: input data */
  arg++;
  fileSize = getFileSize(argv[arg]);
  plainData = NULL;
  if (fileSize > 0)
    plainData = (uint8_t*) malloc(fileSize);
  res = readAllDataFromFile(argv[arg], plainData, fileSize);
  if (errReadAll(res, argv[arg]))
  {
    free(plainData);
    return res;
  }

  plainDataSize = res;
  if (plainDataSize >= MAX_ENC_DEC_DATA_LEN)
  {
    warnDataSize(argv[arg]);
  }

  res = ias_keystore_encrypt_size(algoSpec, plainDataSize, &encryptedDataSize);
  if (errApi(res, "encrypt_size"))
  {
    free(plainData);
    return res;
  }

  encryptedDataBlobSize = encryptedDataSize + DAL_KEYSTORE_GCM_IV_SIZE + 1;
  uint8_t *encryptedDataBlob = (uint8_t*) malloc(encryptedDataBlobSize);
  if (!encryptedDataBlob)
  {
    free(plainData);
    return -ENOMEM;
  }

  encryptedDataBlob[0] = (uint8_t)algoSpec;
  copy_len = sizeof(initVec); 
  if (encryptedDataBlobSize - 1 < copy_len)  
    copy_len = encryptedDataBlobSize - 1;  
 
if (0 != keystore_memcpy(&encryptedDataBlob[1], initVec, copy_len))
  {
    free(plainData);
    free(encryptedDataBlob);
    return -EFAULT;
  }

  uint8_t *encryptedData = &encryptedDataBlob[DAL_KEYSTORE_GCM_IV_SIZE + 1];

  /* api: encrypt */
  ksutilHexdump("clientTicket", clientTicket, sizeof(clientTicket));
  ksutilHexdump("slotId", (uint8_t*) &slotId, sizeof(slotId));
  ksutilHexdump("algoSpec", (uint8_t*) &algoSpec, sizeof(algoSpec));
  ksutilHexdump("initVec", initVec, initVecSize);
  ksutilHexdump("plainData", plainData, dumpLimit(plainDataSize));

  res = ias_keystore_encrypt(clientTicket, slotId, algoSpec,
                             (initVecSize > 0) ? initVec : 0, initVecSize,
                             plainData, plainDataSize, encryptedData);

  ks_fprintf(stderr, "encrypt result: %d\n", res);

  free(plainData);

  if (errApi(res, "encrypt"))
  {
    free(encryptedDataBlob);
    return res;
  }

  ksutilHexdump("encryptedData", encryptedData, dumpLimit(plainDataSize));
  ksutilHexdump("encryptedDataBlob", encryptedDataBlob, dumpLimit(encryptedDataBlobSize));

  /* arg 6: *output data */
  arg++;

  res = writeDataToFile(argv[arg], encryptedDataBlob, encryptedDataBlobSize);
  free(encryptedDataBlob);

  errWrite(res, argv[arg]);

  return res;
}