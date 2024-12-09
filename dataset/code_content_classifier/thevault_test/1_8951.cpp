void ROSImageListener::callback(const sensor_msgs::Image::ConstPtr& msg)
    {
        boost::recursive_mutex::scoped_lock lock(mutex_);
        latestImageMsgReceived = msg;
        hasReceivedNewImage = true;

        ++image_count_;
    }