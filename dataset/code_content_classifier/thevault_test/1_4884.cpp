void CollisionDetectionSystem::addNoCollisionPair(Entity body1Entity, Entity body2Entity) {
    mNoCollisionPairs.add(OverlappingPairs::computeBodiesIndexPair(body1Entity, body2Entity));

    // If there already are OverlappingPairs involved, they should be removed; Or they will remain in collision state
    Array<uint64> toBeRemoved(mMemoryManager.getPoolAllocator());
    const Array<Entity>& colliderEntities = mWorld->mCollisionBodyComponents.getColliders(body1Entity);
    for (uint32 i = 0; i < colliderEntities.size(); ++i) {

        // Get the currently overlapping pairs for colliders of body1
        const Array<uint64>& overlappingPairs = mCollidersComponents.getOverlappingPairs(colliderEntities[i]);

        for (uint32 j = 0; j < overlappingPairs.size(); ++j) {

            OverlappingPairs::OverlappingPair* pair = mOverlappingPairs.getOverlappingPair(overlappingPairs[j]);
            assert(pair != nullptr);

            const Entity overlappingBody1 = mOverlappingPairs.mColliderComponents.getBody(pair->collider1);
            const Entity overlappingBody2 = mOverlappingPairs.mColliderComponents.getBody(pair->collider2);
            if (overlappingBody1 == body2Entity || overlappingBody2 == body2Entity) {
                toBeRemoved.add(overlappingPairs[j]);
            }
        }
    }

    // Remove the overlapping pairs that needs to be removed
    for (uint32 i = 0; i < toBeRemoved.size(); ++i) {
        mOverlappingPairs.removePair(toBeRemoved[i]);
    }
}