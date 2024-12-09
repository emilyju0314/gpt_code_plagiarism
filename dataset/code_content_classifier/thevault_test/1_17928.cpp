bool Util::assignAdmin(char *phone) {
  if (!modem->checkPhoneFormat(phone))return false;
#if DEBUG
  Serial.print(F("assignAdmin: phone right "));
#endif
  ;
  if (!modem->setFormatSms(GSM_FORMAT)) return false;
  if (writeToPhoneBook( ADMIN, phone) != SUCCESS)return false;
#if DEBUG
  Serial.print(F("success write admin "));
#endif
  char empty[13] = { '+', '0', '0', '0', '\0' };
  if (writeToPhoneBook( CLIENT1, empty) != SUCCESS) {
    Serial.print(F("wrong erase client1"));
  }
  if (writeToPhoneBook( CLIENT2, empty) != SUCCESS) {
    Serial.print(F("wrong erase client2"));
  }
  return SUCCESS;
}