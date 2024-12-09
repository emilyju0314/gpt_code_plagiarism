bool HandlerHTTP::setRequestParam(char *wKey /*, char *fields */){
  uint8_t n = 0;
  while(urlHead[n] != '='){
    requestHeader[n] = urlHead[n];
    n++;
  }
  requestHeader[n] = urlHead[n];
  n++;
  for(uint8_t i = 0; i < 16; i++)requestHeader[n + i] = wKey[i];
  requestHeader[n+17]='\0';
 // Serial.print(F("On get apiKey have request header : "));
  Serial.println(requestHeader);
  /* fieldsList = fields; */
  return true;
}