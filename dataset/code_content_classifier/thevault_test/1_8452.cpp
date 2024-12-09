void update_callback (const cpswarm_msgs::TargetPositionEvent::ConstPtr& msg)
{
    // update information for this target
    if (msg->id == target.id)
        target = *msg;
}