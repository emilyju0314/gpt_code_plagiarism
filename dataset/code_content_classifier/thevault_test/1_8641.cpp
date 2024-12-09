void AccumulateData::InitAccumulateDataJson()
{
  // Stack Data to send
  bool PIR_state;
  if (digitalRead(MotionSensor) ?  PIR_state = true: PIR_state = false);
  Doc["Motion_Sensor_state"] = PIR_state;
  Doc["MotionSensor_Last_Updated"] = millis(); //TODO: Implement proper time stamping for PIR sensor activation
  if (digitalRead(PumpRelay) ?  Doc["Pump_state"] = true: Doc["Pump_state"] = false);
  //Doc["PURR_PUMP_FLOWRATE"] = ;
  //Doc["PURR_WATER_LEVEL"] = ; //TODO: Implement water level sensor and add to json

  // Speakers
  JsonArray Speakers = Doc.createNestedArray("PURR_SPEAKERS");
  bool speakers[2] = {1, 2};
  for (int i = 0; i < 2; i++)
  {
    Speakers.add(speakers[i]);
  }

  // Relay
  JsonArray Relays = Doc.createNestedArray("PURR_RELAYS");
  bool relays[2] = {1, 2};
  for (int i = 0; i < 2; i++)
  {
    Relays.add(relays[i]);
  }

  // Speakers
  JsonArray SpeakersState = Doc.createNestedArray("PURR_SPEAKERS_State");
  bool speakersstate[2] = {1, 2};
  for (int i = 0; i < 2; i++)
  {
    SpeakersState.add(speakersstate[i]);
    bool speakers_state[2] = {1, 2};
    SpeakersState.add("Relay" + String(i) + "State: ");
    if (digitalRead(speakers[i]) ?  speakers_state[i] = true: speakers_state[i] = false);
  }

  // Relay
  JsonArray RelaysState = Doc.createNestedArray("PURR_RELAYS_State");
  bool relaysstate[2] = {1, 2};
  for (int i = 0; i < 2; i++)
  {
    RelaysState.add(relays[i]);
    bool relay_state[2] = {1, 2};
    RelaysState.add("Relay" + String(i) + "State: ");
    if (digitalRead(relaysstate[i]) ?  relay_state[i] = true: relay_state[i] = false);
  }


  // Flow Rate


  //example of how to add json array to json object
  /* // Add arrays for Cell level Data.
  JsonArray Cell_Voltage = Doc.createNestedArray("HMS_Cell_Voltage"); // from 0 - 10 in increasing order
  float *cell_voltage = HMSmain.readSensAndCondition();
  // loop through and store per cell voltage
  for (int i = 0; i < numSensors; i++)
  {
    Cell_Voltage.add(cell_voltage[i]);
  } 

  free(cell_voltage); // free the memory*/

  /* serializeJson(Doc, Serial);
  String json = Doc.as<String>();
  mqtt.MQTTPublish("/PURR/json_live", StringtoChar(json)); */
}