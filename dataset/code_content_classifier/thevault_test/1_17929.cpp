uint8_t Util::handleIncomingSms() {
  uint8_t ret;
  Serial.print(F("handleIncomingSms "));
  char admin[13];
  if (!modem->fillGSMPhone( ADMIN, admin))return RETURN_ERROR;
  modem->dropGSM();
  if (!modem->setFormatSms(GSM_FORMAT))return RETURN_ERROR;
  modem->sendCommand(F("AT+CMGR=1 \r"));
  setEspiredTime(DELAY_FOR_OK);
  while (modem->available() < 40 && delayEspired > 0)delay(2);
  if (modem->available() > 35) {
    if (compareSenderWithAdmin(admin)) {
      ret = executeRequest();
    }
    else ret =  WRONG_USER;
  } else {
    if (digitalRead(DUCT_PIN) == LOW) {
      Serial.print(F("DEBUG: it is not SMS - content("));
      while (modem->available() > 0)Serial.write(modem->read());
    }
    Serial.println(" )");
    
    ret = IS_EMPTY;
  }
  modem->dropGSM();
  if (ret != IS_EMPTY)modem->sendCommand(F("AT+CMGDA=\"DEL ALL\" \r"));
  delay(1);
  modem->dropGSM();
  return ret;
}