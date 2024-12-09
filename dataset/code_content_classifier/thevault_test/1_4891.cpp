void CollisionDetectionSystem::computeNarrowPhase() {

    RP3D_PROFILE("CollisionDetectionSystem::computeNarrowPhase()", mProfiler);

    MemoryAllocator& allocator = mMemoryManager.getSingleFrameAllocator();

    // Swap the previous and current contacts arrays
    swapPreviousAndCurrentContacts();

    mPotentialContactManifolds.reserve(mNbPreviousPotentialContactManifolds);
    mPotentialContactPoints.reserve(mNbPreviousPotentialContactPoints);

    // Test the narrow-phase collision detection on the batches to be tested
    testNarrowPhaseCollision(mNarrowPhaseInput, true, allocator);

    // Process all the potential contacts after narrow-phase collision
    processAllPotentialContacts(mNarrowPhaseInput, true, mPotentialContactPoints,
                                mPotentialContactManifolds, mCurrentContactPairs);

    // Reduce the number of contact points in the manifolds
    reducePotentialContactManifolds(mCurrentContactPairs, mPotentialContactManifolds, mPotentialContactPoints);

    // Add the contact pairs to the bodies
    addContactPairsToBodies();

    assert(mCurrentContactManifolds->size() == 0);
    assert(mCurrentContactPoints->size() == 0);
}