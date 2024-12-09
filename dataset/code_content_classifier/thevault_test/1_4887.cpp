void CollisionDetectionSystem::computeMiddlePhaseCollisionSnapshot(Array<uint64>& convexPairs, Array<uint64>& concavePairs,
                                                                   NarrowPhaseInput& narrowPhaseInput, bool reportContacts) {

    RP3D_PROFILE("CollisionDetectionSystem::computeMiddlePhase()", mProfiler);

    // Reserve memory for the narrow-phase input using cached capacity from previous frame
    narrowPhaseInput.reserveMemory();

    // Remove the obsolete last frame collision infos and mark all the others as obsolete
    mOverlappingPairs.clearObsoleteLastFrameCollisionInfos();

    // For each possible convex vs convex pair of bodies
    const uint64 nbConvexPairs = convexPairs.size();
    for (uint64 p=0; p < nbConvexPairs; p++) {

        const uint64 pairId = convexPairs[p];

        const uint64 pairIndex = mOverlappingPairs.mMapConvexPairIdToPairIndex[pairId];
        assert(pairIndex < mOverlappingPairs.mConvexPairs.size());

        const Entity collider1Entity = mOverlappingPairs.mConvexPairs[pairIndex].collider1;
        const Entity collider2Entity = mOverlappingPairs.mConvexPairs[pairIndex].collider2;

        const uint32 collider1Index = mCollidersComponents.getEntityIndex(collider1Entity);
        const uint32 collider2Index = mCollidersComponents.getEntityIndex(collider2Entity);

        assert(mCollidersComponents.getBroadPhaseId(collider1Entity) != -1);
        assert(mCollidersComponents.getBroadPhaseId(collider2Entity) != -1);
        assert(mCollidersComponents.getBroadPhaseId(collider1Entity) != mCollidersComponents.getBroadPhaseId(collider2Entity));

        CollisionShape* collisionShape1 = mCollidersComponents.mCollisionShapes[collider1Index];
        CollisionShape* collisionShape2 = mCollidersComponents.mCollisionShapes[collider2Index];

        NarrowPhaseAlgorithmType algorithmType = mOverlappingPairs.mConvexPairs[pairIndex].narrowPhaseAlgorithmType;

        // No middle-phase is necessary, simply create a narrow phase info
        // for the narrow-phase collision detection
        narrowPhaseInput.addNarrowPhaseTest(pairId, collider1Entity, collider2Entity, collisionShape1, collisionShape2,
                                                  mCollidersComponents.mLocalToWorldTransforms[collider1Index],
                                                  mCollidersComponents.mLocalToWorldTransforms[collider2Index],
                                                  algorithmType, reportContacts, &mOverlappingPairs.mConvexPairs[pairIndex].lastFrameCollisionInfo, mMemoryManager.getSingleFrameAllocator());

    }

    // For each possible convex vs concave pair of bodies
    const uint32 nbConcavePairs = static_cast<uint32>(concavePairs.size());
    for (uint32 p=0; p < nbConcavePairs; p++) {

        const uint64 pairId = concavePairs[p];
        const uint64 pairIndex = mOverlappingPairs.mMapConcavePairIdToPairIndex[pairId];

        assert(mCollidersComponents.getBroadPhaseId(mOverlappingPairs.mConcavePairs[pairIndex].collider1) != -1);
        assert(mCollidersComponents.getBroadPhaseId(mOverlappingPairs.mConcavePairs[pairIndex].collider2) != -1);
        assert(mCollidersComponents.getBroadPhaseId(mOverlappingPairs.mConcavePairs[pairIndex].collider1) != mCollidersComponents.getBroadPhaseId(mOverlappingPairs.mConcavePairs[pairIndex].collider2));

        computeConvexVsConcaveMiddlePhase(mOverlappingPairs.mConcavePairs[pairIndex], mMemoryManager.getSingleFrameAllocator(), narrowPhaseInput, reportContacts);
    }
}