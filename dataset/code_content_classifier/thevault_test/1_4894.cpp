bool CollisionDetectionSystem::computeNarrowPhaseOverlapSnapshot(NarrowPhaseInput& narrowPhaseInput, OverlapCallback* callback) {

    RP3D_PROFILE("CollisionDetectionSystem::computeNarrowPhaseOverlapSnapshot()", mProfiler);

    MemoryAllocator& allocator = mMemoryManager.getPoolAllocator();

    // Test the narrow-phase collision detection on the batches to be tested
    bool collisionFound = testNarrowPhaseCollision(narrowPhaseInput, false, allocator);
    if (collisionFound && callback != nullptr) {

        // Compute the overlapping colliders
        Array<ContactPair> contactPairs(allocator);
        Array<ContactPair> lostContactPairs(allocator);          // Always empty in this case (snapshot)
        computeOverlapSnapshotContactPairs(narrowPhaseInput, contactPairs);

        // Report overlapping colliders
        OverlapCallback::CallbackData callbackData(contactPairs, lostContactPairs, false, *mWorld);
        (*callback).onOverlap(callbackData);
    }

    return collisionFound;
}