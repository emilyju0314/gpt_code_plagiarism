ESPStepperMotorServer::ESPStepperMotorServer(byte serverMode, byte logLevel)
{
    ESPStepperMotorServer_Logger::setLogLevel(logLevel);
    startSPIFFS();
    //get config instance which tries to load config from SPIFFS by default
    this->serverConfiguration = new ESPStepperMotorServer_Configuration(this->defaultConfigurationFilename, this->isSPIFFSactive);

    this->enabledServices = serverMode;

#ifndef ESPStepperMotorServer_COMPILE_NO_WEB
    if ((this->enabledServices & ESPServerWebserverEnabled) == ESPServerWebserverEnabled)
    {
        this->isWebserverEnabled = true;
        this->webInterfaceHandler = new ESPStepperMotorServer_WebInterface(this);
    }
    //rest api needs to be started either if web UI is enabled (which uses the REST API itself) or if REST API is enabled
    if ((this->enabledServices & ESPServerRestApiEnabled) == ESPServerRestApiEnabled || this->isWebserverEnabled)
    {
        this->isRestApiEnabled = true;
        this->restApiHandler = new ESPStepperMotorServer_RestAPI(this);
    }
#endif

    if ((this->enabledServices & ESPServerSerialEnabled) == ESPServerSerialEnabled)
    {
        this->isCLIEnabled = true;
        this->cliHandler = new ESPStepperMotorServer_CLI(this);
    }

    this->motionControllerHandler = new ESPStepperMotorServer_MotionController(this);

    if (ESPStepperMotorServer::anchor != NULL)
    {
        ESPStepperMotorServer_Logger::logWarning("ESPStepperMotorServer must be used as a singleton, do not instanciate more than one server in your project");
    }
    else
    {
        ESPStepperMotorServer::anchor = this;
    }
}