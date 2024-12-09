int cmdInitVec(char *argv[])
{
  int arg, res;
  uint8_t initVec[DAL_KEYSTORE_GCM_IV_SIZE];
  int initVecSize;

  /* arg 1: algo_spec */
  arg = 0;
  if (isAES_CCM(argv[arg]) || isAES_GCM(argv[arg]))
  {
    initVecSize = DAL_KEYSTORE_GCM_IV_SIZE;
  }
  else
  {
    return errAlgo(argv[arg]);
  }

  /* get random data */
  memset(initVec, 0, sizeof(initVec));
  res = readDataFromFile("/dev/urandom", initVec, sizeof(initVec));
  if (errRead(res, sizeof(initVec), "/dev/urandom"))
  {
    return res;
  }

  /* keystore data is small so let's minimize max message length & maximize nonce size (rfc3610) */
  if (isAES_CCM(argv[arg]))
  {
    initVec[0] = 1;
  }
  ksutilHexdump("initVec", initVec, initVecSize);

  /* arg 2: *init_vec */
  arg++;

  res = writeDataToFile(argv[arg], initVec, initVecSize);

  errWrite(res, argv[arg]);

  return res;
}