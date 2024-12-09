int CanCommunication::manualCalibration()
{
    std::vector<int> motor_id_list;
    std::vector<int> steps_list;
    if (!get_motors_calibration_offsets(motor_id_list, steps_list)) {
        return CAN_STEPPERS_CALIBRATION_FAIL;
    }

    for (int i = 0; i < motors.size(); i++) {
        if (motors.at(i)->isEnabled()) {
            // compute step offset to send
            int offset_to_send = 0;
            int sensor_offset_steps = 0;
            int absolute_steps_at_offset_position = 0;
            int offset_steps = motors.at(i)->getOffsetPosition();
            for (int j = 0; j < motor_id_list.size(); j++) {
                if (motors.at(i)->getId() == motor_id_list.at(j)) {
                    sensor_offset_steps = steps_list.at(j);
                    break;
                }
            }
            if (motors.at(i)->getId() == 1 || motors.at(i)->getId() == 2 || motors.at(i)->getId() == 4) { // position 0.0
                offset_to_send = (sensor_offset_steps - offset_steps) % 1600;
                if (offset_to_send < 0) { offset_to_send += 1600; }
                absolute_steps_at_offset_position = offset_to_send;
            }
            else if (motors.at(i)->getId() == 3) { // max position
                offset_to_send = sensor_offset_steps - offset_steps;
                absolute_steps_at_offset_position = sensor_offset_steps;
            }

            ROS_INFO("Motor %d - sending offset : %d", motors.at(i)->getId(), offset_to_send);
            if (can->sendPositionOffsetCommand(motors.at(i)->getId(), offset_to_send, absolute_steps_at_offset_position) != CAN_OK) {
                return CAN_STEPPERS_CALIBRATION_FAIL;
            }
        }
    }

    return CAN_STEPPERS_CALIBRATION_OK;
}