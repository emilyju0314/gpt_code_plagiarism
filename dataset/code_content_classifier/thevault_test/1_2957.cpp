bool RampToVelocitySelection(uint8_t velocityIndex) {
    SerialPort.Send("Moving to Velocity Selection: ");
    SerialPort.Send(velocityIndex);

    switch (velocityIndex) {
        case 1:
            // Sets Input A and B for velocity 1
            motor.MotorInAState(false);
            motor.MotorInBState(false);
            SerialPort.SendLine(" (Inputs A Off/B Off)");
            break;
        case 2:
            // Sets Input A and B for velocity 2
            motor.MotorInAState(true);
            motor.MotorInBState(false);
            SerialPort.SendLine(" (Inputs A On/B Off)");
            break;
        case 3:
            // Sets Input A and B for velocity 3
            motor.MotorInAState(false);
            motor.MotorInBState(true);
            SerialPort.SendLine(" (Inputs A Off/B On)");
            break;
        case 4:
            // Sets Input A and B for velocity 4
            motor.MotorInAState(true);
            motor.MotorInBState(true);
            SerialPort.SendLine(" (Inputs A On/B On)");
            break;
        default:
            // If this case is reached then an incorrect velocityIndex was
            // entered
            return false;
    }

    // Ensures this delay is at least 2ms longer than the Input A, B filter
    // setting in MSP
    Delay_ms(2 + INPUT_A_B_FILTER);

    // Waits for HLFB to assert (signaling the move has successfully reached its
    // target velocity)
    SerialPort.SendLine("Moving... Waiting for HLFB");
    while (motor.HlfbState() != MotorDriver::HLFB_ASSERTED) {
        continue;
    }

    SerialPort.SendLine("Move Done");
    return true;
}