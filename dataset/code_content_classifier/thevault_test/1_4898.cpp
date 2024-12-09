bool CollisionDetectionSystem::computeNarrowPhaseCollisionSnapshot(NarrowPhaseInput& narrowPhaseInput, CollisionCallback& callback) {

    RP3D_PROFILE("CollisionDetectionSystem::computeNarrowPhaseCollisionSnapshot()", mProfiler);

    MemoryAllocator& allocator = mMemoryManager.getHeapAllocator();

    // Test the narrow-phase collision detection on the batches to be tested
    bool collisionFound = testNarrowPhaseCollision(narrowPhaseInput, false, allocator);

    // If collision has been found, create contacts
    if (collisionFound) {

        Array<ContactPointInfo> potentialContactPoints(allocator);
        Array<ContactManifoldInfo> potentialContactManifolds(allocator);
        Array<ContactPair> contactPairs(allocator);
        Array<ContactPair> lostContactPairs(allocator);                  // Not used during collision snapshots
        Array<ContactManifold> contactManifolds(allocator);
        Array<ContactPoint> contactPoints(allocator);

        // Process all the potential contacts after narrow-phase collision
        processAllPotentialContacts(narrowPhaseInput, true, potentialContactPoints, potentialContactManifolds, &contactPairs);

        // Reduce the number of contact points in the manifolds
        reducePotentialContactManifolds(&contactPairs, potentialContactManifolds, potentialContactPoints);

        // Create the actual contact manifolds and contact points
        createSnapshotContacts(contactPairs, contactManifolds, contactPoints, potentialContactManifolds, potentialContactPoints);

        // Report the contacts to the user
        reportContacts(callback, &contactPairs, &contactManifolds, &contactPoints, lostContactPairs);
    }

    return collisionFound;
}