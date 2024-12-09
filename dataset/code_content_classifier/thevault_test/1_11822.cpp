bool PID::Compute() {
  if (!inAuto)
    return false;
  unsigned long now = Hal.millis();
  unsigned long timeChange = (now - lastTime);
  if (timeChange >= SampleTime) {
    /*Compute all the working error variables*/
    double input = *myInput;
    double error = *mySetpoint - input;
    double dInput = (input - lastInput);
    outputSum += (ki * error);

    /*Add Proportional on Measurement, if P_ON_M is specified*/
    if (!pOnE)
      outputSum -= kp * dInput;

    if (outputSum > outMax)
      outputSum = outMax;
    else if (outputSum < outMin)
      outputSum = outMin;

    /*Add Proportional on Error, if P_ON_E is specified*/
    double output;
    if (pOnE)
      output = kp * error;
    else
      output = 0;

    /*Compute Rest of PID Output*/
    output += outputSum - kd * dInput;

    if (output > outMax)
      output = outMax;
    else if (output < outMin)
      output = outMin;
    *myOutput = output;

    /*Remember some variables for next time*/
    lastInput = input;
    lastTime = now;
    return true;
  } else
    return false;
}