void TestCalculateSphereAreaInClipSpaceWithSphereFillingYDimension(float fovY, float aspectRatio, float sphereRadius)
    {
        using namespace AZ;
        using namespace RPI;

        ViewPtr view = CreateView(fovY, aspectRatio);

        // Sphere distance from camera is radius/sin(fov/2)
        // At this distance the horizon of the sphere should be touching the edge of the viewport vertically
        // So the visible area of the sphere would be a circle the diameter of the viewport height
        // So the coverage percentage would be 0.5f * 0.5f * pi (radius will be half screen height)
        float sinHalfFovY = sin(fovY * 0.5f);
        float dist = sphereRadius / sinHalfFovY;
        AZ::Vector3 center(0.0f, 0.0f, -dist);

        float coverage = view->CalculateSphereAreaInClipSpace(center, sphereRadius);

        const float expectedCoverage = 0.5f * 0.5f * AZ::Constants::Pi;
        const float allowedEpsilon = 0.001f;
        float diff = fabsf(coverage - expectedCoverage);

        EXPECT_TRUE(diff < allowedEpsilon);
    }