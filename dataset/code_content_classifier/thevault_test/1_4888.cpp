void CollisionDetectionSystem::computeConvexVsConcaveMiddlePhase(OverlappingPairs::ConcaveOverlappingPair& overlappingPair, MemoryAllocator& allocator, NarrowPhaseInput& narrowPhaseInput, bool reportContacts) {

    RP3D_PROFILE("CollisionDetectionSystem::computeConvexVsConcaveMiddlePhase()", mProfiler);

    const Entity collider1 = overlappingPair.collider1;
    const Entity collider2 = overlappingPair.collider2;

    const uint32 collider1Index = mCollidersComponents.getEntityIndex(collider1);
    const uint32 collider2Index = mCollidersComponents.getEntityIndex(collider2);

    Transform& shape1LocalToWorldTransform = mCollidersComponents.mLocalToWorldTransforms[collider1Index];
    Transform& shape2LocalToWorldTransform = mCollidersComponents.mLocalToWorldTransforms[collider2Index];

    Transform convexToConcaveTransform;

    // Collision shape 1 is convex, collision shape 2 is concave
    ConvexShape* convexShape;
    ConcaveShape* concaveShape;
    if (overlappingPair.isShape1Convex) {
        convexShape = static_cast<ConvexShape*>(mCollidersComponents.mCollisionShapes[collider1Index]);
        concaveShape = static_cast<ConcaveShape*>(mCollidersComponents.mCollisionShapes[collider2Index]);
        convexToConcaveTransform = shape2LocalToWorldTransform.getInverse() * shape1LocalToWorldTransform;
    }
    else {  // Collision shape 2 is convex, collision shape 1 is concave
        convexShape = static_cast<ConvexShape*>(mCollidersComponents.mCollisionShapes[collider2Index]);
        concaveShape = static_cast<ConcaveShape*>(mCollidersComponents.mCollisionShapes[collider1Index]);
        convexToConcaveTransform = shape1LocalToWorldTransform.getInverse() * shape2LocalToWorldTransform;
    }

    assert(convexShape->isConvex());
    assert(!concaveShape->isConvex());
    assert(overlappingPair.narrowPhaseAlgorithmType != NarrowPhaseAlgorithmType::None);

    // Compute the convex shape AABB in the local-space of the concave shape
    AABB aabb;
    convexShape->computeAABB(aabb, convexToConcaveTransform);

    // Compute the concave shape triangles that are overlapping with the convex mesh AABB
    Array<Vector3> triangleVertices(allocator, 64);
    Array<Vector3> triangleVerticesNormals(allocator, 64);
    Array<uint> shapeIds(allocator, 64);
    concaveShape->computeOverlappingTriangles(aabb, triangleVertices, triangleVerticesNormals, shapeIds, allocator);

    assert(triangleVertices.size() == triangleVerticesNormals.size());
    assert(shapeIds.size() == triangleVertices.size() / 3);
    assert(triangleVertices.size() % 3 == 0);
    assert(triangleVerticesNormals.size() % 3 == 0);

    const bool isCollider1Trigger = mCollidersComponents.mIsTrigger[collider1Index];
    const bool isCollider2Trigger = mCollidersComponents.mIsTrigger[collider2Index];
    reportContacts = reportContacts && !isCollider1Trigger && !isCollider2Trigger;

    CollisionShape* shape1;
    CollisionShape* shape2;

    if (overlappingPair.isShape1Convex) {
        shape1 = convexShape;
    }
    else {
        shape2 = convexShape;
    }

    // For each overlapping triangle
    const uint32 nbShapeIds = static_cast<uint32>(shapeIds.size());
    for (uint32 i=0; i < nbShapeIds; i++) {

        // Create a triangle collision shape (the allocated memory for the TriangleShape will be released in the
        // destructor of the corresponding NarrowPhaseInfo.
        TriangleShape* triangleShape = new (allocator.allocate(sizeof(TriangleShape)))
                                       TriangleShape(&(triangleVertices[i * 3]), &(triangleVerticesNormals[i * 3]), shapeIds[i], mTriangleHalfEdgeStructure, allocator);

    #ifdef IS_RP3D_PROFILING_ENABLED


        // Set the profiler to the triangle shape
        triangleShape->setProfiler(mProfiler);

    #endif

        if (overlappingPair.isShape1Convex) {
            shape2 = triangleShape;
        }
        else {
            shape1 = triangleShape;
        }

        // Add a collision info for the two collision shapes into the overlapping pair (if not present yet)
        LastFrameCollisionInfo* lastFrameInfo = overlappingPair.addLastFrameInfoIfNecessary(shape1->getId(), shape2->getId());

        // Create a narrow phase info for the narrow-phase collision detection
        narrowPhaseInput.addNarrowPhaseTest(overlappingPair.pairID, collider1, collider2, shape1, shape2,
                                            shape1LocalToWorldTransform, shape2LocalToWorldTransform,
                                            overlappingPair.narrowPhaseAlgorithmType, reportContacts, lastFrameInfo, allocator);
    }
}