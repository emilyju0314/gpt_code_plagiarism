walker::walker(ros::NodeHandle nh, ros::Subscriber subs, ros::Publisher pub) {
  linearVel = 0.5;
  angularVel = 1.0;
  pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity",
                                           1000);
  subs = nh.subscribe<sensor_msgs::LaserScan>("/scan", 100,
                                              &walker::laserScanCallback, this);
  ros::Rate loopRate(5);
  while (ros::ok()) {
    // Object to get linear and angular velocity
    geometry_msgs::Twist twist;

    // Initialize twist
    twist.linear.x = 0;
    twist.linear.y = 0;
    twist.linear.z = 0;
    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0;
    if (obstacleInRange() == true) {
      ROS_INFO_STREAM("The obstacle is in the range, Turning...");
      twist.angular.z = angularVel;
    } else {
      ROS_INFO_STREAM("Moving forward, No obstacle present");
      twist.linear.x = linearVel;
    }
    pub.publish(twist);
    ros::spinOnce();
    loopRate.sleep();
  }
}