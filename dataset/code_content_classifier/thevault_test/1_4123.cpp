bool ESP8266WiFiMesh::waitForClient(WiFiClient curr_client, int max_wait)
{
	int wait = max_wait;
	while(curr_client.connected() && !curr_client.available() && wait--)
		delay(3);

	/* Return false if the client isn't ready to communicate */
	if (WiFi.status() == WL_DISCONNECTED || !curr_client.connected())
		return false;
	
	return true;
}