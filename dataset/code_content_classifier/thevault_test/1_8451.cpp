void ActionCallback(const cpswarm_msgs::TrackingGoalConstPtr& goal, action_server_t* as)
{
    NodeHandle nh;

    // target id
    target.id = goal->target;

    // set loop rate
    double loop_rate;
    nh.param(this_node::getName() + "/loop_rate", loop_rate, 5.0);
    Rate rate(loop_rate);

    ROS_INFO("Executing tracking");

    // tracking library
    uav_simple_tracking uav_tracking(target, goal->altitude);

    // execute tracking until state changes
    state = STATE_ACTIVE;
    while (ok() && !as->isPreemptRequested() && state == STATE_ACTIVE) {
        ROS_DEBUG("Tracking step");
        behavior_state_t result = uav_tracking.step(target);
        if (state == STATE_ACTIVE)
            state = result;
        rate.sleep();
        spinOnce();
    }

    // stop moving
    uav_tracking.stop();

    // tracking succeeded
    if (state == STATE_SUCCEEDED) {
        ROS_INFO("Tracking succeeded");
        as->setSucceeded();
    }

    // tracking aborted
    else if (state == STATE_ABORTED) {
        ROS_INFO("Tracking aborted");
        as->setAborted();
    }

    // tracking was preempted
    else{
        ROS_INFO("Tracking preempted");
        as->setPreempted();
    }
}