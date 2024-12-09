TEST_F(MultiCameraTest, cameraSubscribeTest)
{
  // image_transport::ImageTransport it(nh_);
  // cam_left_sub_.subscribe(it, "stereo/camera/left/image_raw", 1);
  // cam_right_sub_.subscribe(it, "stereo/camera/right/image_raw", 1);
  // sync_ = message_filters::Synchronizer<MySyncPolicy>(
  //     MySyncPolicy(4), cam_left_sub_, cam_right_sub_);
  cam_left_sub_.subscribe(nh_, "stereo/camera/left/image_raw", 1);
  cam_right_sub_.subscribe(nh_, "stereo/camera/right/image_raw", 1);
  message_filters::TimeSynchronizer<sensor_msgs::Image, sensor_msgs::Image> sync(
      cam_left_sub_, cam_right_sub_, 4);
  sync.registerCallback(boost::bind(&MultiCameraTest::imageCallback,
      dynamic_cast<MultiCameraTest*>(this), _1, _2));
#if 0
  // wait for gazebo to start publishing
  // TODO(lucasw) this isn't really necessary since this test
  // is purely passive
  bool wait_for_topic = true;
  while (wait_for_topic)
  {
    // @todo this fails without the additional 0.5 second sleep after the
    // publisher comes online, which means on a slower or more heavily
    // loaded system it may take longer than 0.5 seconds, and the test
    // would hang until the timeout is reached and fail.
    if (cam_sub_.getNumPublishers() > 0)
       wait_for_topic = false;
    ros::Duration(0.5).sleep();
  }
#endif

  while (!has_new_image_)
  {
    ros::spinOnce();
    ros::Duration(0.1).sleep();
  }

  double sync_diff = (image_left_stamp_ - image_right_stamp_).toSec();
  EXPECT_EQ(sync_diff, 0.0);

  // This check depends on the update period being much longer
  // than the expected difference between now and the received image time
  // TODO(lucasw)
  // this likely isn't that robust - what if the testing system is really slow?
  double time_diff = (ros::Time::now() - image_left_stamp_).toSec();
  ROS_INFO_STREAM(time_diff);
  EXPECT_LT(time_diff, 1.0);
  // cam_sub_.shutdown();
}