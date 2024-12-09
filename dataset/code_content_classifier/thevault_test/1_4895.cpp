void CollisionDetectionSystem::computeOverlapSnapshotContactPairs(NarrowPhaseInput& narrowPhaseInput, Array<ContactPair>& contactPairs) const {

    Set<uint64> setOverlapContactPairId(mMemoryManager.getHeapAllocator());

    // get the narrow-phase batches to test for collision
    NarrowPhaseInfoBatch& sphereVsSphereBatch = narrowPhaseInput.getSphereVsSphereBatch();
    NarrowPhaseInfoBatch& sphereVsCapsuleBatch = narrowPhaseInput.getSphereVsCapsuleBatch();
    NarrowPhaseInfoBatch& capsuleVsCapsuleBatch = narrowPhaseInput.getCapsuleVsCapsuleBatch();
    NarrowPhaseInfoBatch& sphereVsConvexPolyhedronBatch = narrowPhaseInput.getSphereVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& capsuleVsConvexPolyhedronBatch = narrowPhaseInput.getCapsuleVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& convexPolyhedronVsConvexPolyhedronBatch = narrowPhaseInput.getConvexPolyhedronVsConvexPolyhedronBatch();

    // Process the potential contacts
    computeOverlapSnapshotContactPairs(sphereVsSphereBatch, contactPairs, setOverlapContactPairId);
    computeOverlapSnapshotContactPairs(sphereVsCapsuleBatch, contactPairs, setOverlapContactPairId);
    computeOverlapSnapshotContactPairs(capsuleVsCapsuleBatch, contactPairs, setOverlapContactPairId);
    computeOverlapSnapshotContactPairs(sphereVsConvexPolyhedronBatch, contactPairs, setOverlapContactPairId);
    computeOverlapSnapshotContactPairs(capsuleVsConvexPolyhedronBatch, contactPairs, setOverlapContactPairId);
    computeOverlapSnapshotContactPairs(convexPolyhedronVsConvexPolyhedronBatch, contactPairs, setOverlapContactPairId);
}