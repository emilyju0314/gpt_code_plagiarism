void CollisionDetectionSystem::updateOverlappingPairs(const Array<Pair<int32, int32>>& overlappingNodes) {

    RP3D_PROFILE("CollisionDetectionSystem::updateOverlappingPairs()", mProfiler);

    // For each overlapping pair of nodes
    const uint32 nbOverlappingNodes = static_cast<uint32>(overlappingNodes.size());
    for (uint32 i=0; i < nbOverlappingNodes; i++) {

        Pair<int32, int32> nodePair = overlappingNodes[i];

        assert(nodePair.first != -1);
        assert(nodePair.second != -1);

        // Skip pairs with same overlapping nodes
        if (nodePair.first != nodePair.second) {

            // Get the two colliders
            const Entity collider1Entity = mMapBroadPhaseIdToColliderEntity[nodePair.first];
            const Entity collider2Entity = mMapBroadPhaseIdToColliderEntity[nodePair.second];

            const uint32 collider1Index = mCollidersComponents.getEntityIndex(collider1Entity);
            const uint32 collider2Index = mCollidersComponents.getEntityIndex(collider2Entity);

            // Get the two bodies
            const Entity body1Entity = mCollidersComponents.mBodiesEntities[collider1Index];
            const Entity body2Entity = mCollidersComponents.mBodiesEntities[collider2Index];

            // If the two colliders are from the same body, skip it
            if (body1Entity != body2Entity) {

                const uint32 nbEnabledColliderComponents = mCollidersComponents.getNbEnabledComponents();
                const bool isBody1Enabled = collider1Index < nbEnabledColliderComponents;
                const bool isBody2Enabled = collider2Index < nbEnabledColliderComponents;
                bool isBody1Static = false;
                bool isBody2Static = false;
                uint32 rigidBody1Index, rigidBody2Index;
                if (mRigidBodyComponents.hasComponentGetIndex(body1Entity, rigidBody1Index)) {
                    isBody1Static = mRigidBodyComponents.mBodyTypes[rigidBody1Index] == BodyType::STATIC;
                }
                if (mRigidBodyComponents.hasComponentGetIndex(body2Entity, rigidBody2Index)) {
                    isBody2Static = mRigidBodyComponents.mBodyTypes[rigidBody2Index] == BodyType::STATIC;
                }

                const bool isBody1Active = isBody1Enabled && !isBody1Static;
                const bool isBody2Active = isBody2Enabled && !isBody2Static;

                if (isBody1Active || isBody2Active) {

                    // Check if the bodies are in the set of bodies that cannot collide between each other
                    const bodypair bodiesIndex = OverlappingPairs::computeBodiesIndexPair(body1Entity, body2Entity);
                    if (!mNoCollisionPairs.contains(bodiesIndex)) {

                        // Compute the overlapping pair ID
                        const uint64 pairId = pairNumbers(std::max(nodePair.first, nodePair.second), std::min(nodePair.first, nodePair.second));

                        // Check if the overlapping pair already exists
                        OverlappingPairs::OverlappingPair* overlappingPair = mOverlappingPairs.getOverlappingPair(pairId);
                        if (overlappingPair == nullptr) {

                            const unsigned short shape1CollideWithMaskBits = mCollidersComponents.mCollideWithMaskBits[collider1Index];
                            const unsigned short shape2CollideWithMaskBits = mCollidersComponents.mCollideWithMaskBits[collider2Index];

                            const unsigned short shape1CollisionCategoryBits = mCollidersComponents.mCollisionCategoryBits[collider1Index];
                            const unsigned short shape2CollisionCategoryBits = mCollidersComponents.mCollisionCategoryBits[collider2Index];

                            // Check if the collision filtering allows collision between the two shapes
                            if ((shape1CollideWithMaskBits & shape2CollisionCategoryBits) != 0 &&
                                (shape1CollisionCategoryBits & shape2CollideWithMaskBits) != 0) {

                                Collider* shape1 = mCollidersComponents.mColliders[collider1Index];
                                Collider* shape2 = mCollidersComponents.mColliders[collider2Index];

                                // Check that at least one collision shape is convex
                                const bool isShape1Convex = shape1->getCollisionShape()->isConvex();
                                const bool isShape2Convex = shape2->getCollisionShape()->isConvex();
                                if (isShape1Convex || isShape2Convex) {

                                    // Add the new overlapping pair
                                    mOverlappingPairs.addPair(collider1Index, collider2Index, isShape1Convex && isShape2Convex);
                                }
                            }
                        }
                        else {

                            // We do not need to test the pair for overlap because it has just been reported that they still overlap
                            overlappingPair->needToTestOverlap = false;
                        }
                    }
                }
            }
        }
    }
}