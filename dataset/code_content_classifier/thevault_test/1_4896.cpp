void CollisionDetectionSystem::notifyOverlappingPairsToTestOverlap(Collider* collider) {

    // Get the overlapping pairs involved with this collider
    Array<uint64>& overlappingPairs = mCollidersComponents.getOverlappingPairs(collider->getEntity());

    const uint32 nbPairs = static_cast<uint32>(overlappingPairs.size());
    for (uint32 i=0; i < nbPairs; i++) {

        // Notify that the overlapping pair needs to be testbed for overlap
        mOverlappingPairs.setNeedToTestOverlap(overlappingPairs[i], true);
    }
}