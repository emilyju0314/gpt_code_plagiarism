TEST(MATH_IntersectRayConeTestEditor, DISABLED_RayConeEditorScenarioTest)
    {
        auto rayOrigin = Vector3(0.0f, -0.808944702f, 0.0f);
        auto rayDir = Vector3(0.301363617f, 0.939044654f, 0.165454566f);
        float t1 = 0.0f;
        float t2 = 0.0f;
        int hits = Intersect::IntersectRayCone(
            rayOrigin, rayDir, AZ::Vector3(0.0f, 0.0f, 0.161788940f), AZ::Vector3(0.0f, 0.0f, -1.0f), 0.0453009047, 0.0113252262, t1, t2);
        EXPECT_EQ(hits, 0);
    }