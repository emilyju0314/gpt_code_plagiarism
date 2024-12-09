void GenerateSolidTubeMesh(
        const AZ::SplinePtr& spline, const SplineAttribute<float>& variableRadius,
        const float radius, const AZ::u32 capSegments, const AZ::u32 sides,
        AZStd::vector<AZ::Vector3>& vertexBufferOut,
        AZStd::vector<AZ::u32>& indexBufferOut)
    {
        const size_t segmentCount = spline->GetSegmentCount();
        if (segmentCount == 0)
        {
            // clear the buffers so we no longer draw anything
            vertexBufferOut.clear();
            indexBufferOut.clear();
            return;
        }

        const AZ::u32 segments = static_cast<AZ::u32>(segmentCount * spline->GetSegmentGranularity() + segmentCount - 1);
        const AZ::u32 totalSegments = segments + capSegments * 2;
        const AZ::u32 capSegmentTipVerts = capSegments > 0 ? 2 : 0;
        const size_t numVerts = sides * (totalSegments + 1) + capSegmentTipVerts;
        const size_t numTriangles = (sides * totalSegments) * 2 + (sides * capSegmentTipVerts);

        vertexBufferOut.resize(numVerts);
        indexBufferOut.resize(numTriangles * 3);

        GenerateSolidTubeMeshVertices(
            spline, variableRadius, radius,
            sides, capSegments, &vertexBufferOut[0]);

        CapsuleTubeUtil::GenerateSolidMeshIndices(
            sides, segments, capSegments, &indexBufferOut[0]);
    }