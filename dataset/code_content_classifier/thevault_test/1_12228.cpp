static void GenerateSolidTubeMeshVertices(
        const AZ::SplinePtr& spline, const SplineAttribute<float>& variableRadius,
        const float radius, const AZ::u32 sides, const AZ::u32 capSegments, AZ::Vector3* vertices)
    {
        // start cap
        auto address = spline->GetAddressByFraction(0.0f);
        AZ::Vector3 normal = spline->GetNormal(address);
        AZ::Vector3 previousTangent = spline->GetTangent(address);
        if (capSegments > 0)
        {
            vertices = CapsuleTubeUtil::GenerateSolidStartCap(
                spline->GetPosition(address),
                previousTangent,
                normal,
                radius + variableRadius.GetElementInterpolated(address, Lerpf),
                sides, capSegments, vertices);
        }

        // middle segments (body)
        const float stepDelta = 1.0f / static_cast<float>(spline->GetSegmentGranularity());
        const auto endIndex = address.m_segmentIndex + spline->GetSegmentCount();

        while (address.m_segmentIndex < endIndex)
        {
            for (auto step = 0; step <= spline->GetSegmentGranularity(); ++step)
            {
                const AZ::Vector3 currentTangent = spline->GetTangent(address);
                normal = CalculateNormal(normal, previousTangent, currentTangent);

                vertices = CapsuleTubeUtil::GenerateSegmentVertices(
                    spline->GetPosition(address),
                    currentTangent,
                    normal,
                    radius + variableRadius.GetElementInterpolated(address, Lerpf),
                    sides, vertices);

                address.m_segmentFraction += stepDelta;
                previousTangent = currentTangent;
            }
            address.m_segmentIndex++;
            address.m_segmentFraction = 0.f;
        }

        // end cap
        if (capSegments > 0)
        {
            const auto endAddress = spline->GetAddressByFraction(1.0f);
            CapsuleTubeUtil::GenerateSolidEndCap(
                spline->GetPosition(endAddress),
                spline->GetTangent(endAddress),
                normal,
                radius + variableRadius.GetElementInterpolated(endAddress, Lerpf),
                sides, capSegments, vertices);
        }
    }