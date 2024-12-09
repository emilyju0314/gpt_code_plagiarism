void ESPStepperMotorServer::setupAllIOPins()
{
    //setup IO pins for all switches
    for (byte switchId = 0; switchId < ESPServerMaxSwitches; switchId++)
    {
        ESPStepperMotorServer_PositionSwitch *switchConfig = this->serverConfiguration->getSwitch(switchId);
        if (switchConfig)
        {
            this->setupPositionSwitchIOPin(switchConfig);
        }
    }
    //Setup IO pins for all encoders
    for (byte encoderId = 0; encoderId < ESPServerMaxRotaryEncoders; encoderId++)
    {
        ESPStepperMotorServer_RotaryEncoder *encoderConfig = this->serverConfiguration->getRotaryEncoder(encoderId);
        if (encoderConfig)
        {
            this->setupRotaryEncoderIOPin(encoderConfig);
        }
    }

    this->updateSwitchStatusRegister();
}