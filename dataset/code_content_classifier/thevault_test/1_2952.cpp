bool MoveIncrements(uint32_t numberOfIncrements, int32_t positionIncrement) {
    SerialPort.Send("Moving ");
    SerialPort.Send(numberOfIncrements);
    SerialPort.Send(" * ");

    switch (positionIncrement) {
        case POSITION_INCREMENT_1:
            // Sets Input A and B to position increment 1
            SerialPort.SendLine(POSITION_INCREMENT_1);
            motor.MotorInAState(false);
            motor.MotorInBState(false);
            break;
        case POSITION_INCREMENT_2:
            // Sets Input A and B to position increment 2
            SerialPort.SendLine(POSITION_INCREMENT_2);
            motor.MotorInAState(true);
            motor.MotorInBState(false);
            break;
        case POSITION_INCREMENT_3:
            // Sets Input A and B to position increment 3
            SerialPort.SendLine(POSITION_INCREMENT_3);
            motor.MotorInAState(false);
            motor.MotorInBState(true);
            break;
        case POSITION_INCREMENT_4:
            // Sets Input A and B to position increment 4
            SerialPort.SendLine(POSITION_INCREMENT_4);
            motor.MotorInAState(true);
            motor.MotorInBState(true);
            break;
        default:
            // If this case is reached then an incorrect positionIncrement was
            // entered
            return false;
    }

    // Delays 2ms longer than the Input A, B filter setting in MSP
    Delay_ms(2 + INPUT_A_B_FILTER);

    // Sends trigger pulses to the motor
    motor.EnableTriggerPulse(numberOfIncrements, TRIGGER_PULSE_TIME, true);

    // Waits for HLFB to assert (signaling the move has successfully completed)
    SerialPort.SendLine("Moving... Waiting for HLFB");
    while (motor.HlfbState() != MotorDriver::HLFB_ASSERTED) {
        continue;
    }

    SerialPort.SendLine("Move Done");
    return true;
}