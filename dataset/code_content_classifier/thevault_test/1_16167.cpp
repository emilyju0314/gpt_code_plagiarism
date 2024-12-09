int CanCommunication::calibrateMotors(int calibration_step)
{
    if (!is_can_connection_ok) {
        return CAN_STEPPERS_CALIBRATION_FAIL;
    }

    // this flag should be cleared by a user action to continue
    if (waiting_for_user_trigger_calibration) {
        return CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT;
    }

    ROS_INFO("START Calibrating stepper motors, step number %d", calibration_step);
    stopHardwareControlLoop();
    ros::Duration(0.1).sleep();

    // If user wants to do a manual calibration, just send offset to current position
    if (steppers_calibration_mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL) {
        if (calibration_step > 1) {
            return CAN_STEPPERS_CALIBRATION_OK; // do manual calibration only once
        }
        calibration_in_progress = true;
        int result = manualCalibration();
        calibration_in_progress = false;
        return result;
    }
    else if (steppers_calibration_mode == CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
        if (calibration_step == 1) {
            calibration_in_progress = true;
            int result = autoCalibrationStep1();
            return result;
        }
        else if (calibration_step == 2) {
            int result = autoCalibrationStep2();
            calibration_in_progress = false;
            return result;
        }
    }
    else {
        return CAN_STEPPERS_CALIBRATION_FAIL;
    }
}