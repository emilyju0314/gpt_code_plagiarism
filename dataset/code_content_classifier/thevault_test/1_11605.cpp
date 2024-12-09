void WebSocketsServer::begin(void) {
    WSclient_t * client;

    // init client storage
    for(uint8_t i = 0; i < WEBSOCKETS_SERVER_CLIENT_MAX; i++) {
        client = &_clients[i];

        client->num = i;
        client->status = WSC_NOT_CONNECTED;
        client->tcp = NULL;
#if (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP8266) || (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP32)
        client->isSSL = false;
        client->ssl = NULL;
#endif
        client->cUrl = "";
        client->cCode = 0;
        client->cKey = "";
        client->cProtocol = "";
        client->cVersion = 0;
        client->cIsUpgrade = false;
        client->cIsWebsocket = false;

        client->base64Authorization = "";

        client->cWsRXsize = 0;

#if (WEBSOCKETS_NETWORK_TYPE == NETWORK_ESP8266_ASYNC)
        client->cHttpLine = "";
#endif
    }

#ifdef ESP8266
    randomSeed(RANDOM_REG32);
#elif defined(ESP32)
    #define DR_REG_RNG_BASE 0x3ff75144
    randomSeed(READ_PERI_REG(DR_REG_RNG_BASE));
#else
    // TODO find better seed
    randomSeed(millis());
#endif

    _server->begin();

    DEBUG_WEBSOCKETS("[WS-Server] Server Started.\n");
}