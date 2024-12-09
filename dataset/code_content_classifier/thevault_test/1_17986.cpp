TEST_F(PhysicsSystemFixture, MovingCanonicalLinkOnly)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = common::joinPaths(PROJECT_SOURCE_PATH, "test", "worlds",
    "only_canonical_link_moves.sdf");

  sdf::Root root;
  root.Load(sdfFile);
  const sdf::World *world = root.WorldByIndex(0);
  ASSERT_TRUE(nullptr != world);

  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(1us);

  // Create a system that records the poses of the links after physics
  test::Relay testSystem;

  size_t numBaseLinkChecks = 0;
  size_t numOuterLinkChecks = 0;
  size_t numBaseLinkCustomChecks = 0;
  size_t numOuterLinkCustomChecks = 0;
  size_t numBaseLinkParentChecks = 0;
  size_t numNestedModelLinkChecks = 0;
  size_t numParentModelLinkChecks = 0;
  size_t numBaseLinkChildChecks = 0;

  size_t currIter = 0;
  testSystem.OnPostUpdate(
    [&](const gazebo::UpdateInfo &, const gazebo::EntityComponentManager &_ecm)
    {
      currIter++;
      _ecm.Each<components::Link, components::Name>(
          [&](const ignition::gazebo::Entity &_entity,
          const components::Link *, const components::Name *_name)->bool
          {
            // ignore the link for the ground plane
            if (_name->Data() != "surface")
            {
              const double dt = 0.001;
              const double zExpected =
                0.5 * world->Gravity().Z() * pow(dt * currIter, 2);

              if (_name->Data() == "base_link")
              {
                // link "base_link" falls due to gravity, starting from rest
                EXPECT_NEAR(zExpected,
                    ignition::gazebo::worldPose(_entity, _ecm).Z(), 1e-2);
                numBaseLinkChecks++;
              }
              else if (_name->Data() == "link0_outer")
              {
                // link "link0_outer" is resting on the ground and does not
                // move, so it should always have a pose of (1 0 0 0 0 0)
                EXPECT_EQ(ignition::math::Pose3d(1, 0, 0, 0, 0, 0),
                    ignition::gazebo::worldPose(_entity, _ecm));
                numOuterLinkChecks++;
              }
              else if (_name->Data() == "base_link_custom")
              {
                // same as link "base_link"
                EXPECT_NEAR(zExpected,
                    ignition::gazebo::worldPose(_entity, _ecm).Z(), 1e-2);
                numBaseLinkCustomChecks++;
              }
              else if (_name->Data() == "link0_outer_custom")
              {
                // same as "link0_outer", but with an offset pose
                EXPECT_EQ(ignition::math::Pose3d(1, 2, 0, 0, 0, 0),
                    ignition::gazebo::worldPose(_entity, _ecm));
                numOuterLinkCustomChecks++;
              }
              else if (_name->Data() == "base_link_parent")
              {
                // same as link "base_link"
                EXPECT_NEAR(zExpected,
                    ignition::gazebo::worldPose(_entity, _ecm).Z(), 1e-2);
                numBaseLinkParentChecks++;
              }
              else if (_name->Data() == "nested_model_link")
              {
                // same as "link0_outer", but with an offset pose
                EXPECT_EQ(ignition::math::Pose3d(1, -2, 0, 0, 0, 0),
                    ignition::gazebo::worldPose(_entity, _ecm));
                numNestedModelLinkChecks++;
              }
              else if (_name->Data() == "parent_model_link")
              {
                // same as "link0_outer", but with an offset pose
                EXPECT_EQ(ignition::math::Pose3d(1, -4, 0, 0, 0, 0),
                    ignition::gazebo::worldPose(_entity, _ecm));
                numParentModelLinkChecks++;
              }
              else if (_name->Data() == "base_link_child")
              {
                // same as link "base_link"
                EXPECT_NEAR(zExpected,
                    ignition::gazebo::worldPose(_entity, _ecm).Z(), 1e-2);
                numBaseLinkChildChecks++;
              }
            }

            return true;
          });

      return true;
    });

  server.AddSystem(testSystem.systemPtr);
  const size_t iters = 500;
  server.Run(true, iters, false);

  EXPECT_EQ(iters, currIter);
  EXPECT_EQ(iters, numBaseLinkChecks);
  EXPECT_EQ(iters, numOuterLinkChecks);
  EXPECT_EQ(iters, numBaseLinkCustomChecks);
  EXPECT_EQ(iters, numOuterLinkCustomChecks);
  EXPECT_EQ(iters, numBaseLinkParentChecks);
  EXPECT_EQ(iters, numNestedModelLinkChecks);
  EXPECT_EQ(iters, numParentModelLinkChecks);
  EXPECT_EQ(iters, numBaseLinkChildChecks);
}