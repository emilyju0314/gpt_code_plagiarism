TEST_F(PhysicsSystemFixture, MultiAxisJointPosition)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/demo_joint_types.sdf";
  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(0ns);

  test::Relay testSystem;
  // Create JointPosition components if they don't already exist
  testSystem.OnPreUpdate(
      [&](const gazebo::UpdateInfo &, gazebo::EntityComponentManager &_ecm)
      {
        _ecm.Each<components::Joint>(
            [&](const ignition::gazebo::Entity &_entity,
                components::Joint *) -> bool
            {
              auto posComp = _ecm.Component<components::JointPosition>(_entity);
              if (!posComp)
              {
                _ecm.CreateComponent(_entity, components::JointPosition());
              }
              return true;
            });
      });

  std::map<std::string, std::size_t> jointPosDof;

  testSystem.OnPostUpdate(
    [&](const gazebo::UpdateInfo &, const gazebo::EntityComponentManager &_ecm)
    {
      _ecm.Each<components::Joint, components::Name, components::JointPosition>(
        [&](const ignition::gazebo::Entity &,
            const components::Joint *,
            const components::Name *_name,
            const components::JointPosition *_jointPos) -> bool
        {
          jointPosDof[_name->Data()] = _jointPos->Data().size();
          return true;
        });
    });

  server.AddSystem(testSystem.systemPtr);
  server.Run(true, 1, false);

  std::map<std::string, std::size_t> jointsToCheck {
    {"revolute_demo", 1},
    {"prismatic_demo", 1},
    {"ball_demo", 3},
    {"screw_demo", 1},
    {"universal_demo", 2},
    {"fixed_demo", 0},
    // Gearbox not supported yet
    // {"gearbox_demo", 1},
    // Revolute2 not supported yet
    // {"revolute2_demo", 2},
  };

  for (const auto &[jName, jDof] : jointsToCheck)
  {
    ASSERT_TRUE(jointPosDof.find(jName) != jointPosDof.end()) << jName;
    EXPECT_EQ(jDof, jointPosDof[jName]) << jName;
  }

  // Run several more times and ensure that the DOF stays the same
  server.Run(true, 10, false);
  for (const auto &[jName, jDof] : jointsToCheck)
  {
    ASSERT_TRUE(jointPosDof.find(jName) != jointPosDof.end()) << jName;
    EXPECT_EQ(jDof, jointPosDof[jName]) << jName;
  }
}