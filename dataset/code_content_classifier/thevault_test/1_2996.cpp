char *ReadyStateString(MotorDriver::MotorReadyStates readyState) {
    switch (readyState) {
        case MotorDriver::MOTOR_DISABLED:
            return (char *)"Disabled";
        case MotorDriver::MOTOR_ENABLING:
            return (char *)"Enabling";
        case MotorDriver::MOTOR_FAULTED:
            return (char *)"Faulted";
        case MotorDriver::MOTOR_READY:
            return (char *)"Ready";
        case MotorDriver::MOTOR_MOVING:
            return (char *)"Moving";
        default:
            // Something has gone wrong if this is printed
            return (char *)"???";
    }
}