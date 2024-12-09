void Util::WDT_Reset() {
  digitalWrite(RST_PIN, LOW);
  delay(9000);
  wdt_enable(WDTO_8S);//  REBOOT the device after 8 seconds
  Serial.println(F("\n\n\t RESET ON CHANGE PARAMETERS \n"));
  while(Serial.available() > 0)Serial.read();
  modem->dropGSM();
  delay(9000);
}