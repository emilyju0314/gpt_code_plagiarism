void CollisionDetectionSystem::testCollision(CollisionCallback& callback) {

    NarrowPhaseInput narrowPhaseInput(mMemoryManager.getPoolAllocator(), mOverlappingPairs);

    // Compute the broad-phase collision detection
    computeBroadPhase();

    // Compute the middle-phase collision detection
    computeMiddlePhase(narrowPhaseInput, true);

    // Compute the narrow-phase collision detection and report contacts
    computeNarrowPhaseCollisionSnapshot(narrowPhaseInput, callback);
}