StandardOCUTool::StandardOCUTool(int8_t id, const std::string& name, const std::string& iconFileName, const ros::Publisher* publisherViewControl)
                : Tool(id, name, iconFileName)
                , publisherViewControl(publisherViewControl)
                , timerLongClick(this)
                , dragging(false)
                , xOnMouseDown(0)
                , yOnMouseDown(0)
                , currentViewController(NULL)
                {
                }