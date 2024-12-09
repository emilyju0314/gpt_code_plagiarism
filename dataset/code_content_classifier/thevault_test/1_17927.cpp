uint8_t Util::getTypeRequest(void) {
  setEspiredTime(DELAY_FOR_ANSWER);
  while (modem->available() < 14 && delayEspired != 0)delay(2);
  if (modem->available() < 14)return UNDEFINED;
  char req[13];
  for (uint8_t i = 0; i < 12; i++) {
    req[i] = modem->read();
  }
  req[12] = '\0';
  if ( strstr( req, "RING") != NULL)return INC_CALL;
  if (strstr( req, "+CMTI") != NULL)return INC_SMS;
  Serial.print(F("\n\tWARNING: undefined modem MSG\n get from modem [ "));
  Serial.print(req);
  while (modem->available() > 0)Serial.write(modem->read());
  Serial.println(" ]\n");
  return UNDEFINED;
}