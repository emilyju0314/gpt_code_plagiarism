void SpawnModelTool::onInitialize() {
  // hide 3d model until the user clicks the span model tool button
  model_state = m_hidden;

  // make an arrow to show axis of rotation
  arrow_ = new rviz::Arrow(scene_manager_, NULL, 2.0f, 0.2f, 0.5f, 0.35f);
  arrow_->setColor(0.0f, 0.0f, 1.0f, 1.0f);  // blue
  arrow_->getSceneNode()->setVisible(
      false);  // will only be visible during rotation phase

  // set arrow to point up (along z)
  Ogre::Quaternion orientation(Ogre::Radian(M_PI), Ogre::Vector3(1, 0, 0));
  arrow_->setOrientation(orientation);

  // full path to the model file
  model_resource_ = "package://flatland_viz/media/simple.dae";

  // load the 3d model
  if (rviz::loadMeshFromResource(model_resource_).isNull()) {
    ROS_ERROR("SpawnModelTool: failed to load model resource '%s'.",
              model_resource_.c_str());
    return;
  }

  // create an Ogre child scene node
  moving_model_node_ =
      scene_manager_->getRootSceneNode()->createChildSceneNode();

  // create an Ogre entity
  Ogre::Entity *entity = scene_manager_->createEntity(model_resource_);

  // attach the object to the entity
  moving_model_node_->attachObject(entity);
  moving_model_node_->setVisible(false);

  SetMovingModelColor(Qt::green);
}