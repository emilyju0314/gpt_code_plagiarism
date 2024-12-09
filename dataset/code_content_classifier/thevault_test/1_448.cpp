void imageCallback(const sensor_msgs::ImageConstPtr& msg){

  try{

    cv::imshow("Face Detection", cv_bridge::toCvShare(msg, "bgr8")->image); // displays an subcribed image 
    cv::waitKey(30);
  
  }

  catch (cv_bridge::Exception& e){
  
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str()); // display Exception whwn image could not be displayed

  }

}