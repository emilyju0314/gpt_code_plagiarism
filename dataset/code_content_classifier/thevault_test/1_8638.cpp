void Network::connectToApWithFailToStation()
{
  WiFi.persistent(true);
  SERIAL_DEBUG_LN("Configuring access point...");
  SERIAL_DEBUG_ADD("cfg.WIFISSID:");
  SERIAL_DEBUG_LN(cfg.WIFISSID);
  SERIAL_DEBUG_ADD("cfg.WIFIPASS:");
  SERIAL_DEBUG_LN(cfg.WIFIPASS);

  WiFi.mode(WIFI_STA);
  if (cfg.WIFISSID == " ")
  {
    WiFi.reconnect();
  }
  else
  {
    WiFi.begin(cfg.WIFISSID, cfg.WIFIPASS);
  }

  int numberOfAttempts = 0;

  while (WiFi.status() != WL_CONNECTED)
  {
    numberOfAttempts++;
    delay(200);
    SERIAL_DEBUG_ADD(".");
    if (numberOfAttempts > 100)
    {
      WiFi.mode(WIFI_AP);
      // You can remove the password parameter if you want the AP to be open.
      WiFi.softAP(cfg.WIFISSID, cfg.WIFIPASS);
      SERIAL_DEBUG_ADD("Wifi Connect Failed. \r\nStarting AP. \r\nAP IP address: ");
      SERIAL_DEBUG_LN(WiFi.softAPIP());
      return;
      break;
    }
  }
  SERIAL_DEBUG_LN("");
  SERIAL_DEBUG_LN("Connected! IP address: ");
  SERIAL_DEBUG_LN(WiFi.localIP());
}