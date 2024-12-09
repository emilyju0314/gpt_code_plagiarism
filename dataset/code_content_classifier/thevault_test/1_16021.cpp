units::degree_t DriveTrainSubsystemRocky::GyroGetAngle()
{
#ifndef NOHW
  m_gyroAngle = m_gyro.GetAngle();
  //frc::SmartDashboard::PutNumber("GyroAngle", m_gyroAngle);
  return m_gyroAngle;
#else
  return 0_deg;
#endif
}