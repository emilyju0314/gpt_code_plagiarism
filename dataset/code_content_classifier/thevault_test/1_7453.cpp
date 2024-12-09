void app_loop(void){
  M5.update();
  if(app.flags.launchOTA){
      app.flags.launchOTA = 0;
      wdt_config_hal(WDT_VERY_LONG_TIMEOUT);
      ArduinoOTA.handle();
      wdt_config_hal(WDT_SHORT_TIMEOUT);
  }
  if(app.flags.readBME){
    app.flags.readBME = 0;
    MPRINT("Reading BME...")
    bme_read_data();
  }
}