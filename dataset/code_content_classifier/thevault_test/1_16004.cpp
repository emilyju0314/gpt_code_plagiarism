void ESPStepperMotorServer::setupPositionSwitchIOPin(ESPStepperMotorServer_PositionSwitch *posSwitch)
{
    if (posSwitch)
    {
        if (posSwitch->isActiveHigh())
        {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
            ESPStepperMotorServer_Logger::logDebugf("Setting up IO pin %i as input for active high switch '%s' (%i)\n", posSwitch->getIoPinNumber(), posSwitch->getPositionName().c_str(), posSwitch->getId());
#endif
            pinMode(posSwitch->getIoPinNumber(), INPUT);
        }
        else
        {
            if (posSwitch->getIoPinNumber() == 34 || posSwitch->getIoPinNumber() == 35 || posSwitch->getIoPinNumber() == 36 || posSwitch->getIoPinNumber() == 39)
            {
                ESPStepperMotorServer_Logger::logWarningf("The configured IO pin %i cannot be used for active low switches unless an external pull up resistor is in place. The ESP does not provide internal pullups on this IO pin. Make sure you have a pull up resistor in place for the switch %s (%i)\n", posSwitch->getIoPinNumber(), posSwitch->getPositionName(), posSwitch->getId());
            }
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
            ESPStepperMotorServer_Logger::logDebugf("Setting up IO pin %i as input with pullup for active low switch '%s' (%i)\n", posSwitch->getIoPinNumber(), posSwitch->getPositionName().c_str(), posSwitch->getId());
#endif
            pinMode(posSwitch->getIoPinNumber(), INPUT_PULLUP);
        }
    }
}