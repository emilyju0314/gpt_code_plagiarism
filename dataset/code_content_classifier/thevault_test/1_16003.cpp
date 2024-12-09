void ESPStepperMotorServer::printWifiStatus()
{
    ESPStepperMotorServer_Logger::logInfo("ESPStepperMotorServer WiFi details:");

    if (this->serverConfiguration->staticIP != 0)
    {
        ESPStepperMotorServer_Logger::logInfof("Static IP address has been configured:\nIP: %s\nGateway: %s\nSubnet Mask:%s\n", this->serverConfiguration->staticIP.toString().c_str(), this->serverConfiguration->gatewayIP.toString().c_str(), this->serverConfiguration->subnetMask.toString().c_str());
    }

    if (this->serverConfiguration->wifiMode == ESPServerWifiModeClient)
    {
        ESPStepperMotorServer_Logger::logInfo("WiFi status: server acts as wifi client in existing network with DHCP");
        ESPStepperMotorServer_Logger::logInfof("SSID: %s\n", this->getCurrentServerConfiguration()->wifiSsid);
        ESPStepperMotorServer_Logger::logInfof("IP address: %s\n", WiFi.localIP().toString().c_str());
        ESPStepperMotorServer_Logger::logInfof("Strength: %i dBm\n", WiFi.RSSI()); //Received Signal Strength Indicator
    }
    else if (this->serverConfiguration->wifiMode == ESPServerWifiModeAccessPoint)
    {
        ESPStepperMotorServer_Logger::logInfo("WiFi status: access point started");
        ESPStepperMotorServer_Logger::logInfof("SSID: %s\n", this->serverConfiguration->apName);
        ESPStepperMotorServer_Logger::logInfof("IP Address: %s\n", WiFi.softAPIP().toString().c_str());
    }
    else
    {
        ESPStepperMotorServer_Logger::logInfo("WiFi is disabled");
    }
}