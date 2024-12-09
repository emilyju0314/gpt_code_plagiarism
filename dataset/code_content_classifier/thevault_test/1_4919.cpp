void CollisionDetectionSystem::filterOverlappingPairs(Entity bodyEntity, Array<uint64>& convexPairs, Array<uint64>& concavePairs) const {

    // For each convex pairs
    const uint32 nbConvexPairs = static_cast<uint32>(mOverlappingPairs.mConvexPairs.size());
    for (uint32 i=0; i < nbConvexPairs; i++) {

        if (mCollidersComponents.getBody(mOverlappingPairs.mConvexPairs[i].collider1) == bodyEntity ||
            mCollidersComponents.getBody(mOverlappingPairs.mConvexPairs[i].collider2) == bodyEntity) {

            convexPairs.add(mOverlappingPairs.mConvexPairs[i].pairID);
        }
    }

    // For each concave pairs
    const uint32 nbConcavePairs = static_cast<uint32>(mOverlappingPairs.mConcavePairs.size());
    for (uint32 i=0; i < nbConcavePairs; i++) {

        if (mCollidersComponents.getBody(mOverlappingPairs.mConcavePairs[i].collider1) == bodyEntity ||
            mCollidersComponents.getBody(mOverlappingPairs.mConcavePairs[i].collider2) == bodyEntity) {

            concavePairs.add(mOverlappingPairs.mConcavePairs[i].pairID);
        }
    }
}