void Receiver::loop() {
  HomieNode::loop();

  // get value from receiver
  unsigned long code = fillReceivedCode();

  if (code == 0) {
    return;
  }

  // convert unsigned long to string for MQTT topic
  char cstr[16];
  itoa(code, cstr, 10);

  Serial.println(cstr);

  // set up value in MQTT topic
  setProperty(SW_RECEIVER).send(cstr);

  for (RemoteButton* recPtr : buttonNodes) {
    if (recPtr->handle(code)) {
      break;
    }
  }
}