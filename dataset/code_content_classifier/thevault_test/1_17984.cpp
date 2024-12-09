TEST_F(PhysicsSystemFixture, NestedModel)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/nested_model.sdf";

  sdf::Root root;
  root.Load(sdfFile);
  const sdf::World *world = root.WorldByIndex(0);
  ASSERT_TRUE(nullptr != world);

  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(1us);

  // Create a system that records the poses of the links after physics
  test::Relay testSystem;

  std::unordered_map<std::string, ignition::math::Pose3d> postUpModelPoses;
  std::unordered_map<std::string, ignition::math::Pose3d> postUpLinkPoses;
  std::unordered_map<std::string, std::string> parents;
  testSystem.OnPostUpdate(
    [&postUpModelPoses, &postUpLinkPoses, &parents](const gazebo::UpdateInfo &,
    const gazebo::EntityComponentManager &_ecm)
    {
      _ecm.Each<components::Model, components::Name, components::Pose>(
        [&](const ignition::gazebo::Entity &_entity, const components::Model *,
        const components::Name *_name, const components::Pose *_pose)->bool
        {
          // store model pose
          postUpModelPoses[_name->Data()] = _pose->Data();

          // store parent model name, if any
          auto parentId = _ecm.Component<components::ParentEntity>(_entity);
          if (parentId)
          {
            auto parentName =
                _ecm.Component<components::Name>(parentId->Data());
            parents[_name->Data()] = parentName->Data();
          }
          return true;
        });

      _ecm.Each<components::Link, components::Name, components::Pose,
                components::ParentEntity>(
        [&](const ignition::gazebo::Entity &, const components::Link *,
        const components::Name *_name, const components::Pose *_pose,
        const components::ParentEntity *_parent)->bool
        {
          // store link pose
          postUpLinkPoses[_name->Data()] = _pose->Data();

          // store parent model name
          auto parentName = _ecm.Component<components::Name>(_parent->Data());
          parents[_name->Data()] = parentName->Data();
          return true;
        });

      return true;
    });

  server.AddSystem(testSystem.systemPtr);
  server.Run(true, 1, false);

  EXPECT_EQ(2u, postUpModelPoses.size());
  EXPECT_EQ(2u, postUpLinkPoses.size());
  EXPECT_EQ(4u, parents.size());

  auto modelIt = postUpModelPoses.find("model_00");
  EXPECT_NE(postUpModelPoses.end(), modelIt);
  EXPECT_EQ(math::Pose3d(0, 0, 0.5, 0, 0, 0), modelIt->second);

  modelIt = postUpModelPoses.find("model_01");
  EXPECT_NE(postUpModelPoses.end(), modelIt);
  EXPECT_EQ(math::Pose3d(1.0, 0, 0.0, 0, 0, 0), modelIt->second);

  auto linkIt = postUpLinkPoses.find("link_00");
  EXPECT_NE(postUpLinkPoses.end(), linkIt);
  EXPECT_EQ(math::Pose3d(0, 0, 0.0, 0, 0, 0), linkIt->second);

  linkIt = postUpLinkPoses.find("link_01");
  EXPECT_NE(postUpLinkPoses.end(), linkIt);
  EXPECT_EQ(math::Pose3d(0.25, 0, 0.0, 0, 0, 0), linkIt->second);

  auto parentIt = parents.find("model_00");
  EXPECT_NE(parents.end(), parentIt);
  EXPECT_EQ("nested_model_world", parentIt->second);

  parentIt = parents.find("model_01");
  EXPECT_NE(parents.end(), parentIt);
  EXPECT_EQ("model_00", parentIt->second);

  parentIt = parents.find("link_00");
  EXPECT_NE(parents.end(), parentIt);
  EXPECT_EQ("model_00", parentIt->second);

  parentIt = parents.find("link_01");
  EXPECT_NE(parents.end(), parentIt);
  EXPECT_EQ("model_01", parentIt->second);
}