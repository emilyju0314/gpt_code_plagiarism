TEST(TESTSuite, testServiceExistence) {
  ros::NodeHandle n;
  ros::ServiceClient client =
  n.serviceClient<beginner_tutorials::change_string>(
      "change_string");
  bool exists(client.waitForExistence(ros::Duration(5)));
  EXPECT_TRUE(exists);
}