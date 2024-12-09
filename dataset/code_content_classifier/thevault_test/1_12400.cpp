TEST(ManipulatorIntersectRayConeTest, RayConeEditorScenarioTest)
    {
        auto rayOrigin = AZ::Vector3(0.0f, -0.808944702f, 0.0f);
        auto rayDir = AZ::Vector3(0.301363617f, 0.939044654f, 0.165454566f);
        float t = 0.0f;
        bool hit = AzToolsFramework::Picking::IntersectRayCone(
            rayOrigin, rayDir, AZ::Vector3(0.0f, 0.0f, 0.161788940f), AZ::Vector3(0.0f, 0.0f, -1.0f), 0.0453009047, 0.0113252262, t);
        EXPECT_FALSE(hit);
    }