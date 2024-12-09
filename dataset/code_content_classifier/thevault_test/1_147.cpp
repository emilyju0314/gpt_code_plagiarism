void PlanningPanel::load(const rviz::Config& config)
{
rviz::Panel::load(config);

if (config.mapGetString("path_request_topic", &planningServiceName_)) {
planningServiceNameEditor_->setText(planningServiceName_);
}

if (config.mapGetString("get_current_state_service", &currentStateServiceName_)) {
currStateServiceEditor_->setText(currentStateServiceName_);
}

if (config.mapGetString("controller_command_topic", &controllerCommandTopicName_)) {
controllerCommandTopicEditor_->setText(controllerCommandTopicName_);
}

auto isChecked = [](const QString &qString){
  const std::string str = qString.toStdString();
  return str == "checked";
};

QString checkedStatus;
if (config.mapGetString("use_current_pose_as_start", &checkedStatus)){
  currentStateAsStartCheckBox_->setChecked(isChecked(checkedStatus));
}

//bool isUseCurrentStateAsStart ;
if (config.mapGetString("plan_approach_pose",&checkedStatus)){
  bool checkedValue = isChecked(checkedStatus);
  approachPosePlanningCheckBox_->setChecked(checkedValue);
  setShapeOfGoalMarker(checkedValue);
  geometry_msgs::Pose pose;
  pose.position.x = pose.position.y = pose.position.z = 0.0;
  pose.orientation.w = 1.0;
  pose.orientation.x = pose.orientation.y = pose.orientation.z = 0.0;

  interactive_markers_.enableMarker("goal", pose);
}

}