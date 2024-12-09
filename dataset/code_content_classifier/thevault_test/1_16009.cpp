signed char ESPStepperMotorServer::updateSwitchStatusRegister()
{
    byte registerIndex = 0;
    signed char changedSwitchIndex = -1;
    signed char *allSwitchIoPins = this->serverConfiguration->allSwitchIoPins;
    volatile byte *buttonStatus = this->buttonStatus;
    //iterate over all configured position switch IO pins and read state and write to status registers
    for (int switchIndex = 0; switchIndex < ESPServerMaxSwitches; switchIndex++)
    {
        signed char ioPin = allSwitchIoPins[switchIndex];
        if (ioPin > -1)
        {
            if (switchIndex > 7) //write to next register if needed
            {
                registerIndex = (byte)(ceil)((switchIndex + 1) / 8);
            }
            byte previousPinState = bitRead(buttonStatus[registerIndex], switchIndex % 8);
            byte currentPinState = digitalRead(ioPin);

            if (currentPinState == HIGH && previousPinState == LOW)
            {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
                if (ESPStepperMotorServer_Logger::isDebugEnabled())
                    ESPStepperMotorServer_Logger::logDebugf("Setting bit %i to high in register for switch %i with io pin %i\n", (switchIndex % 8), switchIndex, ioPin);
#endif
                bitSet(this->buttonStatus[registerIndex], switchIndex % 8);
                changedSwitchIndex = switchIndex;
            }
            else if (currentPinState == LOW && previousPinState == HIGH)
            {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
                if (ESPStepperMotorServer_Logger::isDebugEnabled())
                    ESPStepperMotorServer_Logger::logDebugf("Setting bit %i to low in register for switch %i with io pin %i\n", (switchIndex % 8), switchIndex, ioPin);
#endif
                bitClear(buttonStatus[registerIndex], switchIndex % 8);
                changedSwitchIndex = switchIndex;
            }
        }
    }
    return changedSwitchIndex;
}