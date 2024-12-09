void WebSocketsClient::sendHeader(WSclient_t * client) {

	static const char * NEW_LINE = "\r\n";

    DEBUG_WEBSOCKETS("[WS-Client][sendHeader] sending header...\n");

    uint8_t randomKey[16] = { 0 };

    for(uint8_t i = 0; i < sizeof(randomKey); i++) {
        randomKey[i] = random(0xFF);
    }

    client->cKey = base64_encode(&randomKey[0], 16);

#ifndef NODEBUG_WEBSOCKETS
    unsigned long start = micros();
#endif

    String handshake;
    bool ws_header = true;
    String url = client->cUrl;

    if(client->isSocketIO) {
    	if(client->cSessionId.length() == 0) {
    		url += WEBSOCKETS_STRING("&transport=polling");
    		ws_header = false;
    	} else {
    		url += WEBSOCKETS_STRING("&transport=websocket&sid=");
    		url += client->cSessionId;
    	}
    }

	handshake = WEBSOCKETS_STRING("GET ");
	handshake += url + WEBSOCKETS_STRING(" HTTP/1.1\r\n"
			"Host: ");
	handshake += _host + ":" + _port + NEW_LINE;

	if(ws_header) {
		handshake += WEBSOCKETS_STRING("Connection: Upgrade\r\n"
				"Upgrade: websocket\r\n"
				"Sec-WebSocket-Version: 13\r\n"
				"Sec-WebSocket-Key: ");
		handshake += client->cKey + NEW_LINE;

		if(client->cProtocol.length() > 0) {
			handshake += WEBSOCKETS_STRING("Sec-WebSocket-Protocol: ");
			handshake +=client->cProtocol + NEW_LINE;
		}

		if(client->cExtensions.length() > 0) {
			handshake += WEBSOCKETS_STRING("Sec-WebSocket-Extensions: ");
			handshake +=client->cExtensions + NEW_LINE;
		}
	} else {
		handshake += WEBSOCKETS_STRING("Connection: keep-alive\r\n");
	}

	// add extra headers; by default this includes "Origin: file://"
	if (client->extraHeaders) {
		handshake += client->extraHeaders + NEW_LINE;
	}	

	handshake += WEBSOCKETS_STRING("User-Agent: arduino-WebSocket-Client\r\n");

	if(client->base64Authorization.length() > 0) {
		handshake += WEBSOCKETS_STRING("Authorization: Basic ");
		handshake += client->base64Authorization + NEW_LINE;
	}

	if(client->plainAuthorization.length() > 0) {
		handshake += WEBSOCKETS_STRING("Authorization: ");
		handshake += client->plainAuthorization + NEW_LINE;
	}

	handshake += NEW_LINE;

    DEBUG_WEBSOCKETS("[WS-Client][sendHeader] handshake %s", (uint8_t*)handshake.c_str());
    write(client, (uint8_t*)handshake.c_str(), handshake.length());

#if (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP8266_ASYNC)
        client->tcp->readStringUntil('\n', &(client->cHttpLine), std::bind(&WebSocketsClient::handleHeader, this, client, &(client->cHttpLine)));
#endif

    DEBUG_WEBSOCKETS("[WS-Client][sendHeader] sending header... Done (%uus).\n", (micros() - start));

}