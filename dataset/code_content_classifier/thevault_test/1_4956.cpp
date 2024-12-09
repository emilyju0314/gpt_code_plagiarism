void RigidBody::resetOverlappingPairs() {

    // For each collider of the body
    const Array<Entity>& colliderEntities = mWorld.mCollisionBodyComponents.getColliders(mEntity);
    for (uint32 i=0; i < colliderEntities.size(); i++) {

        // Get the currently overlapping pairs for this collider
        Array<uint64> overlappingPairs = mWorld.mCollidersComponents.getOverlappingPairs(colliderEntities[i]);

        const uint64 nbOverlappingPairs = overlappingPairs.size();
        for (uint64 j=0; j < nbOverlappingPairs; j++) {

            mWorld.mCollisionDetection.mOverlappingPairs.removePair(overlappingPairs[j]);
        }
    }

    // Make sure we recompute the overlapping pairs with this body in the next frame
    askForBroadPhaseCollisionCheck();
}