void LockSensorCallback() {
    // A 1 ms delay is required in order to pass the correct filtered sensor
    // state.
    Delay_ms(1);
    motor.MotorInAState(LockSensor.State());
}