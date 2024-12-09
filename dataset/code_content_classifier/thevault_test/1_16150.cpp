bool RosInterface::callbackActivateLearningMode(niryo_one_msgs::SetInt::Request &req, niryo_one_msgs::SetInt::Response &res)
{
    if (comm->isCalibrationInProgress()) {
        res.status = 400;
        res.message = "You can't activate/deactivate learning mode during motors calibration";
        return true;
    }

    if (calibration_needed == 1 || !comm->isConnectionOk()) { // if can or dxl is disconnected, only allow to activate learning mode
        learning_mode_on = true;
    }
    else {
        learning_mode_on = req.value; 
    }
    
    // reset controller if learning mode -> OFF
    // we want motors to start where they physically are, not from the last command
    if (!learning_mode_on) {
        *(flag_reset_controllers) = true;
        ros::Duration(0.05).sleep();
    }
    
    comm->activateLearningMode(learning_mode_on);
    
    // publish one time
    std_msgs::Bool msg;
    msg.data = learning_mode_on;
    learning_mode_publisher.publish(msg);
   
    res.status = 200;
    res.message = (learning_mode_on) ? "Activating learning mode" : "Deactivating learning mode";
    return true;
}