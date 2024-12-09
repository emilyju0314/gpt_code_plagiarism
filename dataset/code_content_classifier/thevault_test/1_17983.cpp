TEST_F(PhysicsSystemFixtureWithDart6_10, JointEffortLimitsCommandComponent)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/revolute_joint_equilibrium.sdf";

  sdf::Root root;
  root.Load(sdfFile);
  const sdf::World *world = root.WorldByIndex(0);
  ASSERT_TRUE(nullptr != world);

  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(1ms);

  const std::string rotatingJointName{"j2"};

  test::Relay testSystem;

  // cppcheck-suppress variableScope
  size_t iteration = 0u;

  // The system is in equilibrium at the beginning.
  // For the first 50 ms, we set effort limits to 1e-6 so that
  // it can't move, and we check it does not. For the other 50 ms, we
  // remove the effort limit and check that the joint has moved.
  // Between times 30 and 40 ms we also add a 100 N force to the joint to
  // check that the limit is held even in presence of force commands. Between
  // times 40 and 50 ms, we add a velocity command to check that velocity
  // commands do not break the effort limit.

  testSystem.OnPreUpdate(
    [&](const gazebo::UpdateInfo &, gazebo::EntityComponentManager &_ecm)
    {
      _ecm.Each<components::Joint, components::Name>(
        [&](const ignition::gazebo::Entity &_entity,
            const components::Joint *, components::Name *_name) -> bool
        {
          if (_name->Data() == rotatingJointName)
          {
            if (iteration == 0u)
            {
              auto limitComp =
                _ecm.Component<components::JointEffortLimitsCmd>(_entity);
              EXPECT_EQ(nullptr, limitComp);
              _ecm.CreateComponent(_entity,
                components::JointEffortLimitsCmd ({{-1e-6, 1e-6}}));
              _ecm.CreateComponent(_entity, components::JointPosition());
            }
            else if (iteration == 50u)
            {
              auto limitComp =
                _ecm.Component<components::JointEffortLimitsCmd>(_entity);
              EXPECT_NE(nullptr, limitComp);
              if (limitComp)
              {
                limitComp->Data() = {{-1e9, 1e9}};
              }
            }
            else
            {
              auto limitComp =
                _ecm.Component<components::JointEffortLimitsCmd>(_entity);
              EXPECT_NE(nullptr, limitComp);
              if (limitComp)
              {
                EXPECT_EQ(0u, limitComp->Data().size());
              }
              if (iteration >= 30u && iteration < 40u)
              {
                _ecm.SetComponentData<components::JointForceCmd>(
                  _entity, {100.0});
              }
              else if (iteration >= 40u && iteration < 50u)
              {
                _ecm.SetComponentData<components::JointVelocityCmd>(
                  _entity, {1.0});
              }
              else if (iteration >= 50u)
              {
                _ecm.Component<components::JointForceCmd>(_entity)->Data() =
                  {1000.0};
              }
            }
            ++iteration;
          }
          return true;
        });
    });

  std::vector<double> positions;

  testSystem.OnPostUpdate([&](
    const gazebo::UpdateInfo &, const gazebo::EntityComponentManager &_ecm)
    {
    _ecm.Each<components::Joint,
    components::Name,
    components::JointPosition>(
      [&](const ignition::gazebo::Entity &,
        const components::Joint *,
        const components::Name *_name,
        const components::JointPosition *_pos)
        {
        if (_name->Data() == rotatingJointName)
        {
          positions.push_back(_pos->Data()[0]);
        }
        return true;
        });
    });

  server.AddSystem(testSystem.systemPtr);
  server.Run(true, 100, false);

  ASSERT_EQ(positions.size(), 100ul);
  // The 1e-6 limit is slightly overcome, but not very much
  EXPECT_NEAR(positions[0], positions[20], 2e-5);
  EXPECT_NEAR(positions[0], positions[30], 3e-5);
  EXPECT_NEAR(positions[0], positions[40], 3e-5);
  EXPECT_NEAR(positions[0], positions[49], 3e-5);
  EXPECT_LT(std::abs(positions[50]) + 1e-2, std::abs(positions[99]));
}