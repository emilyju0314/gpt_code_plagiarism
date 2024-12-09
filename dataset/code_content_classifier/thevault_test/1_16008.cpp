void ESPStepperMotorServer::performEmergencyStop(int stepperId)
{
    this->emergencySwitchIsActive = true;
    //only perform emergency stop for one stepper
    if (stepperId > -1 && stepperId != 255)
    {
        ESPStepperMotorServer_StepperConfiguration *stepper = this->serverConfiguration->getStepperConfiguration(stepperId);
        if (stepper)
        {
            stepper->getFlexyStepper()->emergencyStop();
        }
    }
    else
    {
        //perform complete stop on all steppers
        ESP_FlexyStepper **configuredFlexySteppers = this->serverConfiguration->getConfiguredFlexySteppers();
        for (byte i = 0; i < ESPServerMaxSteppers; i++)
        {
            if (configuredFlexySteppers[i])
            {
                configuredFlexySteppers[i]->emergencyStop();
            }
            else
            {
                break;
            }
        }
    }
}