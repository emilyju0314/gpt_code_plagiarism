void spawnCollisionObjects(moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
{
  double z_offset_box = .25;  // The z-axis points away from the gripper
  double z_offset_cylinder = .1;

  moveit_msgs::CollisionObject box;
  box.id = "box";
  box.header.frame_id = "panda_hand";
  box.pose.position.z = z_offset_box;
  box.pose.orientation.w = 1.0;  // Neutral orientation

  box.primitives.resize(1);
  box.primitive_poses.resize(1);
  box.primitives[0].type = box.primitives[0].BOX;
  box.primitives[0].dimensions.resize(3);
  box.primitives[0].dimensions[0] = 0.05;
  box.primitives[0].dimensions[1] = 0.1;
  box.primitives[0].dimensions[2] = 0.02;
  box.primitive_poses[0].orientation.w = 1.0;  // Neutral orientation

  box.subframe_names.resize(1);
  box.subframe_poses.resize(1);

  box.subframe_names[0] = "bottom";
  box.subframe_poses[0].position.y = -.05;

  tf2::Quaternion orientation;
  orientation.setRPY(TAU / 4.0, 0, 0);  // 1/4 turn
  box.subframe_poses[0].orientation = tf2::toMsg(orientation);

  // Next, define the cylinder
  moveit_msgs::CollisionObject cylinder;
  cylinder.id = "cylinder";
  cylinder.header.frame_id = "panda_hand";
  cylinder.pose.position.z = z_offset_cylinder;
  orientation.setRPY(0, TAU / 4.0, 0);
  cylinder.pose.orientation = tf2::toMsg(orientation);

  cylinder.primitives.resize(1);
  cylinder.primitive_poses.resize(1);
  cylinder.primitives[0].type = box.primitives[0].CYLINDER;
  cylinder.primitives[0].dimensions.resize(2);
  cylinder.primitives[0].dimensions[0] = 0.06;      // height (along x)
  cylinder.primitives[0].dimensions[1] = 0.005;     // radius
  cylinder.primitive_poses[0].orientation.w = 1.0;  // Neutral orientation

  cylinder.subframe_poses.resize(1);
  cylinder.subframe_names.resize(1);
  cylinder.subframe_names[0] = "tip";
  cylinder.subframe_poses[0].position.z = 0.03;
  cylinder.subframe_poses[0].orientation.w = 1.0;  // Neutral orientation

  // Lastly, the objects are published to the PlanningScene. In this tutorial, we publish a box and a cylinder.
  box.operation = moveit_msgs::CollisionObject::ADD;
  cylinder.operation = moveit_msgs::CollisionObject::ADD;
  planning_scene_interface.applyCollisionObjects({ box, cylinder });
}