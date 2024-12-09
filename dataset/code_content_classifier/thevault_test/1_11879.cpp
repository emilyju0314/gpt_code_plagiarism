static void GenerateSolidCapsuleMeshVertices(
        const float radius, const float height,
        const AZ::u32 sides, const AZ::u32 capSegments,
        AZ::Vector3* vertices)
    {
        const float middleHeight = AZ::GetMax(height - radius * 2.0f, 0.0f);
        const float halfMiddleHeight = middleHeight * 0.5f;

        vertices = CapsuleTubeUtil::GenerateSolidStartCap(
            AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
            AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(),
            radius, sides, capSegments, vertices);

        AZStd::array<float, 2> endPositions = { { -halfMiddleHeight, halfMiddleHeight } };
        for (size_t i = 0; i < endPositions.size(); ++i)
        {
            const AZ::Vector3 position = AZ::Vector3::CreateAxisZ(endPositions[i]);
            vertices = CapsuleTubeUtil::GenerateSegmentVertices(
                position, AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(),
                radius, sides, vertices);
        }

        CapsuleTubeUtil::GenerateSolidEndCap(
            AZ::Vector3::CreateAxisZ(halfMiddleHeight),
            AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(),
            radius, sides, capSegments, vertices);
    }