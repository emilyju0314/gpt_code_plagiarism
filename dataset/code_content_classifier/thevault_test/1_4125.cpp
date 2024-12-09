void ESP8266WiFiMesh::connectToNode(String target_ssid, String message)
{
	WiFiClient curr_client;
	WiFi.begin( target_ssid.c_str() );

	int wait = 1500;
	while((WiFi.status() == WL_DISCONNECTED) && wait--)
		delay(3);

	/* If the connection timed out */
	if (WiFi.status() != 3)
		return;

	/* Connect to the node's server */
	if (!curr_client.connect(SERVER_IP_ADDR, SERVER_PORT)) 
		return;

	if (!exchangeInfo(message, curr_client))
		return;

	curr_client.stop();
	WiFi.disconnect();
}