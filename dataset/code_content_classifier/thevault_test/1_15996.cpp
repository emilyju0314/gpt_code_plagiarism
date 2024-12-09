void ESPStepperMotorServer::requestReboot(String rebootReason)
{
    Serial.printf("Reboot scheduled, preparing shutdown. Reaon: %s\n", rebootReason.c_str());
    this->_isRebootScheduled = true;
}