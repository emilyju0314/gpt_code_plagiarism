bool changeString(beginner_tutorials::change_string::Request &req,
        beginner_tutorials::change_string::Response &res) {
    strMsg = req.input;
    res.output = strMsg;             // modify the output string
    /* Info logger level message */
    ROS_INFO_STREAM("Modified the base output string message");
    return true;
}