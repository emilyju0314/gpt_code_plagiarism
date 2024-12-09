void SpawnModelTool::activate() {
  ROS_INFO_STREAM("SpawnModelTool::activate ");

  LoadModelDialog *model_dialog = new LoadModelDialog(NULL, this);
  model_dialog->setModal(true);
  model_dialog->show();
}