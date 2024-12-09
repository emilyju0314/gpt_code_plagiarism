void ESPStepperMotorServer::detachAllInterrupts()
{
    for (int i = 0; i < ESPServerMaxSwitches; i++)
    {
        ESPStepperMotorServer_PositionSwitch *posSwitch = this->serverConfiguration->getSwitch(i);
        if (posSwitch)
        {
            this->detachInterruptForPositionSwitch(posSwitch);
        }
    }
    for (int i = 0; i < ESPServerMaxRotaryEncoders; i++)
    {
        ESPStepperMotorServer_RotaryEncoder *rotaryEncoder = this->serverConfiguration->getRotaryEncoder(i);
        if (rotaryEncoder != NULL)
        {
            this->detachInterruptForRotaryEncoder(rotaryEncoder);
        }
    }
}