void app_ota_init(void){
 // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      MPRINT("Start updating " + type);
    })
    .onEnd([]() {
      MPRINT("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) MPRINT("Auth Failed")
      else if (error == OTA_BEGIN_ERROR) MPRINT("Begin Failed")
      else if (error == OTA_CONNECT_ERROR) MPRINT("Connect Failed")
      else if (error == OTA_RECEIVE_ERROR) MPRINT("Receive Failed")
      else if (error == OTA_END_ERROR) MPRINT("End Failed")
    });

  ArduinoOTA.begin();
}