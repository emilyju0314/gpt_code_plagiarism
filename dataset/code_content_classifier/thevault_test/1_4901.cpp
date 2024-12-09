void CollisionDetectionSystem::computeLostContactPairs() {

    // For each convex pair
    const uint32 nbConvexPairs = static_cast<uint32>(mOverlappingPairs.mConvexPairs.size());
    for (uint32 i=0; i < nbConvexPairs; i++) {

        // If the two colliders of the pair were colliding in the previous frame but not in the current one
        if (mOverlappingPairs.mConvexPairs[i].collidingInPreviousFrame && !mOverlappingPairs.mConvexPairs[i].collidingInCurrentFrame) {

            // If both bodies still exist
            if (mCollidersComponents.hasComponent(mOverlappingPairs.mConvexPairs[i].collider1) && mCollidersComponents.hasComponent(mOverlappingPairs.mConvexPairs[i].collider2)) {

                // Create a lost contact pair
                addLostContactPair(mOverlappingPairs.mConvexPairs[i]);
            }
        }
    }

    // For each convex pair
    const uint32 nbConcavePairs = static_cast<uint32>(mOverlappingPairs.mConcavePairs.size());
    for (uint32 i=0; i < nbConcavePairs; i++) {

        // If the two colliders of the pair were colliding in the previous frame but not in the current one
        if (mOverlappingPairs.mConcavePairs[i].collidingInPreviousFrame && !mOverlappingPairs.mConcavePairs[i].collidingInCurrentFrame) {

            // If both bodies still exist
            if (mCollidersComponents.hasComponent(mOverlappingPairs.mConcavePairs[i].collider1) && mCollidersComponents.hasComponent(mOverlappingPairs.mConcavePairs[i].collider2)) {

                // Create a lost contact pair
                addLostContactPair(mOverlappingPairs.mConcavePairs[i]);
            }
        }
    }
}