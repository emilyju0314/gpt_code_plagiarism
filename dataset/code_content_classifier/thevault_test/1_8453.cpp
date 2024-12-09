void lost_callback (const cpswarm_msgs::TargetPositionEvent::ConstPtr& msg)
{
    if (msg->id == target.id)
        state = STATE_ABORTED;
}