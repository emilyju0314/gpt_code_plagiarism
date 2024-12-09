void SplineBounce::GenerateTrajectory()
{
  const frc::Pose2d start{0.0_ft,0.0_ft,frc::Rotation2d(0.0_deg)};
  const frc::Pose2d end{0.0_ft,0.0_ft,frc::Rotation2d(0.0_deg)};

  std::vector<frc::Translation2d> interiorWaypoints
  {
    frc::Translation2d{0.0_ft, 0.0_ft},
    frc::Translation2d{0.0_ft, 0.0_ft}
  };

  frc::TrajectoryConfig config{12_fps, 12_fps_sq};
  config.SetReversed(false);

  auto trajectory = frc::TrajectoryGenerator::GenerateTrajectory(start, interiorWaypoints, end, config);
}