void DriveTrainSubsystemRocky::Init()
{
#ifndef NOHW
  m_leftMotor.SetInverted(false);
  m_rightMotor.SetInverted(true);
  m_leftEncoder.Reset();
  m_rightEncoder.Reset();
  m_leftEncoder.SetReverseDirection(true);
  m_rightEncoder.SetReverseDirection(true);
  //m_leftEncoder.SetDistancePerPulse((WHEELDIAMETER*Util::PI)/PULSE_PER_REVOLUTION);
  //m_rightEncoder.SetDistancePerPulse((WHEELDIAMETER*Util::PI)/PULSE_PER_REVOLUTION);
  m_leftEncoder.SetDistancePerPulse((1.0 / GetPulsesPerRevolution()) * Util::PI * WHEELDIAMETER);
  m_rightEncoder.SetDistancePerPulse((1.0 / GetPulsesPerRevolution()) * Util::PI * WHEELDIAMETER);

  m_camera.Init();
#endif
}