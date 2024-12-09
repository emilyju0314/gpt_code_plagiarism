void PlanningPanel::setControllerCommandTopic(const QString& newControllerCommandTopic)
{
  // Only take action if the name has changed.
  if (newControllerCommandTopic != controllerCommandTopicName_) {
    controllerCommandTopicName_ = newControllerCommandTopic;
    Q_EMIT configChanged();
  }
}