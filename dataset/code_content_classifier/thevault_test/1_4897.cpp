void CollisionDetectionSystem::computeOverlapSnapshotContactPairs(NarrowPhaseInfoBatch& narrowPhaseInfoBatch, Array<ContactPair>& contactPairs,
                                                           Set<uint64>& setOverlapContactPairId) const {

    RP3D_PROFILE("CollisionDetectionSystem::computeSnapshotContactPairs()", mProfiler);

    // For each narrow phase info object
    for(uint32 i=0; i < narrowPhaseInfoBatch.getNbObjects(); i++) {

        // If there is a collision
        if (narrowPhaseInfoBatch.narrowPhaseInfos[i].isColliding) {

            // If the contact pair does not already exist
            if (!setOverlapContactPairId.contains(narrowPhaseInfoBatch.narrowPhaseInfos[i].overlappingPairId)) {

                const Entity collider1Entity = narrowPhaseInfoBatch.narrowPhaseInfos[i].colliderEntity1;
                const Entity collider2Entity = narrowPhaseInfoBatch.narrowPhaseInfos[i].colliderEntity2;

                const uint32 collider1Index = mCollidersComponents.getEntityIndex(collider1Entity);
                const uint32 collider2Index = mCollidersComponents.getEntityIndex(collider2Entity);

                const Entity body1Entity = mCollidersComponents.mBodiesEntities[collider1Index];
                const Entity body2Entity = mCollidersComponents.mBodiesEntities[collider2Index];

                const bool isTrigger = mCollidersComponents.mIsTrigger[collider1Index] || mCollidersComponents.mIsTrigger[collider2Index];

                // Create a new contact pair
                ContactPair contactPair(narrowPhaseInfoBatch.narrowPhaseInfos[i].overlappingPairId, body1Entity, body2Entity, collider1Entity, collider2Entity, static_cast<uint32>(contactPairs.size()), false, isTrigger);
                contactPairs.add(contactPair);

                setOverlapContactPairId.add(narrowPhaseInfoBatch.narrowPhaseInfos[i].overlappingPairId);
            }
        }

        narrowPhaseInfoBatch.resetContactPoints(i);
    }
}