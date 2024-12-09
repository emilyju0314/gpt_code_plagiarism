void ESPStepperMotorServer::startSPIFFS()
{
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
    ESPStepperMotorServer_Logger::logDebug("Checking SPIFFS for existance and free space");
#endif
    bool spiffsBeginSuccess = SPIFFS.begin();
    if (!spiffsBeginSuccess)
    {
        ESPStepperMotorServer_Logger::logWarning("SPIFFS cannot be mounted, trying to format SPIFFS");
        if (SPIFFS.format())
        {
            ESPStepperMotorServer_Logger::logInfo("SPIFFS formatted, trying to mount again");
            spiffsBeginSuccess = SPIFFS.begin();
        }
        else
        {
            ESPStepperMotorServer_Logger::logWarning("SPIFFS formatting failed");
        }
    }

    if (spiffsBeginSuccess)
    {
        this->isSPIFFSactive = true;
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
        if (ESPStepperMotorServer_Logger::getLogLevel() >= ESPServerLogLevel_DEBUG)
        {
            ESPStepperMotorServer_Logger::logDebug("SPIFFS started");
            printSPIFFSStats();
        }
#endif
    }
    else
    {
        this->isSPIFFSactive = false;
        if (this->isWebserverEnabled)
        {
            ESPStepperMotorServer_Logger::logWarning("Unable to activate SPIFFS. Files for web interface cannot be loaded");
        }
    }
}