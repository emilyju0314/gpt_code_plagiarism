void DriveTrainSubsystemBase::TurnInDegrees(double relativeAngle, double speed, double turnRadius)
{
    //This is Regular
    ResetEncoder();
    double startDistance = GetLeftEncoderInch();
    double currentDistanceLeft = GetLeftEncoderInch();
    double inch = Util::Abs(relativeAngle)*(Util::PI/180)*turnRadius;
    while (Util::Abs(currentDistanceLeft - startDistance) < inch )
    {
        if(relativeAngle < 0)
        {
            TurnLeft(speed);
        }
        else
        {
            TurnRight(speed);
        }
        currentDistanceLeft = GetLeftEncoderInch();
        frc::SmartDashboard::PutNumber("LeftEncoderInches", GetLeftEncoderInch());
        Util::Log("DriveTrainSubsystemBase: TurnInDegrees: current", currentDistanceLeft);
        Util::Log("DriveTrainSubsystemBase: TurnInDegrees: start", startDistance);
        Util::Log("DriveTrainSubsystemBase: TurnInDegrees: inch", inch);
    }
    Stop();
}