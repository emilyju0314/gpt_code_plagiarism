int CanCommunication::scanAndCheck()
{
    int counter = 0;

    while (hw_is_busy && counter < 100) {
        ros::Duration(TIME_TO_WAIT_IF_BUSY).sleep();
        counter++;
    }

    if (counter == 100) {
        debug_error_message = "Failed to scan motors, CAN bus is too busy. Will retry...";
        ROS_WARN("Failed to scan motors, CAN bus is too busy (counter max : %d)", counter);
        return CAN_SCAN_BUSY;
    }

    hw_is_busy = true;

    // if some motors are disabled, just declare them as connected
    bool m1_ok = !m1.isEnabled();
    bool m2_ok = !m2.isEnabled();
    bool m3_ok = !m3.isEnabled();
    bool m4_ok = !m4.isEnabled();

    bool m6_ok = true;//!m6.isEnabled();
    bool m7_ok = true; //!m7.isEnabled();
    double time_begin_scan = ros::Time::now().toSec();
    double min_time_to_wait = 0.25;
    double timeout = 0.5;

    while (!m1_ok || !m2_ok || !m3_ok || !m4_ok || !m6_ok || !m7_ok || (ros::Time::now().toSec() - time_begin_scan < min_time_to_wait)) {
        ros::Duration(0.001).sleep(); // check at 1000 Hz

        if (can->canReadData()) {
            long unsigned int rxId;
            unsigned char len;
            unsigned char rxBuf[8];

            can->readMsgBuf(&rxId, &len, rxBuf);
            // Validate id
            int motor_id = rxId & 0x00F; // 0x101 for id 1, 0x102 for id 2, ...
            if (motor_id == m1.getId()) {
                m1_ok = true;
            }
            else if (motor_id == m2.getId()) {
                m2_ok = true;
            }
            else if (motor_id == m3.getId()) {
                m3_ok = true;
            }
            else if (hardware_version == 1 && motor_id == m4.getId()) { // m4 only for Niryo One V1
                m4_ok = true;
            }
            else { // detect unallowed motor
                ROS_ERROR("Scan CAN bus : Received can frame with wrong id : %d", motor_id);
                hw_is_busy = false;
                debug_error_message = "Unallowed connected motor : ";
                debug_error_message += std::to_string(motor_id);
                ROS_ERROR("%s", debug_error_message.c_str());
                return CAN_SCAN_NOT_ALLOWED;
            }
        }

        if (ros::Time::now().toSec() - time_begin_scan > timeout) {
            ROS_ERROR("CAN SCAN Timeout");
            debug_error_message = "CAN bus scan failed : motors ";
            if (!m1_ok) { debug_error_message += m1.getName(); debug_error_message += ", "; }
            if (!m2_ok) { debug_error_message += m2.getName(); debug_error_message += ", "; }
            if (!m3_ok) { debug_error_message += m3.getName(); debug_error_message += ", "; }
            if (!m4_ok) { debug_error_message += m4.getName(); debug_error_message += ", "; }
            debug_error_message += "are not connected";
            is_can_connection_ok = false;
            hw_is_busy = false;
            ROS_ERROR("%s", debug_error_message.c_str());
            return CAN_SCAN_TIMEOUT;
        }
    }

    //ROS_INFO("CAN Connection ok");
    hw_is_busy = false;
    is_can_connection_ok = true;
    debug_error_message = "";
    return CAN_SCAN_OK;
}