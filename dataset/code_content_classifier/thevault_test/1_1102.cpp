int AMS_5600::getMagnetStrength()
{
  int magStatus;
  int retVal = 0;
  /*0 0 MD ML MH 0 0 0*/
  /* MD high = magnet detected */
  /* ML high = AGC Maximum overflow, magnet to weak*/
  /* MH high = AGC minimum overflow, Magnet to strong*/
  magStatus = readOneByte(_addr_status);
  if (detectMagnet() == 1) {
    retVal = 2; /* just right */
    if (magStatus & 0x10)
      retVal = 1; /* too weak */
    else if (magStatus & 0x08)
      retVal = 3; /* too strong */
  }

  return retVal;
}