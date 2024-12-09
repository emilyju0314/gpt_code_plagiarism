void enableGPIO(rclcpp::Client<deepracer_interfaces_pkg::srv::ServoGPIOSrv>::SharedPtr &servoGPIOClient){
        auto servoGPIORequest = std::make_shared<deepracer_interfaces_pkg::srv::ServoGPIOSrv::Request>();
        // 0 for enable and 1 for disable
        servoGPIORequest->enable = 0;
        auto future_result_servo_gpio = servoGPIOClient->async_send_request(servoGPIORequest);
    }