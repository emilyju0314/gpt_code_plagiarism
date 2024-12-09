void handlePostRoot() {
  String content = espServer.arg("plain");
  debug_println("Request content: '" + content + "'");

  bool needSave = false;
  bool needSensorFetch = false;
  String newValue;

  newValue = findData(content, "node"); 
  if (isNewValue(nodeName, newValue)) {
    nodeName = newValue;
    needSave = true;
  }

  newValue = findData(content, "topic");
  if (isNewValue(rootTopic, newValue)) {
    rootTopic = newValue;
    updateSensorTopics();
    needSave = true;
  }

  newValue = findData(content, "altitude");
  if (isNewValue(String(nodeAltitude, 2), newValue)) {
    nodeAltitude = newValue.toFloat();
    needSensorFetch = true;
    needSave = true;
  }

  newValue = findData(content, "sensorcycle");
  if (isNewValue(String(updateSensorsTimeout, 10), newValue)) {
    updateSensorsTimeout = max(1L,newValue.toInt());
    timer1.interval(updateSensorsTimeout * 1000);
    needSave = true;
  }

#if SENSORNODE_VERSION >= SENSORNODE_WITH_DISPLAY_VERSION
  newValue = findData(content, "forecastcycle");
  if (isNewValue(String(updateWeatherForecastTimeout, 10), newValue)) {
    updateWeatherForecastTimeout = newValue.toInt();
    timer2.interval(updateWeatherForecastTimeout * 1000);
    needSave = true;
  }

  newValue = findData(content, "hasDisplay");
  if (hasDisplay != (newValue.length() > 0)) {
    hasDisplay = newValue.length() > 0;
    needSave = true;
    setupDisplay();
  }
#else
  hasDisplay = false;
#endif

  uint8_t idx = 0;
  while (sensors[idx].id.length() > 0 && idx < MAX_SENSORS) {
    String key = "loc-" + sensors[idx].id;
    newValue = findData(content, key);
    if (isNewValue(sensors[idx].location, newValue)) {
      sensors[idx].location = newValue;
      updateSensorTopic(sensors[idx].id);
      needSave = true;
    }

    key = "en-" + sensors[idx].id;
    newValue = findData(content, key);
    bool newEnabled = newValue.equals("on");
    needSave = needSave || (sensors[idx].enabled == newEnabled);
    sensors[idx].enabled = newEnabled;

    key = "cor-" + sensors[idx].id;
    newValue = findData(content, key);
    if (isNewValue(String(sensors[idx].correction, 2), newValue)) {
      sensors[idx].correction = newValue.toFloat();
      needSave = true;
      needSensorFetch = true;
    }

    key = "show";
    newValue = findData(content, key);
    if (isNewValue(showSensor, newValue)) {
      showSensor = newValue;
      needSave = true;
    }

    ++idx;
  }

  if (needSave) saveConfig();
  if (needSensorFetch) fetchSensorValues();
  
  if (needSave || needSensorFetch) updateDisplay();

  espServer.sendHeader("Location", "/");
  espServer.send(303);
}