void CollisionDetectionSystem::processAllPotentialContacts(NarrowPhaseInput& narrowPhaseInput, bool updateLastFrameInfo,
                                                     Array<ContactPointInfo>& potentialContactPoints,
                                                     Array<ContactManifoldInfo>& potentialContactManifolds,
                                                     Array<ContactPair>* contactPairs) {

    assert(contactPairs->size() == 0);

    Map<uint64, uint> mapPairIdToContactPairIndex(mMemoryManager.getHeapAllocator(), mPreviousMapPairIdToContactPairIndex.size());

    // get the narrow-phase batches to test for collision
    NarrowPhaseInfoBatch& sphereVsSphereBatch = narrowPhaseInput.getSphereVsSphereBatch();
    NarrowPhaseInfoBatch& sphereVsCapsuleBatch = narrowPhaseInput.getSphereVsCapsuleBatch();
    NarrowPhaseInfoBatch& capsuleVsCapsuleBatch = narrowPhaseInput.getCapsuleVsCapsuleBatch();
    NarrowPhaseInfoBatch& sphereVsConvexPolyhedronBatch = narrowPhaseInput.getSphereVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& capsuleVsConvexPolyhedronBatch = narrowPhaseInput.getCapsuleVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& convexPolyhedronVsConvexPolyhedronBatch = narrowPhaseInput.getConvexPolyhedronVsConvexPolyhedronBatch();

    // Process the potential contacts
    processPotentialContacts(sphereVsSphereBatch, updateLastFrameInfo, potentialContactPoints, potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
    processPotentialContacts(sphereVsCapsuleBatch, updateLastFrameInfo, potentialContactPoints, potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
    processPotentialContacts(capsuleVsCapsuleBatch, updateLastFrameInfo, potentialContactPoints, potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
    processPotentialContacts(sphereVsConvexPolyhedronBatch, updateLastFrameInfo, potentialContactPoints, potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
    processPotentialContacts(capsuleVsConvexPolyhedronBatch, updateLastFrameInfo, potentialContactPoints, potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
    processPotentialContacts(convexPolyhedronVsConvexPolyhedronBatch, updateLastFrameInfo, potentialContactPoints,
                             potentialContactManifolds, mapPairIdToContactPairIndex, contactPairs);
}