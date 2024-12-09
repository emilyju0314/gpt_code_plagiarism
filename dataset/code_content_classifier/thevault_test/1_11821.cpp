PID::PID(double *Input, double *Output, double *Setpoint, double Kp, double Ki,
         double Kd, int POn, int ControllerDirection) {
  myOutput = Output;
  myInput = Input;
  mySetpoint = Setpoint;
  inAuto = false;

  PID::SetOutputLimits(0, 255); // default output limit corresponds to
                                // the arduino pwm limits

  SampleTime = 100; // default Controller Sample Time is 0.1 seconds

  PID::SetControllerDirection(ControllerDirection);
  PID::SetTunings(Kp, Ki, Kd, POn);

  lastTime = Hal.millis() - SampleTime;
}