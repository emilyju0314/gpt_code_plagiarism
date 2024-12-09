uint8_t HandlerHTTP::sendDataToServer(int themperature, uint8_t motionCounter, uint8_t isHaveVoltage){
 // Serial.println(F("Start send data to Server"));
  if(modem->openConnect()== false)return RETURN_ERROR;
 // Serial.println(F("Open connect"));
  modem->sendCommand(F("AT+HTTPPARA=\"CID\",1 "));
  if(!modem->checkOnOK(0))return NO_SEND;
  //char *command = "AT+HTTPPARA=\"URL\",\"";
  String head = "&field";
    // -------------------------------------------------------------------------------
    // on change methods(add fields) strings bottm must be remaked
    // ------------------------------------------------------------------------------
  String tail = "";
  tail += head + "1=" + String(themperature);
  tail += head + "2=" + String(motionCounter);
  tail += head + "3=" + isHaveVoltage + "\" ";
  String res = String(F("AT+HTTPPARA=\"URL\",\"")) + String(requestHeader) + String(tail);
  Serial.println(res);
  modem->sendCommand(res);
  if(!modem->checkOnOK(0)) {
  //  Serial.println(F("Error on set URL params"));
    return WRONG_DATA;
  }
  modem->sendCommand(F("AT+HTTPACTION=0"));
  uint8_t isSuccess = checkIsSuccess();
  modem->closeConnect();
  if(isSuccess != 0){
    modem->sendCommand(F("AT+SAPBR=0,1"));
    delay(200);
    modem->dropGSM();
    Serial.println(F("Drop Connect with ERROR\n"));
  }
  return isSuccess;
}