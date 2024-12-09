int CanCommunication::relativeMoveMotor(StepperMotorState* motor, int steps, int delay, bool wait)
{
    if (!motor->isEnabled()) {
        return CAN_OK;
    }

    if (can->sendTorqueOnCommand(motor->getId(), true) != CAN_OK) {
        ROS_ERROR("Failed to send torque ON to motor %d", motor->getId());
        return CAN_FAIL;
    }

    if (can->sendRelativeMoveCommand(motor->getId(), steps, delay) != CAN_OK) {
        ROS_ERROR("Relative Move motor failed for motor %d", motor->getId());
        return CAN_FAIL;
    }
    if (wait) {
        ros::Duration(steps*delay/1000000 + 0.5).sleep(); // wait for 0.5 sec more to finish
    }

    return CAN_OK;
}