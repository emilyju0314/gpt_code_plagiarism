void verifyPose(const math::Pose3d& pose1, const math::Pose3d& pose2)
{
  EXPECT_NEAR(pose1.Pos().X(), pose2.Pos().X(), 1e-1);
  EXPECT_NEAR(pose1.Pos().Y(), pose2.Pos().Y(), 1e-1);
  EXPECT_NEAR(pose1.Pos().Z(), pose2.Pos().Z(), 1e-2);
  EXPECT_ANGLE_NEAR(pose1.Rot().Roll(), pose2.Rot().Roll(), 1e-2);
  EXPECT_ANGLE_NEAR(pose1.Rot().Pitch(), pose2.Rot().Pitch(), 1e-2);
  EXPECT_ANGLE_NEAR(pose1.Rot().Yaw(), pose2.Rot().Yaw(), 1e-1);
}