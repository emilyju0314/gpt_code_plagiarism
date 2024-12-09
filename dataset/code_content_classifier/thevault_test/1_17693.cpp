void SpawnModelTool::deactivate() {
  if (moving_model_node_) {
    moving_model_node_->setVisible(false);
  }
}