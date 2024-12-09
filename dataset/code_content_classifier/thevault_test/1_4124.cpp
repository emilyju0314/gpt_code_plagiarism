bool ESP8266WiFiMesh::exchangeInfo(String message, WiFiClient curr_client)
{
	curr_client.println( message.c_str() );

	if (!waitForClient(curr_client, 1000))
		return false;

	String response = curr_client.readStringUntil('\r');
	curr_client.readStringUntil('\n');

	if (response.length() <= 2) 
		return false;

	/* Pass data to user callback */
	_handler(response);
	return true;
}