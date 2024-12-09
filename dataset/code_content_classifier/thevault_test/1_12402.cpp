TEST(ManipulatorIntersectRayConeTest, RayIntersectsConeSide)
    {
        auto rayOrigin = AZ::Vector3::CreateZero();
        auto rayDir = AZ::Vector3::CreateAxisY();
        float t = 0.0f;
        bool hit = AzToolsFramework::Picking::IntersectRayCone(
            rayOrigin, rayDir, AZ::Vector3(0.0f, 10.0f, 5.0f), AZ::Vector3::CreateAxisZ(-1.0f), 10.0f, 5.0f, t);
        EXPECT_TRUE(hit);
        EXPECT_THAT(t, ::testing::FloatNear(7.5f, 0.0001f));
    }