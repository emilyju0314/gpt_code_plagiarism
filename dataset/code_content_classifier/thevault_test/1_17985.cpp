TEST_F(PhysicsSystemFixture, NestedModelIndividualCanonicalLinks)
{
  ignition::gazebo::ServerConfig serverConfig;

  const auto sdfFile = std::string(PROJECT_SOURCE_PATH) +
    "/test/worlds/nested_model_canonical_link.sdf";

  sdf::Root root;
  root.Load(sdfFile);
  const sdf::World *world = root.WorldByIndex(0);
  ASSERT_TRUE(nullptr != world);

  serverConfig.SetSdfFile(sdfFile);

  gazebo::Server server(serverConfig);

  server.SetUpdatePeriod(1us);

  // Create a system that records the poses of the links after physics
  test::Relay testSystem;

  // Store a pointer to the ECM used in testSystem so that it can be used to
  // help verify poses at the end of this test
  const gazebo::EntityComponentManager *ecm;

  std::unordered_map<std::string, ignition::math::Pose3d> postUpModelPoses;
  testSystem.OnPostUpdate(
    [&postUpModelPoses, &ecm](const gazebo::UpdateInfo &,
    const gazebo::EntityComponentManager &_ecm)
    {
      ecm = &_ecm;

      _ecm.Each<components::Model, components::Name, components::Pose>(
        [&](const ignition::gazebo::Entity &, const components::Model *,
        const components::Name *_name, const components::Pose *_pose)->bool
        {
          // store model pose
          postUpModelPoses[_name->Data()] = _pose->Data();
          return true;
        });

      return true;
    });

  server.AddSystem(testSystem.systemPtr);
  const size_t iters = 500;
  server.Run(true, iters, false);
  EXPECT_EQ(6u, postUpModelPoses.size());

  auto modelIt = postUpModelPoses.find("model_00");
  ASSERT_NE(postUpModelPoses.end(), modelIt);

  // link_00 is resting on the ground_box, so it remains stationary. And since
  // it is the canonical link of the parent model, model_00, the model frame
  // should also remain stationary.
  EXPECT_EQ(math::Pose3d::Zero, modelIt->second);

  // link_01 is floating, so it should fall due to gravity. And since it is the
  // canonical link of the nested model, model_01, the model frame should also
  // fall. If the model pose is not updated according to this canonical link,
  // the test would fail.
  const double dt = 0.001;
  const double zExpected = 0.5 * world->Gravity().Z() * pow(dt * iters, 2);
  modelIt = postUpModelPoses.find("model_01");
  ASSERT_NE(postUpModelPoses.end(), modelIt);
  EXPECT_NEAR(zExpected, modelIt->second.Z(), 1e-2);

  // model_10, model_11 and model_12 share the same canonical link (link_12),
  // which is a floating link. So, link_12 should fall due to gravity, which
  // also means that the frames for model_10, model_11 and model_12 should fall
  auto model10It = postUpModelPoses.find("model_10");
  ASSERT_NE(postUpModelPoses.end(), model10It);
  EXPECT_NEAR(zExpected, model10It->second.Z(), 1e-2);
  auto model11It = postUpModelPoses.find("model_11");
  ASSERT_NE(postUpModelPoses.end(), model11It);
  auto model12It = postUpModelPoses.find("model_12");
  ASSERT_NE(postUpModelPoses.end(), model12It);
  // (since model_11 and model_12 are nested, their poses are computed w.r.t.
  // model_10)
  EXPECT_DOUBLE_EQ(0.0, model11It->second.Z());
  EXPECT_DOUBLE_EQ(0.0, model12It->second.Z());
  // check the world pose of model_11 and model_12 to make sure the z components
  // of these world poses match zExpected
  ASSERT_NE(nullptr, ecm);
  const auto model11Entity =
    ecm->EntityByComponents(components::Name(model11It->first));
  ASSERT_NE(kNullEntity, model11Entity);
  const auto model11WorldPose = gazebo::worldPose(model11Entity, *ecm);
  EXPECT_NEAR(zExpected, model11WorldPose.Z(), 1e-2);
  const auto model12Entity =
    ecm->EntityByComponents(components::Name(model12It->first));
  ASSERT_NE(kNullEntity, model12Entity);
  const auto model12WorldPose = gazebo::worldPose(model12Entity, *ecm);
  EXPECT_NEAR(zExpected, model12WorldPose.Z(), 1e-2);
  EXPECT_DOUBLE_EQ(model11WorldPose.Z(), model12WorldPose.Z());
  // zExpected is also the z component of the world pose for model_10
  EXPECT_DOUBLE_EQ(model11WorldPose.Z(), model10It->second.Z());
  EXPECT_DOUBLE_EQ(model12WorldPose.Z(), model10It->second.Z());
}