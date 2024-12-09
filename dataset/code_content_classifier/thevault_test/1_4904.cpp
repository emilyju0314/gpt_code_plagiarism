void CollisionDetectionSystem::removeCollider(Collider* collider) {

    const int colliderBroadPhaseId = collider->getBroadPhaseId();

    assert(colliderBroadPhaseId != -1);
    assert(mMapBroadPhaseIdToColliderEntity.containsKey(colliderBroadPhaseId));

    // Remove all the overlapping pairs involving this collider
    Array<uint64>& overlappingPairs = mCollidersComponents.getOverlappingPairs(collider->getEntity());
    while(overlappingPairs.size() > 0) {

        // TODO : Remove all the contact manifold of the overlapping pair from the contact manifolds array of the two bodies involved

        // Remove the overlapping pair
        mOverlappingPairs.removePair(overlappingPairs[0]);
    }

    mMapBroadPhaseIdToColliderEntity.remove(colliderBroadPhaseId);

    // Remove the body from the broad-phase
    mBroadPhaseSystem.removeCollider(collider);
}