bool CommandVelocity(int32_t commandedVelocity) {
    if (abs(commandedVelocity) > abs(maxSpeed)) {
        SerialPort.SendLine("Move rejected, requested velocity over the limit.");
        return false;
    }

    SerialPort.Send("Commanding velocity: ");
    SerialPort.SendLine(commandedVelocity);

    // Change ClearPath's Input A state to change direction.
    if (commandedVelocity > 0) {
        motor.MotorInAState(false);
    }
    else {
        motor.MotorInAState(true);
    }

    // Delays to send the correct filtered direction.
    Delay_ms(2 + INPUT_A_FILTER);

    // Find the scaling factor of our velocity range mapped to the PWM duty
    // cycle range (255 is the max duty cycle).
    double scaleFactor = 255 / maxSpeed;

    // Scale the velocity command to our duty cycle range.
    uint8_t dutyRequest = abs(commandedVelocity) * scaleFactor;

    // Command the move.
    motor.MotorInBDuty(dutyRequest);

    return true;
}