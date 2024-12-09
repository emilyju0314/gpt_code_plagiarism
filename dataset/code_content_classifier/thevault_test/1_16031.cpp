void DriveTrainSubsystemBase::TurnInDegreesGyro(double relativeAngle, double speed)
 {
     //troubleshooting values, use these for testing what makes the robot go to the relative angle
     frc::SmartDashboard::PutNumber("Current Angle", relativeAngle);
     frc::SmartDashboard::PutBoolean("In Place", true);
     double startAngle = IMUGetAngle();
     double currentAngle = IMUGetAngle();
     //logic used to turn the robot left or right and keeping it turned
     if (relativeAngle > 0)
     {
         TurnRight(speed);
         while (currentAngle - startAngle < relativeAngle)
         {
            currentAngle = IMUGetAngle();
         }
     }
     if (relativeAngle < 0)
     {
         TurnLeft(speed);
         while (currentAngle - startAngle > relativeAngle)
         {
            currentAngle = IMUGetAngle();
         }
     }
     Stop();
 }