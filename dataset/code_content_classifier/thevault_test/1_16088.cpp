void turnOn(String deviceId) {
  if (deviceId == SwitchId) {// Device ID of first device
    client.publish(mqttTopic, "[ESP8266-IRremote-Alexa] Toggle TV On/Off");
    irsend.sendGC(Samsung_power_toggle, 71);
  }
  else if (deviceId == LightId) {// Device ID of second device
    client.publish(mqttTopic, "[ESP8266-IRremote-Alexa] TV LEDs On");
    irsend.sendNEC(rgbled.On, freq_strip);
    delay(100);
    irsend.sendNEC(rgbled.Green, freq_strip);
    delay(50);
  }
  else {
    Serial.print("Turn on for unknown device id: ");
    Serial.println(deviceId);
  }
}