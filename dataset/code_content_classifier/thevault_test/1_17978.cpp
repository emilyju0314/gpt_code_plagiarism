TEST_F(PhysicsSystemFixture, NonDefaultCanonicalLink)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/nondefault_canonical.sdf";

  sdf::Root root;
  root.Load(sdfFile);
  const sdf::World *world = root.WorldByIndex(0);
  ASSERT_TRUE(nullptr != world);

  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(1ns);

  const std::string modelName{"nondefault_canonical"};

  // Create a system that records the pose of the model.
  test::Relay testSystem;

  std::vector<ignition::math::Pose3d> modelPoses;
  testSystem.OnPostUpdate(
    [&modelName, &modelPoses](const gazebo::UpdateInfo &,
    const gazebo::EntityComponentManager &_ecm)
    {
      _ecm.Each<components::Model, components::Name, components::Pose>(
        [&](const ignition::gazebo::Entity &, const components::Model *,
        const components::Name *_name, const components::Pose *_pose)->bool
        {
          if (_name->Data() == modelName)
          {
            modelPoses.push_back(_pose->Data());
          }
          return true;
        });
      return true;
    });

  server.AddSystem(testSystem.systemPtr);
  std::size_t nIters{2000};
  server.Run(true, nIters, false);

  EXPECT_EQ(nIters, modelPoses.size());

  // The model is attached to link2 (it's canonical link) so it will fall during
  // simulation. The new Z position of the model is an offset of -2 in the Z
  // direction from the center of link2.
  EXPECT_NEAR(-(2.0 - 0.2), modelPoses.back().Pos().Z(), 1e-2);
}