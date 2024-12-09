void MoveDistance(int32_t distance) {
    SerialPort.Send("Moving distance: ");
    SerialPort.SendLine(distance);

    // Command the move of incremental distance
    motor.Move(distance);

    // Waits for all step pulses to output
    SerialPort.SendLine("Moving... Waiting for the step output to finish...");
    while (!motor.StepsComplete()) {
        continue;
    }

    SerialPort.SendLine("Steps Complete");
}