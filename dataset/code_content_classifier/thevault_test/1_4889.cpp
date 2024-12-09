bool CollisionDetectionSystem::testNarrowPhaseCollision(NarrowPhaseInput& narrowPhaseInput,
                                                        bool clipWithPreviousAxisIfStillColliding, MemoryAllocator& allocator) {

    bool contactFound = false;

    // Get the narrow-phase collision detection algorithms for each kind of collision shapes
    SphereVsSphereAlgorithm* sphereVsSphereAlgo = mCollisionDispatch.getSphereVsSphereAlgorithm();
    SphereVsCapsuleAlgorithm* sphereVsCapsuleAlgo = mCollisionDispatch.getSphereVsCapsuleAlgorithm();
    CapsuleVsCapsuleAlgorithm* capsuleVsCapsuleAlgo = mCollisionDispatch.getCapsuleVsCapsuleAlgorithm();
    SphereVsConvexPolyhedronAlgorithm* sphereVsConvexPolyAlgo = mCollisionDispatch.getSphereVsConvexPolyhedronAlgorithm();
    CapsuleVsConvexPolyhedronAlgorithm* capsuleVsConvexPolyAlgo = mCollisionDispatch.getCapsuleVsConvexPolyhedronAlgorithm();
    ConvexPolyhedronVsConvexPolyhedronAlgorithm* convexPolyVsConvexPolyAlgo = mCollisionDispatch.getConvexPolyhedronVsConvexPolyhedronAlgorithm();

    // get the narrow-phase batches to test for collision for contacts
    NarrowPhaseInfoBatch& sphereVsSphereBatchContacts = narrowPhaseInput.getSphereVsSphereBatch();
    NarrowPhaseInfoBatch& sphereVsCapsuleBatchContacts = narrowPhaseInput.getSphereVsCapsuleBatch();
    NarrowPhaseInfoBatch& capsuleVsCapsuleBatchContacts = narrowPhaseInput.getCapsuleVsCapsuleBatch();
    NarrowPhaseInfoBatch& sphereVsConvexPolyhedronBatchContacts = narrowPhaseInput.getSphereVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& capsuleVsConvexPolyhedronBatchContacts = narrowPhaseInput.getCapsuleVsConvexPolyhedronBatch();
    NarrowPhaseInfoBatch& convexPolyhedronVsConvexPolyhedronBatchContacts = narrowPhaseInput.getConvexPolyhedronVsConvexPolyhedronBatch();

    // Compute the narrow-phase collision detection for each kind of collision shapes (for contacts)
    if (sphereVsSphereBatchContacts.getNbObjects() > 0) {
        contactFound |= sphereVsSphereAlgo->testCollision(sphereVsSphereBatchContacts, 0, sphereVsSphereBatchContacts.getNbObjects(), allocator);
    }
    if (sphereVsCapsuleBatchContacts.getNbObjects() > 0) {
        contactFound |= sphereVsCapsuleAlgo->testCollision(sphereVsCapsuleBatchContacts, 0, sphereVsCapsuleBatchContacts.getNbObjects(), allocator);
    }
    if (capsuleVsCapsuleBatchContacts.getNbObjects() > 0) {
        contactFound |= capsuleVsCapsuleAlgo->testCollision(capsuleVsCapsuleBatchContacts, 0, capsuleVsCapsuleBatchContacts.getNbObjects(), allocator);
    }
    if (sphereVsConvexPolyhedronBatchContacts.getNbObjects() > 0) {
        contactFound |= sphereVsConvexPolyAlgo->testCollision(sphereVsConvexPolyhedronBatchContacts, 0, sphereVsConvexPolyhedronBatchContacts.getNbObjects(), clipWithPreviousAxisIfStillColliding, allocator);
    }
    if (capsuleVsConvexPolyhedronBatchContacts.getNbObjects() > 0) {
        contactFound |= capsuleVsConvexPolyAlgo->testCollision(capsuleVsConvexPolyhedronBatchContacts, 0, capsuleVsConvexPolyhedronBatchContacts.getNbObjects(), clipWithPreviousAxisIfStillColliding, allocator);
    }
    if (convexPolyhedronVsConvexPolyhedronBatchContacts.getNbObjects() > 0) {
        contactFound |= convexPolyVsConvexPolyAlgo->testCollision(convexPolyhedronVsConvexPolyhedronBatchContacts, 0, convexPolyhedronVsConvexPolyhedronBatchContacts.getNbObjects(), clipWithPreviousAxisIfStillColliding, allocator);
    }

    return contactFound;
}