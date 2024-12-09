void DriveTrainSubsystemBase::ForwardInInch(double inch, double angle, double speed)
{
    WhereToTurn(-0.7, 40);

    ResetEncoder();
    //This is Regular
    double startDistanceRight = GetRightEncoderInch();
    double currentDistanceRight = GetRightEncoderInch();
    double startDistanceLeft = GetLeftEncoderInch();
    double currentDistanceLeft = GetLeftEncoderInch();

    double startDistanceRightRaw = GetLeftEncoderRaw();
    double currentDistanceRightRaw = GetRightEncoderRaw();
    double startDistanceLeftRaw = GetLeftEncoderRaw();
    double currentDistanceLeftRaw = GetLeftEncoderRaw();

    double multiplierR = 0.0;
    double SPEED_INCREMENT = 0.005;
    double ENCODER_DEADZONE = 40;
    while ((Util::Abs(currentDistanceLeft - startDistanceLeft) < inch))
        // || (Util::Abs(currentDistanceRight - startDistanceRight) < inch))
    {
        //Forward(speed);
        Util::Log("Right Multiplier", multiplierR, "DriveTrainSubsystemBase");
        MoveTank(speed,speed*multiplierR);
        Util::DelayInSeconds(0.02_s);
        Util::Log("Start Distance Right", startDistanceRightRaw, "DriveTrainSubsystemBase");
        Util::Log("Start Distance Left", startDistanceLeftRaw, "DriveTrainSubsystemBase");
        Util::Log("Delta Right", (-currentDistanceRightRaw)-(-startDistanceRightRaw), "DriveTrainSubsystemBase");
        Util::Log("Delta Left", currentDistanceLeftRaw-startDistanceLeftRaw, "DriveTrainSubsystemBase");
        currentDistanceRight = GetRightEncoderInch();
        currentDistanceLeft = GetLeftEncoderInch();
        currentDistanceRightRaw = GetRightEncoderRaw();
        currentDistanceLeftRaw = GetLeftEncoderRaw();
        if(Util::Abs(currentDistanceRightRaw-startDistanceRightRaw)<Util::Abs(currentDistanceLeftRaw-startDistanceLeftRaw)-ENCODER_DEADZONE)
        {
            multiplierR += SPEED_INCREMENT;
        }
        else if(Util::Abs(currentDistanceRightRaw-startDistanceRightRaw)>Util::Abs(currentDistanceLeftRaw-startDistanceLeftRaw)+ENCODER_DEADZONE)
        {
            multiplierR -= SPEED_INCREMENT;
        }
        if(speed*multiplierR>1.0)
        {
            multiplierR -= SPEED_INCREMENT;
        }
        else if(speed*multiplierR<-1.0)
        {
            multiplierR += SPEED_INCREMENT;
        }
    }
    if (currentDistanceLeft > inch)
    {
        ResetEncoder();
    }
    Stop();
}