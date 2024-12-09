bool MoveToPosition(uint8_t positionNum) {
    SerialPort.Send("Moving to position: ");
    SerialPort.Send(positionNum);

    switch (positionNum) {
        case 1:
            // Sets Input A "off" for position 1
            motor.MotorInAState(false);
            SerialPort.SendLine(" (Input A Off)");
            break;
        case 2:
            // Sets Input A "on" for position 2
            motor.MotorInAState(true);
            SerialPort.SendLine(" (Input A On)");
            break;
        default:
            // If this case is reached then an incorrect positionNum was entered
            return false;
    }

    // Ensures this delay is at least 2ms longer than the Input A, B filter
    // setting in MSP
    Delay_ms(2 + INPUT_A_B_FILTER);

    // Waits for HLFB to assert (signaling the move has successfully completed)
    SerialPort.SendLine("Moving... Waiting for HLFB");
    while (motor.HlfbState() != MotorDriver::HLFB_ASSERTED) {
        continue;
    }

    SerialPort.SendLine("Move Done");
    return true;
}