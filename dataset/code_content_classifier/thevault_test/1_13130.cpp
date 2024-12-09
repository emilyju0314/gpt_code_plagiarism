void Robot::RobotPeriodic() {

  //Gets axis for each controller (Driving/Operating)
  double JoyY = -JoyAccel1.GetY();
  double WheelX = RaceWheel.GetX();

  //Power get's cut from one side of the bot to straighten out when driving straight
  float sumAngle = Gyro.GetAngle();
  float derivAngle = sumAngle - LastSumAngle;
  float correctionAngle = (sumAngle * 0.00) + (derivAngle *0.00);
  //                                    ^Subject to change...
  
  //Gear intake
  if(Xbox.GetRawButton(3)) {
    
  }

  //Drive Code for CNS and modified for Axon
  //Button 5 on the wheel activates point turning
  if (RaceWheel.GetRawButton(5)) {
    RightFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, WheelX);
    RightMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, WheelX);
    RightBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, WheelX);
    LeftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -WheelX);
    LeftMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -WheelX);
    LeftBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -WheelX);
    Gyro.Reset();
  } 
  else {
    //Code for regular turning
    if ((WheelX < -0.01 || WheelX > 0.01) && (JoyY > 0.06 || JoyY < -0.06)) {
      //              ^ You set the dead zone for the wheel and the joysticks
      RightFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY + turnFact*(WheelX));
      RightMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY + turnFact*(WheelX));
      RightBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY + turnFact*(WheelX));
      LeftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY - turnFact*(WheelX));
      LeftMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,  -JoyY - turnFact*(WheelX));
      LeftBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,  -JoyY - turnFact*(WheelX));
      Gyro.Reset();
    }
    //Code for driving straight
    else if ((JoyY > 0.1|| JoyY < -0.1)) {
      //              ^ You set the dead zone for the joystick
      RightFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY - correctionAngle);
      RightMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, JoyY - correctionAngle);
      RightBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY - correctionAngle);
      LeftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY + correctionAngle);
      LeftMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, JoyY + correctionAngle);
      LeftBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -JoyY + correctionAngle);
    } 
    else {
      if(!beRunning) {
        // Dont spin any drive train motors if the driver is not doing anything
        RightFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        RightMid.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        RightBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        LeftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        LeftFront.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        LeftBack.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
      }
    }
  }
  
  /* Straightens out bot here when driving straight */
  LastSumAngle = sumAngle;

}