int ESPStepperMotorServer::addOrUpdateStepper(ESPStepperMotorServer_StepperConfiguration *stepper, int stepperIndex)
{
    if (stepper->getStepIoPin() == ESPStepperMotorServer_StepperConfiguration::ESPServerStepperUnsetIoPinNumber ||
        stepper->getDirectionIoPin() == ESPStepperMotorServer_StepperConfiguration::ESPServerStepperUnsetIoPinNumber)
    {
        ESPStepperMotorServer_Logger::logWarningf("Either the step IO pin (%i) or direction IO (%i) pin, or both, are not set correctly. Use a valid IO Pin value between 0 and the highest available IO Pin on your ESP\n", stepper->getStepIoPin(), stepper->getDirectionIoPin());
        return -1;
    }
    //set IO Pins for stepper
    pinMode(stepper->getDirectionIoPin(), OUTPUT);
    digitalWrite(stepper->getDirectionIoPin(), LOW);
    pinMode(stepper->getStepIoPin(), OUTPUT);
    digitalWrite(stepper->getStepIoPin(), LOW);
    //add stepper to configuration or update existing one
    if (stepperIndex > -1)
    {
        this->serverConfiguration->setStepperConfiguration(stepper, stepperIndex);
    }
    else
    {
        stepperIndex = this->serverConfiguration->addStepperConfiguration(stepper);
    }

    return stepperIndex;
}