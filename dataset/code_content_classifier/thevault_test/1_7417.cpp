void timer_process(void){
  #ifdef OTA
   // Reset the timer and execute the function
   if(!app.timers.OTAUpdateTimer){
    app.timers.OTAUpdateTimer = OTA_UPDATE_POLL_PERIOD_MS;
    app.flags.launchOTA = 1;
   }
  #endif
  if(!app.timers.bmeReadingTimer){
    app.timers.bmeReadingTimer = BME_POLLING_PERIOD_MS;
    app.flags.readBME = 1;
  }
  if(app.displayState && app.flags.displayAutoTurnOffFlag){
    if(!app.timers.displayOffTimer){
      app.timers.displayOffTimer = DISPLAY_OFF_TIMEOUT_TIME_MS;
      app.flags.setDisplayOff = 1;
    }
  }
}