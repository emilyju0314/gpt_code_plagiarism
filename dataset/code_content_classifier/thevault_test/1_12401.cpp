TEST(ManipulatorIntersectRayConeTest, RayIntersectsConeBase)
    {
        auto rayOrigin = AZ::Vector3::CreateZero();
        auto rayDir = AZ::Vector3::CreateAxisY();
        float t = 0.0f;
        bool hit = AzToolsFramework::Picking::IntersectRayCone(
            rayOrigin, rayDir, AZ::Vector3::CreateAxisY(10.0f), AZ::Vector3::CreateAxisY(-1.0f), 5.0f, 1.0f, t);
        EXPECT_TRUE(hit);
        EXPECT_THAT(t, ::testing::FloatNear(5.0f, 0.0001f));
    }