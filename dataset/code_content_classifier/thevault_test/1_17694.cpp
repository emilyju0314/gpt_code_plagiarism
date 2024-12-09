int SpawnModelTool::processMouseEvent(rviz::ViewportMouseEvent &event) {
  if (!moving_model_node_) {
    return Render;
  }

  Ogre::Vector3 intersection2;
  Ogre::Plane ground_plane(Ogre::Vector3::UNIT_Z, 0.0f);

  if (model_state == m_dragging) {
    if (rviz::getPointOnPlaneFromWindowXY(event.viewport, ground_plane, event.x,
                                          event.y, intersection)) {
      moving_model_node_->setVisible(true);
      moving_model_node_->setPosition(intersection);

      if (event.leftDown()) {
        model_state = m_rotating;
        arrow_->getSceneNode()->setVisible(true);
        arrow_->setPosition(intersection);

        return Render;
      }
    } else {
      moving_model_node_->setVisible(
          false);  // If the mouse is not pointing at the
                   // ground plane, don't show the model.
    }
  }
  if (model_state == m_rotating) {  // model_state is m_rotating

    if (rviz::getPointOnPlaneFromWindowXY(event.viewport, ground_plane, event.x,
                                          event.y, intersection2)) {
      if (event.leftDown()) {
        model_state = m_hidden;
        arrow_->getSceneNode()->setVisible(false);

        // change Vector3 from x,y,z to x,y,angle
        // z is zero since we are intersecting with the ground
        intersection[2] = initial_angle;

        SpawnModelInFlatland();

        return Render | Finished;
      }
      moving_model_node_->setVisible(true);
      moving_model_node_->setPosition(intersection);
      Ogre::Vector3 dir = intersection2 - intersection;
      if (fabs(dir.y) > .001) {
        initial_angle = -1.0 * atan2(dir.x, dir.y);
      } else {
        initial_angle = -90.0 * M_PI / 180.0;
      }
      Ogre::Quaternion orientation(Ogre::Radian(initial_angle),
                                   Ogre::Vector3(0, 0, 1));
      moving_model_node_->setOrientation(orientation);
    }
  }
  return Render;
}