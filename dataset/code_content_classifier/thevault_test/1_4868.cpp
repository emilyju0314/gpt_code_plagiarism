bool HeightFieldShape::raycastTriangle(const Ray& ray, const Vector3& p1, const Vector3& p2, const Vector3& p3, uint32 shapeId,
                                       Collider* collider, RaycastInfo& raycastInfo, decimal& smallestHitFraction, MemoryAllocator& allocator) const {

   // Generate the first triangle for the current grid rectangle
   Vector3 triangleVertices[3] = {p1, p2, p3};

    // Create a triangle collision shape
    TriangleShape triangleShape(triangleVertices, shapeId, mTriangleHalfEdgeStructure, allocator);
    triangleShape.setRaycastTestType(getRaycastTestType());

#ifdef IS_RP3D_PROFILING_ENABLED


    // Set the profiler to the triangle shape
    triangleShape.setProfiler(mProfiler);

#endif

    // Ray casting test against the collision shape
    RaycastInfo triangleRaycastInfo;
    bool isTriangleHit = triangleShape.raycast(ray, triangleRaycastInfo, collider, allocator);

    // If the ray hit the collision shape
    if (isTriangleHit && triangleRaycastInfo.hitFraction <= smallestHitFraction) {

        assert(triangleRaycastInfo.hitFraction >= decimal(0.0));

        raycastInfo.body = triangleRaycastInfo.body;
        raycastInfo.collider = triangleRaycastInfo.collider;
        raycastInfo.hitFraction = triangleRaycastInfo.hitFraction;
        raycastInfo.worldPoint = triangleRaycastInfo.worldPoint;
        raycastInfo.worldNormal = triangleRaycastInfo.worldNormal;
        raycastInfo.meshSubpart = -1;
        raycastInfo.triangleIndex = -1;

        smallestHitFraction = triangleRaycastInfo.hitFraction;

        return true;
    }

    return false;
}