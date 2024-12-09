uint8_t Util::setCoolThemperature() {
#if DEBUG
  Serial.print(F(" wtite cool_themperature "));
#endif
  char themp[3];
  themp[2] = '\0';
  char ch;
  if (modem->read() != '#')return WRONG_TASK;
  ch = modem->read();
  if ( ch < 48 || ch > 57)  return WRONG_DATA; // not digits chsr
  themp[0] = ch;
  ch = modem->read();
  if ( ch == '#') themp[1] = '\0';
  else {
    if ( ch < 48 && ch > 57) return WRONG_DATA;
    themp[1] = ch;
  }
  if (writeToPhoneBook(COOL_THEMPERATURE_RECORD, themp) != SUCCESS)return NO_SEND;
  WDT_Reset();
#if DEBUG
  Serial.print(F("SUCCESS t = "));
  Serial.println(themp);
#endif
  return SET_COOL_THEMPERATURE_RECORD;
}