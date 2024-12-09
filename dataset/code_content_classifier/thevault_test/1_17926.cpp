uint8_t VoiceHandler::playFile(const char *fileName) {
//#if DEBUD
    Serial.print(" Try play file : ");
    Serial.println(fileName);
//#endif
  delay(10);
  while (modem->available() > 0) {
    modem->read();
    delay(1);
  }
  modem->print("AT+CPAMR=\"" + String(fileName) + "\",0 \r");
  if (!modem->checkOnOK(DELAY_FOR_OK)) {
    return NO_PLAY_SOUND;
  }
  delayForPlay();
  return SUCCESS;
}