byte sendReqToServer(MsgFormat* pM) {
  if (!isConnectionUp) return TCP_PROTO__CONNECTION_DOWN;

  // send request
  client.write(pM->opCode);
  client.write(pM->data, TCP_PROTO__MSG_DATA_LEN);
  client.flush();

  // receive response
  digitalWrite(LED_BUILTIN_RX, HIGH);
  unsigned long startTsMillis = millis();
  int b;
  for (int i = -1; i < TCP_PROTO__MSG_DATA_LEN; i++) {

    // try to read single byte
    for (;;) {
      b = client.read();
      if (b == -1) {
        if (millis() - startTsMillis > connectionTimeoutMillis) {
          // connection is down
          client.stop();
          isConnectionUp = false;
        } else {
          // otherwise continue waiting for the byte
          continue;
        }
      } else {
        // byte read success
        if (i >= 0) {
          pM->data[i] = b;
        } else if (i == -1) {
          pM->opCode = i;
        }
      }
      break;
    }

    if (!isConnectionUp) return TCP_PROTO__CONNECTION_DOWN;
  }
  digitalWrite(LED_BUILTIN_RX, LOW);

  return TCP_PROTO__SUCCESS;
}