void CollisionDetectionSystem::reducePotentialContactManifolds(Array<ContactPair>* contactPairs,
                                                         Array<ContactManifoldInfo>& potentialContactManifolds,
                                                         const Array<ContactPointInfo>& potentialContactPoints) const {

    RP3D_PROFILE("CollisionDetectionSystem::reducePotentialContactManifolds()", mProfiler);

    // Reduce the number of potential contact manifolds in a contact pair
    const uint32 nbContactPairs = static_cast<uint32>(contactPairs->size());
    for (uint32 i=0; i < nbContactPairs; i++) {

        ContactPair& contactPair = (*contactPairs)[i];

        // While there are too many manifolds in the contact pair
        while(contactPair.nbPotentialContactManifolds > NB_MAX_CONTACT_MANIFOLDS) {

            // Look for a manifold with the smallest contact penetration depth.
            decimal minDepth = DECIMAL_LARGEST;
            int minDepthManifoldIndex = -1;
            for (uint32 j=0; j < contactPair.nbPotentialContactManifolds; j++) {

                ContactManifoldInfo& manifold = potentialContactManifolds[contactPair.potentialContactManifoldsIndices[j]];

                // Get the largest contact point penetration depth of the manifold
                const decimal depth = computePotentialManifoldLargestContactDepth(manifold, potentialContactPoints);

                if (depth < minDepth) {
                    minDepth = depth;
                    minDepthManifoldIndex = static_cast<int>(j);
                }
            }

            // Remove the non optimal manifold
            assert(minDepthManifoldIndex >= 0);
            contactPair.removePotentialManifoldAtIndex(minDepthManifoldIndex);
        }
    }

    // Reduce the number of potential contact points in the manifolds
    for (uint32 i=0; i < nbContactPairs; i++) {

        const ContactPair& pairContact = (*contactPairs)[i];

        // For each potential contact manifold
        for (uint32 j=0; j < pairContact.nbPotentialContactManifolds; j++) {

            ContactManifoldInfo& manifold = potentialContactManifolds[pairContact.potentialContactManifoldsIndices[j]];

            // If there are two many contact points in the manifold
            if (manifold.nbPotentialContactPoints > MAX_CONTACT_POINTS_IN_MANIFOLD) {

                Transform shape1LocalToWorldTransoform = mCollidersComponents.getLocalToWorldTransform(pairContact.collider1Entity);

                // Reduce the number of contact points in the manifold
                reduceContactPoints(manifold, shape1LocalToWorldTransoform, potentialContactPoints);
            }

            assert(manifold.nbPotentialContactPoints <= MAX_CONTACT_POINTS_IN_MANIFOLD);

            // Remove the duplicated contact points in the manifold (if any)
            removeDuplicatedContactPointsInManifold(manifold, potentialContactPoints);
        }
    }
}