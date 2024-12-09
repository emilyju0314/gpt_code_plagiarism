void CollisionDetectionSystem::computeMiddlePhase(NarrowPhaseInput& narrowPhaseInput, bool needToReportContacts) {

    RP3D_PROFILE("CollisionDetectionSystem::computeMiddlePhase()", mProfiler);

    // Reserve memory for the narrow-phase input using cached capacity from previous frame
    narrowPhaseInput.reserveMemory();

    // Remove the obsolete last frame collision infos and mark all the others as obsolete
    mOverlappingPairs.clearObsoleteLastFrameCollisionInfos();

    // For each possible convex vs convex pair of bodies
    const uint64 nbConvexVsConvexPairs = mOverlappingPairs.mConvexPairs.size();
    for (uint64 i=0; i < nbConvexVsConvexPairs; i++) {

        OverlappingPairs::ConvexOverlappingPair& overlappingPair = mOverlappingPairs.mConvexPairs[i];

        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider1) != -1);
        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider2) != -1);
        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider1) != mCollidersComponents.getBroadPhaseId(overlappingPair.collider2));


        const Entity collider1Entity = overlappingPair.collider1;
        const Entity collider2Entity = overlappingPair.collider2;

        const uint32 collider1Index = mCollidersComponents.getEntityIndex(collider1Entity);
        const uint32 collider2Index = mCollidersComponents.getEntityIndex(collider2Entity);

        CollisionShape* collisionShape1 = mCollidersComponents.mCollisionShapes[collider1Index];
        CollisionShape* collisionShape2 = mCollidersComponents.mCollisionShapes[collider2Index];

        NarrowPhaseAlgorithmType algorithmType = overlappingPair.narrowPhaseAlgorithmType;

        const bool isCollider1Trigger = mCollidersComponents.mIsTrigger[collider1Index];
        const bool isCollider2Trigger = mCollidersComponents.mIsTrigger[collider2Index];
        const bool reportContacts = needToReportContacts && !isCollider1Trigger && !isCollider2Trigger;

        // No middle-phase is necessary, simply create a narrow phase info
        // for the narrow-phase collision detection
        narrowPhaseInput.addNarrowPhaseTest(overlappingPair.pairID, collider1Entity, collider2Entity, collisionShape1, collisionShape2,
                                            mCollidersComponents.mLocalToWorldTransforms[collider1Index],
                                            mCollidersComponents.mLocalToWorldTransforms[collider2Index],
                                            algorithmType, reportContacts, &overlappingPair.lastFrameCollisionInfo,
                                            mMemoryManager.getSingleFrameAllocator());

        overlappingPair.collidingInCurrentFrame = false;
    }

    // For each possible convex vs concave pair of bodies
    const uint64 nbConcavePairs = mOverlappingPairs.mConcavePairs.size();
    for (uint64 i=0; i < nbConcavePairs; i++) {

        OverlappingPairs::ConcaveOverlappingPair& overlappingPair = mOverlappingPairs.mConcavePairs[i];

        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider1) != -1);
        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider2) != -1);
        assert(mCollidersComponents.getBroadPhaseId(overlappingPair.collider1) != mCollidersComponents.getBroadPhaseId(overlappingPair.collider2));

        computeConvexVsConcaveMiddlePhase(overlappingPair, mMemoryManager.getSingleFrameAllocator(), narrowPhaseInput, needToReportContacts);

        overlappingPair.collidingInCurrentFrame = false;
    }
}