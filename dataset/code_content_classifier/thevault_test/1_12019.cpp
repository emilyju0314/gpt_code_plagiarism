static void GenerateSolidPolygonPrismMesh(
        const AZStd::vector<AZ::Vector2>& vertices,
        const float height,
        const AZ::Vector3& nonUniformScale,
        AZStd::vector<AZ::Vector3>& meshTriangles)
    {
        // must have at least one triangle
        if (vertices.size() < 3)
        {
            meshTriangles.clear();
            return;
        }

        // deal with the possibility that the scaled height is negative
        const float scaledHeight = height * nonUniformScale.GetZ();
        const float top = AZ::GetMax(0.0f, scaledHeight);
        const float bottom = AZ::GetMin(0.0f, scaledHeight);
        const AZ::Vector3 topVector = AZ::Vector3::CreateAxisZ(top);
        const AZ::Vector3 bottomVector = AZ::Vector3::CreateAxisZ(bottom);

        // generate triangles for one face of polygon prism
        const AZStd::vector<AZ::Vector3> faceTriangles = GenerateTriangles(vertices);

        const size_t halfTriangleCount = faceTriangles.size();
        const size_t fullTriangleCount = faceTriangles.size() * 2;
        const size_t wallTriangleCount = vertices.size() * 2 * 3;

        // allocate space for both faces (polygons) and walls
        meshTriangles.resize_no_construct(fullTriangleCount + wallTriangleCount);

        // copy vertices into triangle list
        const typename AZStd::vector<AZ::Vector3>::iterator midFace = meshTriangles.begin() + halfTriangleCount;

        AZStd::transform(faceTriangles.cbegin(), faceTriangles.cend(), meshTriangles.begin(),
            [&nonUniformScale, &topVector](AZ::Vector3 vertex) { return nonUniformScale * vertex + topVector; });
        // due to winding order, reverse copy triangles for other face/polygon
        AZStd::transform(faceTriangles.crbegin(), faceTriangles.crend(), midFace,
            [&nonUniformScale, &bottomVector](AZ::Vector3 vertex) { return nonUniformScale * vertex + bottomVector; });

        // end of face/polygon vertices is start of side/wall vertices
        const typename AZStd::vector<AZ::Vector3>::iterator endFaceIt = meshTriangles.begin() + fullTriangleCount;
        typename AZStd::vector<AZ::Vector3>::iterator sideIt = endFaceIt;

        // build quad triangles from vertices util
        const auto quadTriangles =
            [](const AZ::Vector3& a, const AZ::Vector3& b, const AZ::Vector3& c, const AZ::Vector3& d, typename AZStd::vector<AZ::Vector3>::iterator& tri)
        {
            *tri = a; ++tri;
            *tri = b; ++tri;
            *tri = c; ++tri;
            *tri = c; ++tri;
            *tri = b; ++tri;
            *tri = d; ++tri;
        };

        // generate walls
        const bool clockwise = ClockwiseOrder(vertices);
        const size_t vertexCount = vertices.size();
        for (size_t i = 0; i < vertexCount; ++i)
        {
            // local vertex positions
            const AZ::Vector3 currentPoint = nonUniformScale * AZ::Vector2ToVector3(vertices[i]);
            const AZ::Vector3 nextPoint = nonUniformScale * AZ::Vector2ToVector3(vertices[(i + 1) % vertexCount]);
            const AZ::Vector3 p1 = currentPoint + bottomVector;
            const AZ::Vector3 p2 = nextPoint + bottomVector;
            const AZ::Vector3 p3 = currentPoint + topVector;
            const AZ::Vector3 p4 = nextPoint + topVector;

            // generate triangles for wall quad
            if (clockwise)
            {
                quadTriangles(p1, p3, p2, p4, sideIt);
            }
            else
            {
                quadTriangles(p1, p2, p3, p4, sideIt);
            }
        }
    }