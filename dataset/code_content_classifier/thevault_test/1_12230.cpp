void GenerateWireTubeMesh(
        const AZ::SplinePtr& spline, const SplineAttribute<float>& variableRadius,
        const float radius, const AZ::u32 capSegments, const AZ::u32 sides,
        AZStd::vector<AZ::Vector3>& vertexBufferOut)
    {
        const size_t segmentCount = spline->GetSegmentCount();
        if (segmentCount == 0)
        {
            // clear the buffer so we no longer draw anything
            vertexBufferOut.clear();
            return;
        }

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
        //   2 loops per segment
        const AZ::u32 segments = static_cast<AZ::u32>(segmentCount * spline->GetSegmentGranularity());
        const AZ::u32 totalEndSegments = capSegments * 2 * 2 * 2 * 2;
        const AZ::u32 totalSegments = segments * 2 * 2 * 2;
        const AZ::u32 totalLoops = 2 * sides * segments * 2;
        const bool hasEnds = capSegments > 0;
        const size_t numVerts = totalEndSegments + totalSegments + totalLoops;
        vertexBufferOut.resize(numVerts);

        AZ::Vector3* vertices = vertexBufferOut.data();

        // start cap
        auto address = spline->GetAddressByFraction(0.0f);
        AZ::Vector3 side = spline->GetNormal(address);
        AZ::Vector3 nextSide = spline->GetNormal(address);
        AZ::Vector3 previousDirection = spline->GetTangent(address);
        if (hasEnds)
        {
            vertices = CapsuleTubeUtil::GenerateWireCap(
                spline->GetPosition(address),
                -previousDirection,
                side,
                radius + variableRadius.GetElementInterpolated(address, Lerpf),
                capSegments,
                vertices);
        }

        // body
        const float stepDelta = 1.0f / static_cast<float>(spline->GetSegmentGranularity());
        auto nextAddress = address;
        const auto endIndex = address.m_segmentIndex + segmentCount;
        while (address.m_segmentIndex < endIndex)
        {
            address.m_segmentFraction = 0.f;
            nextAddress.m_segmentFraction = stepDelta;

            for (auto step = 0; step < spline->GetSegmentGranularity(); ++step)
            {
                const auto position = spline->GetPosition(address);
                const auto nextPosition = spline->GetPosition(nextAddress);
                const auto direction = spline->GetTangent(address);
                const auto nextDirection = spline->GetTangent(nextAddress);
                side = spline->GetNormal(address);
                nextSide = spline->GetNormal(nextAddress);
                const auto up = side.Cross(direction);
                const auto nextUp = nextSide.Cross(nextDirection);
                const auto finalRadius = radius + variableRadius.GetElementInterpolated(address, Lerpf);
                const auto nextFinalRadius = radius + variableRadius.GetElementInterpolated(nextAddress, Lerpf);

                // left line
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        position, direction, side, finalRadius, 0.0f),
                    vertices);
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        nextPosition, nextDirection, nextSide, nextFinalRadius, 0.0f),
                    vertices);
                // right line
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        position, -direction, side, finalRadius, AZ::Constants::Pi),
                    vertices);
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        nextPosition, -nextDirection, nextSide, nextFinalRadius, AZ::Constants::Pi),
                    vertices);
                // top line
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        position, direction, up, finalRadius, 0.0f),
                    vertices);
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        nextPosition, nextDirection, nextUp, nextFinalRadius, 0.0f),
                    vertices);
                // bottom line
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        position, -direction, up, finalRadius, AZ::Constants::Pi),
                    vertices);
                vertices = WriteVertex(
                    CapsuleTubeUtil::CalculatePositionOnSphere(
                        nextPosition, -nextDirection, nextUp, nextFinalRadius, AZ::Constants::Pi),
                    vertices);

                // loops along each segment
                vertices = CapsuleTubeUtil::GenerateWireLoop(
                    position, direction, side, sides, finalRadius, vertices);

                vertices = CapsuleTubeUtil::GenerateWireLoop(
                    nextPosition, nextDirection, nextSide, sides, nextFinalRadius, vertices);

                address.m_segmentFraction += stepDelta;
                nextAddress.m_segmentFraction += stepDelta;
                previousDirection = direction;
            }

            address.m_segmentIndex++;
            nextAddress.m_segmentIndex++;
        }

        if (hasEnds)
        {
            const auto endAddress = spline->GetAddressByFraction(1.0f);
            const auto endPosition = spline->GetPosition(endAddress);
            const auto endDirection = spline->GetTangent(endAddress);
            const auto endRadius =
                radius + variableRadius.GetElementInterpolated(endAddress, Lerpf);

            // end cap
            CapsuleTubeUtil::GenerateWireCap(
                endPosition, endDirection,
                nextSide, endRadius, capSegments,
                vertices);
        }
    }