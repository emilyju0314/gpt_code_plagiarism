bool WebSocketsClient::sendPing(uint8_t * payload, size_t length) {
    if(clientIsConnected(&_client)) {
        return sendFrame(&_client, WSop_ping, payload, length, true);
    }
    return false;
}