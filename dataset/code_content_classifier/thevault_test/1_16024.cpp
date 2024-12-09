void DriveTrainSubsystemRocky::PrecisionMovementLidar(double wantedDistance, double speed)
{
#ifndef NOHW
  const double DEAD_ZONE = 5.0;
  double currentDistance = m_lidar.GetDistanceInInches();
  //Logic that moves the robot back or forth to the prefered distance for auto
  while (wantedDistance < (currentDistance + DEAD_ZONE) && wantedDistance > (currentDistance - DEAD_ZONE))
  {
    if (currentDistance < wantedDistance)
    {
      MoveTank(-.5, -.5);
    }
    if (currentDistance > wantedDistance)
    {
      MoveTank(.5, .5);
    }
    currentDistance = m_lidar.GetDistanceInInches();
  }
#endif
}