bool CommandPosition(int32_t commandedPosition) {
    if (abs(commandedPosition) > abs(positionMaxPWM) ||
        abs(commandedPosition) < abs(positionZeroPWM)) {
        SerialPort.SendLine("Move rejected, invalid position requested");
        return false;
    }
    SerialPort.Send("Moving to position: ");
    SerialPort.SendLine(commandedPosition);

    // Find the scaling factor of our position range mapped to the PWM duty
    // cycle range (255 is the max duty cycle).
    double scaleFactor = 255 / abs(positionMaxPWM - positionZeroPWM);

    // Scale the position command to our duty cycle range.
    uint8_t dutyRequest = abs(commandedPosition - positionZeroPWM) * scaleFactor;

    // Command the move.
    motor.MotorInBDuty(dutyRequest);

    // Waits for HLFB to assert (signaling the move has successfully completed)
    SerialPort.SendLine("Moving... Waiting for HLFB");

    // Delay to give HLFB time to change according to the new command
    Delay_ms(2);

    while (motor.HlfbState() != MotorDriver::HLFB_ASSERTED) {
        continue;
    }

    SerialPort.SendLine("Move Done");
    return true;
}