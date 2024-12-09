static void GenerateSolidCapsuleMesh(
        const float radius, const float height, const AZ::u32 sides, const AZ::u32 capSegments,
        AZStd::vector<AZ::Vector3>& vertexBufferOut, AZStd::vector<AZ::u32>& indexBufferOut)
    {
        const AZ::u32 segments = 1;
        const AZ::u32 totalSegments = segments + capSegments * 2;

        const size_t numVerts = sides * (totalSegments + 1) + 2;
        const size_t numTriangles = (sides * totalSegments) * 2 + (sides * 2);

        vertexBufferOut.resize(numVerts);
        indexBufferOut.resize(numTriangles * 3);

        GenerateSolidCapsuleMeshVertices(
            radius, height, sides, capSegments, &vertexBufferOut[0]);

        CapsuleTubeUtil::GenerateSolidMeshIndices(
            sides, segments, capSegments, &indexBufferOut[0]);
    }