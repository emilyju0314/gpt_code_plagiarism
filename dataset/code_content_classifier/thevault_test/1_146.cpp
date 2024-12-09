void PlanningPanel::save(rviz::Config config) const
{
rviz::Panel::save(config);
config.mapSetValue("path_request_topic", planningServiceName_);
config.mapSetValue("get_current_state_service", currentStateServiceName_);
config.mapSetValue("controller_command_topic", controllerCommandTopicName_);



auto getCheckedStatusAsString = [](QCheckBox *checkBox){
  const std::string checkStatus = checkBox->isChecked() ? "checked" : "not_checked";
  return QString::fromStdString(checkStatus);;
};
QString checkedStatus = getCheckedStatusAsString(approachPosePlanningCheckBox_);
config.mapSetValue("plan_approach_pose",checkedStatus);
checkedStatus = getCheckedStatusAsString(currentStateAsStartCheckBox_);
config.mapSetValue("use_current_pose_as_start", checkedStatus);

}