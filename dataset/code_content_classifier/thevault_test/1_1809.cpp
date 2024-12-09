void ota()
{
    bHandlingOTA = true;
    timerWrite(timer, 0); //reset timer (feed watchdog)
     //Initialise OTA in case there is a software upgrade
    ArduinoOTA.setHostname("Container");
    ArduinoOTA.onStart([]() {
      Serial.println("Start");
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
      timerWrite(timer, 0); //reset timer (feed watchdog)
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) {Serial.println("Auth Failed");}
      else if (error == OTA_BEGIN_ERROR) {Serial.println("Begin Failed");}
      else if (error == OTA_CONNECT_ERROR) {Serial.println("Connect Failed");}
      else if (error == OTA_RECEIVE_ERROR) {Serial.println("Receive Failed");}
      else if (error == OTA_END_ERROR) {Serial.println("End Failed");}
    });
      
    ArduinoOTA.begin();

    Serial.println("Waiting for any OTA updates");

    while (1) {
      Serial.print (".");
      timerWrite(timer, 0); //reset timer (feed watchdog)
      ArduinoOTA.handle();
        delay(500);
      }
}