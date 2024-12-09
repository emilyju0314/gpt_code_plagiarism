void waitForService(rclcpp::ClientBase::SharedPtr client,
                        std::shared_ptr<rclcpp::Node> ctrlNode) {
        while (!client->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(ctrlNode->get_logger(), "%s node failed", client->get_service_name());
            }
            RCLCPP_INFO(ctrlNode->get_logger(), "%s not available, waiting again...", client->get_service_name());
        }
    }