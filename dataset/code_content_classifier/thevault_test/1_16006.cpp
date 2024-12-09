void ESPStepperMotorServer::attachAllInterrupts()
{
    for (int i = 0; i < ESPServerMaxSwitches; i++)
    {
        ESPStepperMotorServer_PositionSwitch *posSwitch = this->serverConfiguration->getSwitch(i);
        if (posSwitch)
        {
            char irqNum = digitalPinToInterrupt(posSwitch->getIoPinNumber());
            if (irqNum == NOT_AN_INTERRUPT)
            {
                ESPStepperMotorServer_Logger::logWarningf("Failed to determine IRQ# for given IO pin %i, thus setting up of interrupt for the position switch '%s' failed\n", posSwitch->getIoPinNumber(), posSwitch->getPositionName().c_str());
            }
            else
            {
                _BV(irqNum); // clear potentially pending interrupts
                //register emergency stop switches
                if (posSwitch->isEmergencySwitch())
                {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
                    ESPStepperMotorServer_Logger::logDebugf("Attaching interrupt service routine for emergency stop switch '%s' on IO pin %i\n", posSwitch->getPositionName().c_str(), posSwitch->getIoPinNumber());
#endif
                    attachInterrupt(irqNum, staticEmergencySwitchISR, CHANGE);
                }
                //register limit switches
                else if (posSwitch->isLimitSwitch())
                {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
                    ESPStepperMotorServer_Logger::logDebugf("Attaching interrupt service routine for limit switch '%s' on IO pin %i\n", posSwitch->getPositionName().c_str(), posSwitch->getIoPinNumber());
#endif
                    if (posSwitch->isTypeBitSet(SWITCHTYPE_LIMITSWITCH_POS_END_BIT))
                    {
                        attachInterrupt(irqNum, staticLimitSwitchISR_POS_END, CHANGE);
                    }
                    else if (posSwitch->isTypeBitSet(SWITCHTYPE_LIMITSWITCH_POS_BEGIN_BIT))
                    {
                        attachInterrupt(irqNum, staticLimitSwitchISR_POS_BEGIN, CHANGE);
                    }
                    else if (posSwitch->isTypeBitSet(SWITCHTYPE_LIMITSWITCH_COMBINED_BEGIN_END_BIT))
                    {
                        attachInterrupt(irqNum, staticLimitSwitchISR_COMBINED, CHANGE);
                    }
                }
                //register general position switches & others
                else
                {
#ifndef ESPStepperMotorServer_COMPILE_NO_DEBUG
                    ESPStepperMotorServer_Logger::logDebugf("Attaching interrupt service routine for general position switch '%s' on IO pin %i\n", posSwitch->getPositionName().c_str(), posSwitch->getIoPinNumber());
#endif
                    attachInterrupt(irqNum, staticPositionSwitchISR, CHANGE);
                }
            }
        }
    }

    for (int i = 0; i < ESPServerMaxRotaryEncoders; i++)
    {
        ESPStepperMotorServer_RotaryEncoder *rotaryEncoder = this->serverConfiguration->getRotaryEncoder(i);
        if (rotaryEncoder != NULL)
        {
            //we do a loop here to save some program memory, could also externalize code block in another function
            const unsigned char pins[2] = {rotaryEncoder->getPinAIOPin(), rotaryEncoder->getPinBIOPin()};
            for (int i = 0; i < 2; i++)
            {
                char irqNum = digitalPinToInterrupt(pins[i]);
                if (irqNum == NOT_AN_INTERRUPT)
                {
                    ESPStepperMotorServer_Logger::logWarningf("Failed to determine IRQ# for given IO pin %i, thus setting up of interrupt for the rotary encoder failed for pin %s\n", pins[i], rotaryEncoder->getDisplayName().c_str());
                }

                _BV(irqNum); // clear potentially pending interrupts
                attachInterrupt(irqNum, staticRotaryEncoderISR, CHANGE);
            }
        }
    }
}