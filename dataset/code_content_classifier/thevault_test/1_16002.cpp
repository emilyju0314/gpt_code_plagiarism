void ESPStepperMotorServer::getServerStatusAsJsonString(String &statusString)
{
    StaticJsonDocument<200> doc;
    JsonObject root = doc.to<JsonObject>();
    root["version"] = this->version;

    JsonObject wifiStatus = root.createNestedObject("wifi");
    wifiStatus["mode"] = (this->serverConfiguration->wifiMode == ESPServerWifiModeAccessPoint) ? "ap" : "client";
    wifiStatus["ip"] = (this->serverConfiguration->wifiMode == ESPServerWifiModeAccessPoint) ? WiFi.dnsIP().toString() : WiFi.localIP().toString();

    JsonObject spiffsStatus = root.createNestedObject("spiffss");
    if (this->isSPIFFSMounted())
    {
        spiffsStatus["total_space"] = (int)SPIFFS.totalBytes();
        spiffsStatus["free_space"] = this->getSPIFFSFreeSpace();
    }
    else
    {
        spiffsStatus["not_mounted"] = true;
    }

    JsonObject activeModules = root.createNestedObject("activeModules");
    activeModules["serial_cli"] = (this->cliHandler != NULL);
    activeModules["rest_api"] = (this->isRestApiEnabled);
    activeModules["web_ui"] = (this->isWebserverEnabled);

    serializeJson(root, statusString);
}