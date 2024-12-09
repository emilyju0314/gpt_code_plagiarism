void CollisionDetectionSystem::addLostContactPair(OverlappingPairs::OverlappingPair& overlappingPair) {

    const uint32 collider1Index = mCollidersComponents.getEntityIndex(overlappingPair.collider1);
    const uint32 collider2Index = mCollidersComponents.getEntityIndex(overlappingPair.collider2);

    const Entity body1Entity = mCollidersComponents.mBodiesEntities[collider1Index];
    const Entity body2Entity = mCollidersComponents.mBodiesEntities[collider2Index];

    const bool isCollider1Trigger = mCollidersComponents.mIsTrigger[collider1Index];
    const bool isCollider2Trigger = mCollidersComponents.mIsTrigger[collider2Index];
    const bool isTrigger = isCollider1Trigger || isCollider2Trigger;

    // Create a lost contact pair
    ContactPair lostContactPair(overlappingPair.pairID, body1Entity, body2Entity, overlappingPair.collider1, overlappingPair.collider2, static_cast<uint32>(mLostContactPairs.size()),
                                true, isTrigger);
    mLostContactPairs.add(lostContactPair);
}