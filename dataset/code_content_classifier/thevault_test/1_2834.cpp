TEST(TESTSuite, testServiceRun) {
  ros::NodeHandle n;
  ros::ServiceClient client =
  n.serviceClient<beginner_tutorials::change_string>(
      "change_string");
  beginner_tutorials::change_string srv;
  srv.request.input = "new_string";
  client.call(srv);
  EXPECT_STREQ("new_string", srv.response.output.c_str());
}