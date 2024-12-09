void callback(char* topic, byte* payload, unsigned int length) {
  
  Serial.print("MQTT Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  // Copy payload into message buffer
  char message[length + 1];
  for (int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  
  message[length] = '\0';

  if (strcmp(topic, mqtt_topic_subscribe.c_str() ) == 0) { //if the incoming message is on the command topic...
    // Parse message into JSON
    const size_t bufferSize = JSON_OBJECT_SIZE(6);
    DynamicJsonDocument jsonBuffer(bufferSize);

    auto error = deserializeJson(jsonBuffer, message);

    if (error) {
      mqtt_client.publish(mqtt_topic_telemetry.c_str(), "!root.success(): invalid JSON on ...");
      return;
    }

    JsonObject root = jsonBuffer.as<JsonObject>();

    if (root.containsKey("ota")) {
      Serial.println( "Found MQTT OTA Request - Switching into OTA Mode.");
       mqtt_client.publish(mqtt_topic_telemetry.c_str(), "Entering OTA Mode" );   
       ota();
    }

    if (root.containsKey("reset")) {
      int reset = root["reset"];
      if ( reset > 0 )
      {
        Serial.print("Resetting...");
        mqtt_client.publish(mqtt_topic_telemetry.c_str(), "Resetting by Request" );  
        delay(500);    
        esp_restart();
      }
    }
  }  
}