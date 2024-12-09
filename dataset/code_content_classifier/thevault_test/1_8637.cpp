void Network::CheckNetworkLoop()
{
  // run current function every 5 seconds
  
  int currentWifiStatus = CheckWifiState();

  if (currentWifiStatus != 1)
  {
    wifiConnected = false;
    SERIAL_DEBUG_LN(F("Wifi is not connected"));
  }
  else
  {
    SERIAL_DEBUG_LN(F("Wifi is connected and not connected to a network"));
  }
  if (currentWifiStatus == WL_CONNECTED && !wifiConnected)
  {
    wifiConnected = true;
    Serial.print("INFO: WiFi Connected! Open http://");
    Serial.print(WiFi.localIP());
    SERIAL_DEBUG_LN(" in your browser");
  }
}