void ControllerEditWidget::loadControllersTypesComboBox()
{
  // Only load this combo box once
  if (has_loaded_)
    return;
  has_loaded_ = true;

  const std::vector<std::string> default_types = { "effort_controllers/JointTrajectoryController",
                                                   "velocity_controllers/JointTrajectoryController",
                                                   "position_controllers/JointTrajectoryController",
                                                   "FollowJointTrajectory", "GripperCommand" };

  // Remove all old items
  controller_type_field_->clear();

  // Loop through all controller default_types and add to combo box
  for (const std::string& type : default_types)
    controller_type_field_->addItem(type.c_str());
}