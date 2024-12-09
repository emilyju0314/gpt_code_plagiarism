ESPStepperMotorServer_RestAPI::ESPStepperMotorServer_RestAPI(ESPStepperMotorServer *stepperMotorServer)
{
    this->_stepperMotorServer = stepperMotorServer;
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
    ESPStepperMotorServer_Logger::logDebug("ESPStepperMotorServer_RestAPI instance created");
#endif
}