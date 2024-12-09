ESPStepperMotorServer_Configuration::ESPStepperMotorServer_Configuration(const char *configFilePath, bool isSPIFFSactive)
{
    this->_configFilePath = configFilePath;
    this->_isSPIFFSactive = isSPIFFSactive;
    this->loadConfiguationFromSpiffs();
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
    if (ESPStepperMotorServer_Logger::getLogLevel() >= ESPServerLogLevel_DEBUG)
    {
        this->printCurrentConfigurationAsJsonToSerial();
    }
#endif
}