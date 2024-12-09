void ESPStepperMotorServer::removeStepper(byte id)
{
    if (this->serverConfiguration->getStepperConfiguration(id))
    {
        this->serverConfiguration->removeStepperConfiguration(id);
    }
    else
    {
        ESPStepperMotorServer_Logger::logWarningf("Stepper configuration index %i is invalid, no entry found or stepper IDs do not match, removeStepper() canceled\n", id);
    }
}