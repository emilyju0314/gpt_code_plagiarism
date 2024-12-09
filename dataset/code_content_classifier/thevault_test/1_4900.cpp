void CollisionDetectionSystem::createContacts() {

    RP3D_PROFILE("CollisionDetectionSystem::createContacts()", mProfiler);

    mCurrentContactManifolds->reserve(mCurrentContactPairs->size());
    mCurrentContactPoints->reserve(mCurrentContactManifolds->size());

    // We go through all the contact pairs and add the pairs with a least a CollisionBody at the end of the
    // mProcessContactPairsOrderIslands array because those pairs have not been added during the islands
    // creation (only the pairs with two RigidBodies are added during island creation)
    mWorld->mProcessContactPairsOrderIslands.addRange(mCollisionBodyContactPairsIndices);

    assert(mWorld->mProcessContactPairsOrderIslands.size() == (*mCurrentContactPairs).size());

    // Process the contact pairs in the order defined by the islands such that the contact manifolds and
    // contact points of a given island are packed together in the array of manifolds and contact points
    const uint32 nbContactPairsToProcess = static_cast<uint32>(mWorld->mProcessContactPairsOrderIslands.size());
    for (uint32 p=0; p < nbContactPairsToProcess; p++) {

        uint32 contactPairIndex = mWorld->mProcessContactPairsOrderIslands[p];

        ContactPair& contactPair = (*mCurrentContactPairs)[contactPairIndex];

        contactPair.contactManifoldsIndex = static_cast<uint32>(mCurrentContactManifolds->size());
        contactPair.nbContactManifolds = contactPair.nbPotentialContactManifolds;
        contactPair.contactPointsIndex = static_cast<uint32>(mCurrentContactPoints->size());

        // For each potential contact manifold of the pair
        for (uint32 m=0; m < contactPair.nbPotentialContactManifolds; m++) {

            ContactManifoldInfo& potentialManifold = mPotentialContactManifolds[contactPair.potentialContactManifoldsIndices[m]];

            // Start index and number of contact points for this manifold
            const uint32 contactPointsIndex = static_cast<uint32>(mCurrentContactPoints->size());
            const int8 nbContactPoints = static_cast<int8>(potentialManifold.nbPotentialContactPoints);
            contactPair.nbToTalContactPoints += nbContactPoints;

            // Create and add the contact manifold
            mCurrentContactManifolds->emplace(contactPair.body1Entity, contactPair.body2Entity, contactPair.collider1Entity,
                                              contactPair.collider2Entity, contactPointsIndex, nbContactPoints);

            assert(potentialManifold.nbPotentialContactPoints > 0);

            // For each contact point of the manifold
            for (uint32 c=0; c < potentialManifold.nbPotentialContactPoints; c++) {

                ContactPointInfo& potentialContactPoint = mPotentialContactPoints[potentialManifold.potentialContactPointsIndices[c]];

                // Create and add the contact point
                mCurrentContactPoints->emplace(potentialContactPoint, mWorld->mConfig.persistentContactDistanceThreshold);
            }
        }
    }

    // Initialize the current contacts with the contacts from the previous frame (for warmstarting)
    initContactsWithPreviousOnes();

    // Compute the lost contacts (contact pairs that were colliding in previous frame but not in this one)
    computeLostContactPairs();

    mPreviousContactPoints->clear();
    mPreviousContactManifolds->clear();
    mPreviousContactPairs->clear();

    mNbPreviousPotentialContactManifolds = static_cast<uint32>(mPotentialContactManifolds.capacity());
    mNbPreviousPotentialContactPoints = static_cast<uint32>(mPotentialContactPoints.capacity());

    // Reset the potential contacts
    mPotentialContactPoints.clear(true);
    mPotentialContactManifolds.clear(true);

    // Compute the map from contact pairs ids to contact pair for the next frame
    computeMapPreviousContactPairs();

    mCollisionBodyContactPairsIndices.clear(true);

    mNarrowPhaseInput.clear();
}