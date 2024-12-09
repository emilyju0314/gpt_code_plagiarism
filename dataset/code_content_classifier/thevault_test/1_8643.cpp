void TasktoRunNetworkStack(void *parameter)
{
  Network *network = new Network;
  PurrMqtt *mqtt = new PurrMqtt;
  Serial.print("Networking Tasks running on core ");
  Serial.println(xPortGetCoreID());
  for (;;)
  {
    if (millis() - lastMillis >= 5000)
    {
      lastMillis = millis();        // get ready for the next iteration
      network->updateCurrentData(); // Update the config file with the current data
      network->CheckNetworkLoop();  // Check the network state and connect to the AP if needed
    }
    // network.SetupmDNSLoop(); // Setup mDNS loop
    mqtt->RunMqttService(); // Run the MQTT service loop
  }
  delete network;
  delete mqtt;
}