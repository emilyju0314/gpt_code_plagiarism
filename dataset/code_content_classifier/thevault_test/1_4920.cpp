void CollisionDetectionSystem::filterOverlappingPairs(Entity body1Entity, Entity body2Entity, Array<uint64>& convexPairs, Array<uint64>& concavePairs) const {

    // For each convex pair
    const uint32 nbConvexPairs = static_cast<uint32>(mOverlappingPairs.mConvexPairs.size());
    for (uint32 i=0; i < nbConvexPairs; i++) {

        const Entity collider1Body = mCollidersComponents.getBody(mOverlappingPairs.mConvexPairs[i].collider1);
        const Entity collider2Body = mCollidersComponents.getBody(mOverlappingPairs.mConvexPairs[i].collider2);

        if ((collider1Body == body1Entity && collider2Body == body2Entity) ||
            (collider1Body == body2Entity && collider2Body == body1Entity)) {

            convexPairs.add(mOverlappingPairs.mConvexPairs[i].pairID);
        }
    }

    // For each concave pair
    const uint32 nbConcavePairs = static_cast<uint32>(mOverlappingPairs.mConcavePairs.size());
    for (uint32 i=0; i < nbConcavePairs; i++) {

        const Entity collider1Body = mCollidersComponents.getBody(mOverlappingPairs.mConcavePairs[i].collider1);
        const Entity collider2Body = mCollidersComponents.getBody(mOverlappingPairs.mConcavePairs[i].collider2);

        if ((collider1Body == body1Entity && collider2Body == body2Entity) ||
            (collider1Body == body2Entity && collider2Body == body1Entity)) {

            concavePairs.add(mOverlappingPairs.mConcavePairs[i].pairID);
        }
    }
}