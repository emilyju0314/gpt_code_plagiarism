void CollisionDetectionSystem::testOverlap(CollisionBody* body, OverlapCallback& callback) {

    NarrowPhaseInput narrowPhaseInput(mMemoryManager.getPoolAllocator(), mOverlappingPairs);

    // Compute the broad-phase collision detection
    computeBroadPhase();

    // Filter the overlapping pairs to get only the ones with the selected body involved
    Array<uint64> convexPairs(mMemoryManager.getPoolAllocator());
    Array<uint64> concavePairs(mMemoryManager.getPoolAllocator());
    filterOverlappingPairs(body->getEntity(), convexPairs, concavePairs);

    if (convexPairs.size() > 0 || concavePairs.size() > 0) {

        // Compute the middle-phase collision detection
        computeMiddlePhaseCollisionSnapshot(convexPairs, concavePairs, narrowPhaseInput, false);

        // Compute the narrow-phase collision detection
        computeNarrowPhaseOverlapSnapshot(narrowPhaseInput, &callback);
    }
}