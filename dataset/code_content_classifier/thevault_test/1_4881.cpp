void CollisionDetectionSystem::computeBroadPhase() {

    RP3D_PROFILE("CollisionDetectionSystem::computeBroadPhase()", mProfiler);

    assert(mBroadPhaseOverlappingNodes.size() == 0);

    // Ask the broad-phase to compute all the shapes overlapping with the shapes that
    // have moved or have been added in the last frame. This call can only add new
    // overlapping pairs in the collision detection.
    mBroadPhaseSystem.computeOverlappingPairs(mMemoryManager, mBroadPhaseOverlappingNodes);

    // Create new overlapping pairs if necessary
    updateOverlappingPairs(mBroadPhaseOverlappingNodes);

    // Remove non overlapping pairs
    removeNonOverlappingPairs();

    mBroadPhaseOverlappingNodes.clear();
}