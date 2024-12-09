static void GenerateWireCapsuleMesh(
        const float radius, const float height, const AZ::u32 sides,
        const AZ::u32 capSegments, AZStd::vector<AZ::Vector3>& lineBufferOut)
    {
        // notes on vert buffer size
        // total end segments
        // 2 verts for each segment
        //  2 * capSegments for one full half arc
        //   2 arcs per end
        //    2 ends
        // total segments
        // 2 verts for each segment
        //  2 lines - top and bottom
        //   2 lines - left and right
        // total loops
        // 2 verts for each segment
        //  loops == sides
        //   1 extra segment needed for last loop
        //    1 extra segment needed for centre loop
        const AZ::u32 segments = 1;
        const AZ::u32 totalEndSegments = capSegments * 2 * 2 * 2 * 2;
        const AZ::u32 totalSegments = segments * 2 * 2 * 2;
        const AZ::u32 totalLoops = sides * 2 * (segments + 2);

        const size_t numVerts = totalEndSegments + totalSegments + totalLoops;
        lineBufferOut.resize(numVerts);

        const float middleHeight = AZ::GetMax(height - radius * 2.0f, 0.0f);
        const float halfMiddleHeight = middleHeight * 0.5f;

        // start cap
        AZ::Vector3* vertices = CapsuleTubeUtil::GenerateWireCap(
            AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
            -AZ::Vector3::CreateAxisZ(),
            AZ::Vector3::CreateAxisX(),
            radius,
            capSegments,
            &lineBufferOut[0]);

        // first loop
        vertices = CapsuleTubeUtil::GenerateWireLoop(
            AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
            AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), sides, radius, vertices);

        // centre loop
        vertices = CapsuleTubeUtil::GenerateWireLoop(
            AZ::Vector3::CreateZero(),
            AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), sides, radius, vertices);

        // body
        // left line
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
                AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), radius, 0.0f),
                vertices);
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(halfMiddleHeight),
                AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), radius, 0.0f),
            vertices);
        // right line
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
                -AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), radius, AZ::Constants::Pi),
            vertices);
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(halfMiddleHeight),
                -AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisX(), radius, AZ::Constants::Pi),
            vertices);
        // top line
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
                AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisY(), radius, 0.0f),
            vertices);
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(halfMiddleHeight),
                AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisY(), radius, 0.0f),
            vertices);
        // bottom line
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(-halfMiddleHeight),
                -AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisY(), radius, AZ::Constants::Pi),
            vertices);
        vertices = WriteVertex(
            CapsuleTubeUtil::CalculatePositionOnSphere(
                AZ::Vector3::CreateAxisZ(halfMiddleHeight),
                -AZ::Vector3::CreateAxisZ(), AZ::Vector3::CreateAxisY(), radius, AZ::Constants::Pi),
            vertices);

        // final loop
        vertices = CapsuleTubeUtil::GenerateWireLoop(
            AZ::Vector3::CreateAxisZ(halfMiddleHeight), AZ::Vector3::CreateAxisZ(),
            AZ::Vector3::CreateAxisX(), sides, radius, vertices);

        // end cap
        CapsuleTubeUtil::GenerateWireCap(
            AZ::Vector3::CreateAxisZ(halfMiddleHeight),
            AZ::Vector3::CreateAxisZ(),
            AZ::Vector3::CreateAxisX(), radius,
            capSegments, vertices);
    }