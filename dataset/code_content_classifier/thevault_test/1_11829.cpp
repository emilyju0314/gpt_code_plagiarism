void TestCalculateSphereAreaInClipSpaceVsProjectedRadius(float fovY, float aspectRatio, const AZ::Vector3& sphereCenter, float sphereRadius)
    {
        using namespace AZ;
        using namespace RPI;

        ViewPtr view = CreateView(fovY, aspectRatio);

        float coverage = view->CalculateSphereAreaInClipSpace(sphereCenter, sphereRadius);

        // This computes the projected radius of a sphere using the calculation described here:
        // https://stackoverflow.com/questions/21648630/radius-of-projected-sphere-in-screen-space
        float radiusSq = sphereRadius * sphereRadius;
        AZ::Vector3 distanceVector = sphereCenter;
        float distanceSq = distanceVector.GetLengthSq();
        float tanHalfFovY = tan(fovY * 0.5f);
        float cotHalfFovY = 1.0f / tanHalfFovY; // this is actually just the same as view->GetViewToClipMatrix().GetElement(1, 1)
        float sqrtDistanceSqMinusRadiusSq = sqrt(distanceSq - radiusSq);
        float projectedRadius = cotHalfFovY * sphereRadius / sqrtDistanceSqMinusRadiusSq;

        // projectedRadius is a percentage of half of the view height. To get as percentage of view height we halve it
        float prAsAPercentOfViewHeight = projectedRadius * 0.5f;

        float prSq = prAsAPercentOfViewHeight * prAsAPercentOfViewHeight;
        float expectedArea = prSq * AZ::Constants::Pi;

        const float allowedEpsilon = 0.0001f;
        float diff = fabsf(coverage - expectedArea);

        EXPECT_TRUE(diff < allowedEpsilon);
    }