bool Util::compareSenderWithAdmin(char *adminPhone) {
#if DEBUG
  Serial.print(F(" Start compare with admin phone: "));
#endif
  while (modem->read() != ',')delay(1);
  modem->read(); // read first '"' char
  uint8_t i = 0;
  char ch;
  while (modem->available() > 0 && i < 12) {
    ch = modem->read();
#if DEBUG
    Serial.write(ch);
#endif
    if ( adminPhone[i] != ch) return false;
    i++;
  }
  // drop chars while not end string
  while (modem->available() > 0 && modem->read() != '\n')delay(1);
  return true;
}