void CanCommunication::hardwareControlWrite()
{
    if (ros::Time::now().toSec() - time_hw_last_write > 1.0/hw_write_frequency) {
        time_hw_last_write += 1.0/hw_write_frequency;

        // write torque ON/OFF
        if (write_torque_on_enable) {
            if (can->sendTorqueOnCommand(CAN_BROADCAST_ID, torque_on) != CAN_OK) {
                ROS_ERROR("Failed to send torque on");
            }
            else {
                write_torque_on_enable = false; // disable writing on success
            }

        }

        // write synchronize position
        if (write_synchronize_enable) {
            bool synchronize_write_success = true;

            for (int i = 0 ; i < motors.size(); i++) {
                if (motors.at(i)->isEnabled()) {
                    if (can->sendSynchronizePositionCommand(motors.at(i)->getId(), write_synchronize_begin_traj) != CAN_OK) {
                        synchronize_write_success = false;
                    }
                }
            }

            if (synchronize_write_success) {
                write_synchronize_enable = false; // disable writing after success
            }
            else {
                ROS_ERROR("Failed to send synchronize position command");
            }
        }

        // write position
        if (write_position_enable) {


            for (int i = 0 ; i < motors.size(); i++) {
                if (motors.at(i)->isEnabled()) {

                    if (can->sendPositionCommand(motors.at(i)->getId(), motors.at(i)->getPositionCommand()) != CAN_OK) {
                        //ROS_ERROR("Failed to send position");

                    }
                }
            }
        }

        // write micro steps
        if (write_micro_steps_enable) {
            bool micro_steps_write_success = true;
            for (int i = 0 ; i < motors.size(); i++) {
                if (motors.at(i)->isEnabled()) {
                    if (can->sendMicroStepsCommand(motors.at(i)->getId(), motors.at(i)->getMicroStepsCommand()) != CAN_OK) {
                        micro_steps_write_success = false;
                    }
                }
            }

            if (micro_steps_write_success) {
                write_micro_steps_enable = false; // disable writing after success
            }
            else {
                ROS_ERROR("Failed to send Micro Steps");
            }
        }

        // write max effort
        if (write_max_effort_enable) {
            bool max_effort_write_success = true;

            for (int i = 0; i < motors.size(); i++) {
                if (motors.at(i)->isEnabled()) {
                    if (can->sendMaxEffortCommand(motors.at(i)->getId(), motors.at(i)->getMaxEffortCommand()) != CAN_OK) {
                        max_effort_write_success = false;
                    }
                }
            }

            if (max_effort_write_success) {
                write_max_effort_enable = false; // disable writing on success
            }
            else {
                ROS_ERROR("Failed to send Max Effort");
            }
        }
        // conveyor belt commands

    }
}