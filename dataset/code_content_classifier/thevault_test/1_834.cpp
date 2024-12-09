void IRSendRev::ImpSend(unsigned char *idata, unsigned char ifreq)
{
  int len = idata[D_LEN];
  unsigned int start_high = idata[D_STARTH];
  unsigned int start_low = idata[D_STARTL];
  unsigned int nshort = idata[D_SHORT];
  unsigned int nlong = idata[D_LONG];
  unsigned char datalen = idata[D_DATALEN]; //need to manually set this

  int realDatalen = (datalen == 0) ? MaxMsgSize : datalen;

#if __DEBUG
  Serial.println("begin to send ir:\r\n");
  Serial.print("ifreq = ");
  Serial.println(ifreq);
  Serial.print("len = ");
  Serial.println(len);
  Serial.print("start_high = ");
  Serial.println(start_high);
  Serial.print("start_low = ");
  Serial.println(start_low);
  Serial.print("nshort = ");
  Serial.println(nshort);
  Serial.print("nlong = ");
  Serial.println(nlong);
  Serial.print("datalen = ");
  Serial.println(realDatalen);
#endif

  bool toggle = false;
  bool *toggleFlag = &toggle;

  EnableIROut(ifreq);

  // send starting
  ImpSendRaw(start_high, toggleFlag);
  // equal = !equal;
  ImpSendRaw(start_low, toggleFlag);
  // send data:

  for (int i = /*D_DATA*/ 0; i < realDatalen; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (idata[6 + i] & 0x01 << (7 - j))
      {
        ImpSendRaw(nshort, toggleFlag);
        ImpSendRaw(nlong, toggleFlag);
      }
      else
      {
        ImpSendRaw(nshort, toggleFlag);
        ImpSendRaw(nshort, toggleFlag);
      }
    }
  }

  //send ending
  ImpSendRaw(nshort, toggleFlag);
  ImpSendRaw(nshort, toggleFlag);

  space(0); //they said "Just to be sure" yeah, why not
}