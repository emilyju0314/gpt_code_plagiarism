double DriveTrainSubsystemRocky::GetLidarDetectionDistance()
{
#ifndef NOHW
  double val = m_lidar.GetDistanceInInches();
  frc::SmartDashboard::PutNumber("DriveTrain Lidar", val);
  return val;
#else
  return 0;
#endif
}