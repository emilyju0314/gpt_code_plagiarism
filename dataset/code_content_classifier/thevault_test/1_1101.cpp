int AMS_5600::detectMagnet()
{
  int magStatus;
  int retVal = 0;
  /*0 0 MD ML MH 0 0 0*/
  /* MD high = magnet detected*/
  /* ML high = AGC Maximum overflow, magnet to weak*/
  /* MH high = AGC minimum overflow, Magnet to strong*/
  magStatus = readOneByte(_addr_status);

  if (magStatus & 0x20)
    retVal = 1;

  return retVal;
}