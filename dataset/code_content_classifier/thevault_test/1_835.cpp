void IRSendRev::Send(unsigned char *idata, unsigned char ifreq)
{
  int len = idata[0];
  unsigned char start_high = idata[1];
  unsigned char start_low = idata[2];
  unsigned char nshort = idata[3];
  unsigned char nlong = idata[4];
  unsigned char datalen = idata[5];
// funny wasting
// the reason i bumped my head way too hard on my desk:
// allocating 136 ((4+4*16)*2) byte for only 4 byte of payload: simply insane
  unsigned int *pSt = (unsigned int *)malloc((4 + datalen * 16) * sizeof(unsigned int));

  if (NULL == pSt)
  {
#if __DEBUG
    Serial.println("not enough place!!\r\n");
#endif
    exit(1);
  }

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
  Serial.println(datalen);
#endif

  pSt[0] = start_high * 50;
  pSt[1] = start_low * 50;

  for (int i = 0; i < datalen; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (idata[6 + i] & 0x01 << (7 - j))
      {
        pSt[16 * i + 2 * j + 2] = nshort * 50;
        pSt[16 * i + 2 * j + 3] = nlong * 50;
      }
      else
      {
        pSt[16 * i + 2 * j + 2] = nshort * 50;
        pSt[16 * i + 2 * j + 3] = nshort * 50;
      }
    }
  }

  pSt[2 + datalen * 16] = nshort * 50;
  pSt[2 + datalen * 16 + 1] = nshort * 50;

#if __DEBUG
  for (int i = 0; i < 4 + datalen * 16; i++)
  {
    Serial.print(pSt[i]);
    Serial.print("\t");
  }
  Serial.println();
#endif
  sendRaw(pSt, 4 + datalen * 16, ifreq);
  free(pSt);
}