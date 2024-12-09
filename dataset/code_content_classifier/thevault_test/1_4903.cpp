void CollisionDetectionSystem::initContactsWithPreviousOnes() {

    const decimal persistentContactDistThresholdSqr = mWorld->mConfig.persistentContactDistanceThreshold * mWorld->mConfig.persistentContactDistanceThreshold;

    // For each contact pair of the current frame
    const uint32 nbCurrentContactPairs = static_cast<uint32>(mCurrentContactPairs->size());
    for (uint32 i=0; i < nbCurrentContactPairs; i++) {

        ContactPair& currentContactPair = (*mCurrentContactPairs)[i];

        // Find the corresponding contact pair in the previous frame (if any)
        auto itPrevContactPair = mPreviousMapPairIdToContactPairIndex.find(currentContactPair.pairId);

        // If we have found a corresponding contact pair in the previous frame
        if (itPrevContactPair != mPreviousMapPairIdToContactPairIndex.end()) {

            const uint32 previousContactPairIndex = itPrevContactPair->second;
            ContactPair& previousContactPair = (*mPreviousContactPairs)[previousContactPairIndex];

            // --------------------- Contact Manifolds --------------------- //

            const uint32 contactManifoldsIndex = currentContactPair.contactManifoldsIndex;
            const uint32 nbContactManifolds = currentContactPair.nbContactManifolds;

            // For each current contact manifold of the current contact pair
            for (uint32 m=contactManifoldsIndex; m < contactManifoldsIndex + nbContactManifolds; m++) {

                assert(m < mCurrentContactManifolds->size());
                ContactManifold& currentContactManifold = (*mCurrentContactManifolds)[m];
                assert(currentContactManifold.nbContactPoints > 0);
                ContactPoint& currentContactPoint = (*mCurrentContactPoints)[currentContactManifold.contactPointsIndex];
                const Vector3& currentContactPointNormal = currentContactPoint.getNormal();

                // Find a similar contact manifold among the contact manifolds from the previous frame (for warmstarting)
                const uint32 previousContactManifoldIndex = previousContactPair.contactManifoldsIndex;
                const uint32 previousNbContactManifolds = previousContactPair.nbContactManifolds;
                for (uint32 p=previousContactManifoldIndex; p < previousContactManifoldIndex + previousNbContactManifolds; p++) {

                    ContactManifold& previousContactManifold = (*mPreviousContactManifolds)[p];
                    assert(previousContactManifold.nbContactPoints > 0);
                    ContactPoint& previousContactPoint = (*mPreviousContactPoints)[previousContactManifold.contactPointsIndex];

                    // If the previous contact manifold has a similar contact normal with the current manifold
                    if (previousContactPoint.getNormal().dot(currentContactPointNormal) >= mWorld->mConfig.cosAngleSimilarContactManifold) {

                        // Transfer data from the previous contact manifold to the current one
                        currentContactManifold.frictionVector1 = previousContactManifold.frictionVector1;
                        currentContactManifold.frictionVector2 = previousContactManifold.frictionVector2;
                        currentContactManifold.frictionImpulse1 = previousContactManifold.frictionImpulse1;
                        currentContactManifold.frictionImpulse2 = previousContactManifold.frictionImpulse2;
                        currentContactManifold.frictionTwistImpulse = previousContactManifold.frictionTwistImpulse;

                        break;
                    }
                }
            }

            // --------------------- Contact Points --------------------- //

            const uint32 contactPointsIndex = currentContactPair.contactPointsIndex;
            const uint32 nbTotalContactPoints = currentContactPair.nbToTalContactPoints;

            // For each current contact point of the current contact pair
            for (uint32 c=contactPointsIndex; c < contactPointsIndex + nbTotalContactPoints; c++) {

                assert(c < mCurrentContactPoints->size());
                ContactPoint& currentContactPoint = (*mCurrentContactPoints)[c];

                const Vector3& currentContactPointLocalShape1 = currentContactPoint.getLocalPointOnShape1();

                // Find a similar contact point among the contact points from the previous frame (for warmstarting)
                const uint32 previousContactPointsIndex = previousContactPair.contactPointsIndex;
                const uint32 previousNbContactPoints = previousContactPair.nbToTalContactPoints;
                for (uint32 p=previousContactPointsIndex; p < previousContactPointsIndex + previousNbContactPoints; p++) {

                    const ContactPoint& previousContactPoint = (*mPreviousContactPoints)[p];

                    // If the previous contact point is very close to th current one
                    const decimal distSquare = (currentContactPointLocalShape1 - previousContactPoint.getLocalPointOnShape1()).lengthSquare();
                    if (distSquare <= persistentContactDistThresholdSqr) {

                        // Transfer data from the previous contact point to the current one
                        currentContactPoint.setPenetrationImpulse(previousContactPoint.getPenetrationImpulse());
                        currentContactPoint.setIsRestingContact(previousContactPoint.getIsRestingContact());

                        break;
                    }
                }
            }
        }
    }
}