void reconnect() {
  int nFailCount = 0;
  if ( WiFi.status() != WL_CONNECTED )
  {
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.config(ip, gateway, subnet); 
    WiFi.begin(ssid, password);
    WiFi.config(ip, gateway, subnet); 
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(10);
      Serial.print(".");
      nFailCount++;
      if ( nFailCount > 1500 )
        // Why can't we connect?  Let's not get stuck forever trying...
        // Just reboot and start fresh.
        esp_restart();
    }
    Serial.println("");
    Serial.println("WiFi connected");    
  }
  // Loop until we're reconnected
  while (!mqtt_client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");

    mqtt_client.setServer(mqtt_server, mqtt_port);

    // Attempt to connect
    if (mqtt_client.connect(mqtt_clientId.c_str(),mqtt_userName,mqtt_userPass))
    {
      Serial.println("connected");

     //once connected to MQTT broker, subscribe to our command topic
      bool bSubscribed = false;

      while( !bSubscribed )
      {
        bSubscribed = mqtt_client.subscribe( mqtt_topic_subscribe.c_str() );
      }

      mqtt_client.setCallback(callback);
      mqtt_client.loop();      
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" try again in 200 milliseconds");
      delay(200);
      nFailCount++;
      if ( nFailCount > 500 )
        esp_restart();      
    }  
  }
}