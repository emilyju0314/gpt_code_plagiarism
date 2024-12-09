TEST_F(PhysicsSystemFixtureWithDart6_10, JointVelocityLimitsCommandComponent)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/revolute_joint.sdf";

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

  // The system is not in equilibrium at the beginning, so normally, joint j2
  // would move. For the first 50 ms, we set velocity limits to 0.1 so that
  // it can't move very fast, and we check it does not. For the other 50 ms, we
  // remove the velocity limit and check that the joint has moved faster.
  // Between times 30 and 40 ms we also add a 100 N force to the joint to
  // check that the limit is held even in presence of force commands. Between
  // times 40 and 50 ms, we add a velocity command to check that velocity
  // commands do not break the velocity limit.

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
                _ecm.Component<components::JointVelocityLimitsCmd>(_entity);
              EXPECT_EQ(nullptr, limitComp);
              _ecm.CreateComponent(_entity,
                components::JointVelocityLimitsCmd ({{-0.1, 0.1}}));
              _ecm.CreateComponent(_entity, components::JointVelocity());
            }
            else if (iteration == 50u)
            {
              auto limitComp =
                _ecm.Component<components::JointVelocityLimitsCmd>(_entity);
              EXPECT_NE(nullptr, limitComp);
              if (limitComp)
              {
                limitComp->Data() = {{-1e6, 1e6}};
              }
            }
            else
            {
              auto limitComp =
                _ecm.Component<components::JointVelocityLimitsCmd>(_entity);
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
            }
            ++iteration;
          }
          return true;
        });
    });

  std::vector<double> velocities;

  testSystem.OnPostUpdate([&](
    const gazebo::UpdateInfo &, const gazebo::EntityComponentManager &_ecm)
    {
      _ecm.Each<components::Joint,
                components::Name,
                components::JointVelocity>(
        [&](const ignition::gazebo::Entity &,
            const components::Joint *,
            const components::Name *_name,
            const components::JointVelocity *_vel)
        {
          if (_name->Data() == rotatingJointName)
          {
            velocities.push_back(_vel->Data()[0]);
          }
          return true;
        });
    });

  server.AddSystem(testSystem.systemPtr);
  server.Run(true, 100, false);

  ASSERT_EQ(velocities.size(), 100ul);
  // The 0.1 limit is slightly overcome, but not very much
  EXPECT_NEAR(0.1, velocities[20], 1e-2);
  EXPECT_NEAR(0.1, velocities[30], 1e-2);
  EXPECT_NEAR(0.1, velocities[40], 1e-2);
  EXPECT_NEAR(0.1, velocities[49], 1e-2);
  EXPECT_LT(0.5, std::abs(velocities[99]));
}