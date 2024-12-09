void AllegroNodeGrasp::graspStabilityCallback(const std_msgs::Bool &msg){
    const bool isStable = msg.data;
    std_msgs::Float32 safe_envelop_torque;
    safe_envelop_torque.data = 0.4;
    
    // In the case of stability, relax applied torque to default safety 
    if (isStable) {
        this->envelopTorqueCallback(safe_envelop_torque);
    } else{
      // Set the joint torques to 1Nm
      std_msgs::Float32 max_envelop_torque;
      max_envelop_torque.data = 1.;
      this->envelopTorqueCallback(max_envelop_torque);
    }
    ROS_WARN("Attention, the grasping stability is changing!");
}