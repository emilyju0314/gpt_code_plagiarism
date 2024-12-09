void CollisionDetectionSystem::testOverlap(OverlapCallback& callback) {

    NarrowPhaseInput narrowPhaseInput(mMemoryManager.getPoolAllocator(), mOverlappingPairs);

    // Compute the broad-phase collision detection
    computeBroadPhase();

    // Compute the middle-phase collision detection
    computeMiddlePhase(narrowPhaseInput, false);

    // Compute the narrow-phase collision detection and report overlapping shapes
    computeNarrowPhaseOverlapSnapshot(narrowPhaseInput, &callback);
}