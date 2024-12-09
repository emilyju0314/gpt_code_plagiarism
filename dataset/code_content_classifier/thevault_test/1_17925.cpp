uint8_t VoiceHandler::handleIncoming(char *phone) {
#if DEBUG
  Serial.println(F("Handle voice call"));
#endif
  phone[0] = '\0';
  uint8_t ret;
  if (digitalRead(BUTTON_PIN) == HIGH)ret = makeAnswer(true);
  else {
    fillPhoneFromCall(phone);
    makeAnswer(false); // head func is assign admin phone
    ret = ASSIGN_ADMIN;
  }
  modem->dropGSM();
  return ret;
}