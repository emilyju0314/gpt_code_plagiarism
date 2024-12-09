void process_image_callback(const sensor_msgs::Image img)
{
	int white_pixel = 255;
	int left_count = 0;
	int middle_count = 0;
	int right_count = 0;
  	int i = 0;
	for (int height = 0; height < img.height; height++) {
		for (int step = 0; step < img.step; step++) {
          if (img.data[i] == white_pixel) {  
			if (step <= img.step*(1.0/3)) {
				left_count += 1;
			} else if (step <= img.step*(2.0/3)) {
				middle_count += 1;
			} else {
				right_count += 1;
			} 
          }
          
          i++;
		}
	}
	
	float current_lin_x = 0.0;
	float current_ang_z = 0.0;
	if (left_count == 0 && middle_count == 0 && right_count == 0) {
		ROS_INFO_STREAM("STOP");
		current_lin_x = 0.0;
		current_ang_z = 0.0;
	} else if (left_count > right_count && left_count > middle_count) {
		ROS_INFO_STREAM("LEFT");
		current_lin_x = 0.0;
		current_ang_z = 0.5;
	} else if (right_count > left_count && right_count > middle_count) {
		ROS_INFO_STREAM("RIGHT");
		current_lin_x = 0.0;
		current_ang_z = -0.5;
	} else {
		ROS_INFO_STREAM("FORWARD");
		current_lin_x = 0.5;
		current_ang_z = 0.0;
	}
	
	
	if (current_lin_x != last_lin_x || current_ang_z != last_ang_z) { 
	    drive_robot(current_lin_x, current_ang_z);
	    last_lin_x = current_lin_x;
        last_ang_z = current_ang_z;
	}
}