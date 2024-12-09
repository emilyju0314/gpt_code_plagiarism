void CollisionDetectionSystem::createSnapshotContacts(Array<ContactPair>& contactPairs,
                                                 Array<ContactManifold>& contactManifolds,
                                                 Array<ContactPoint>& contactPoints,
                                                 Array<ContactManifoldInfo>& potentialContactManifolds,
                                                 Array<ContactPointInfo>& potentialContactPoints) {

    RP3D_PROFILE("CollisionDetectionSystem::createSnapshotContacts()", mProfiler);

    contactManifolds.reserve(contactPairs.size());
    contactPoints.reserve(contactManifolds.size());

    // For each contact pair
    const uint32 nbContactPairs = static_cast<uint32>(contactPairs.size());
    for (uint32 p=0; p < nbContactPairs; p++) {

        ContactPair& contactPair = contactPairs[p];
        assert(contactPair.nbPotentialContactManifolds > 0);

        contactPair.contactManifoldsIndex = static_cast<uint32>(contactManifolds.size());
        contactPair.nbContactManifolds = contactPair.nbPotentialContactManifolds;
        contactPair.contactPointsIndex = static_cast<uint32>(contactPoints.size());

        // For each potential contact manifold of the pair
        for (uint32 m=0; m < contactPair.nbPotentialContactManifolds; m++) {

            ContactManifoldInfo& potentialManifold = potentialContactManifolds[contactPair.potentialContactManifoldsIndices[m]];

            // Start index and number of contact points for this manifold
            const uint32 contactPointsIndex = static_cast<uint32>(contactPoints.size());
            const uint8 nbContactPoints = potentialManifold.nbPotentialContactPoints;
            contactPair.nbToTalContactPoints += nbContactPoints;

            // Create and add the contact manifold
            contactManifolds.emplace(contactPair.body1Entity, contactPair.body2Entity, contactPair.collider1Entity,
                                     contactPair.collider2Entity, contactPointsIndex, nbContactPoints);

            assert(potentialManifold.nbPotentialContactPoints > 0);

            // For each contact point of the manifold
            for (uint32 c=0; c < potentialManifold.nbPotentialContactPoints; c++) {

                ContactPointInfo& potentialContactPoint = potentialContactPoints[potentialManifold.potentialContactPointsIndices[c]];

                // Create a new contact point
                ContactPoint contactPoint(potentialContactPoint, mWorld->mConfig.persistentContactDistanceThreshold);

                // Add the contact point
                contactPoints.add(contactPoint);
            }
        }
    }
}