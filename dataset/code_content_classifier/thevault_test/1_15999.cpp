byte ESPStepperMotorServer::getPositionSwitchStatus(int positionSwitchIndex)
{
    ESPStepperMotorServer_PositionSwitch *posSwitch = this->serverConfiguration->getSwitch(positionSwitchIndex);
    if (posSwitch)
    {
        byte buttonState = digitalRead(posSwitch->getIoPinNumber());
        if ((posSwitch->getSwitchType() & ESPServerSwitchType_ActiveHigh) == ESPServerSwitchType_ActiveHigh)
        {
            return (buttonState) ? 1 : 0;
        }
        else
        {
            return (buttonState) ? 0 : 1;
        }
    }
    return 0;
}