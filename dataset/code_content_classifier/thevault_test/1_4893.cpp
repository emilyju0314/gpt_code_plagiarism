void CollisionDetectionSystem::computeMapPreviousContactPairs() {

    mPreviousMapPairIdToContactPairIndex.clear();
    const uint32 nbCurrentContactPairs = static_cast<uint32>(mCurrentContactPairs->size());
    for (uint32 i=0; i < nbCurrentContactPairs; i++) {
        mPreviousMapPairIdToContactPairIndex.add(Pair<uint64, uint>((*mCurrentContactPairs)[i].pairId, i));
    }
}