void CollisionDetectionSystem::addContactPairsToBodies() {

    const uint32 nbContactPairs = static_cast<uint32>(mCurrentContactPairs->size());
    for (uint32 p=0 ; p < nbContactPairs; p++) {

        ContactPair& contactPair = (*mCurrentContactPairs)[p];

        const bool isBody1Rigid = mRigidBodyComponents.hasComponent(contactPair.body1Entity);
        const bool isBody2Rigid = mRigidBodyComponents.hasComponent(contactPair.body2Entity);

        // Add the associated contact pair to both bodies of the pair (used to create islands later)
        if (isBody1Rigid) {
           mRigidBodyComponents.addContacPair(contactPair.body1Entity, p);
        }
        if (isBody2Rigid) {
           mRigidBodyComponents.addContacPair(contactPair.body2Entity, p);
        }

        // If at least of body is a CollisionBody
        if (!isBody1Rigid || !isBody2Rigid) {

            // Add the pair index to the array of pairs with CollisionBody
            mCollisionBodyContactPairsIndices.add(p);
        }
    }
}