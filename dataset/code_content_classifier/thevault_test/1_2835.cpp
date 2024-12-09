TEST(TESTSuite, testBroadcaster) {
// Creating NodeHandle
  ros::NodeHandle n;
  tf::TransformListener listener;
  tf::StampedTransform transform;
  listener.waitForTransform("/world", "/talk", ros::Time(0), ros::Duration(10));
  listener.lookupTransform("/world", "/talk", ros::Time(0), transform);
  auto x = transform.getOrigin().x();
  EXPECT_EQ(x, 5);
}