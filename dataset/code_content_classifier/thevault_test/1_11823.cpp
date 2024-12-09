void PID::SetTunings(double Kp, double Ki, double Kd, int POn) {
  if (Kp < 0 || Ki < 0 || Kd < 0)
    return;

  pOn = POn;
  pOnE = POn == P_ON_E;

  dispKp = Kp;
  dispKi = Ki;
  dispKd = Kd;

  double SampleTimeInSec = ((double)SampleTime) / 1000;
  kp = Kp;
  ki = Ki * SampleTimeInSec;
  kd = Kd / SampleTimeInSec;

  if (controllerDirection == REVERSE) {
    kp = (0 - kp);
    ki = (0 - ki);
    kd = (0 - kd);
  }
}