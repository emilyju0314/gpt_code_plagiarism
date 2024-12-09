void CollisionDetectionSystem::removeNonOverlappingPairs() {

    RP3D_PROFILE("CollisionDetectionSystem::removeNonOverlappingPairs()", mProfiler);

    // For each convex pairs
    for (uint64 i=0; i < mOverlappingPairs.mConvexPairs.size(); i++) {

        OverlappingPairs::ConvexOverlappingPair& overlappingPair = mOverlappingPairs.mConvexPairs[i];

        // Check if we need to test overlap. If so, test if the two shapes are still overlapping.
        // Otherwise, we destroy the overlapping pair
        if (overlappingPair.needToTestOverlap) {

            if(mBroadPhaseSystem.testOverlappingShapes(overlappingPair.broadPhaseId1, overlappingPair.broadPhaseId2)) {
                overlappingPair.needToTestOverlap = false;
            }
            else {

                // If the two colliders of the pair were colliding in the previous frame
                if (overlappingPair.collidingInPreviousFrame) {

                    // Create a new lost contact pair
                    addLostContactPair(overlappingPair);
                }

                mOverlappingPairs.removePair(i, true);
                i--;
            }
        }
    }

    // For each concave pairs
    for (uint64 i=0; i < mOverlappingPairs.mConcavePairs.size(); i++) {

        OverlappingPairs::ConcaveOverlappingPair& overlappingPair = mOverlappingPairs.mConcavePairs[i];

        // Check if we need to test overlap. If so, test if the two shapes are still overlapping.
        // Otherwise, we destroy the overlapping pair
        if (overlappingPair.needToTestOverlap) {

            if(mBroadPhaseSystem.testOverlappingShapes(overlappingPair.broadPhaseId1, overlappingPair.broadPhaseId2)) {
                overlappingPair.needToTestOverlap = false;
            }
            else {

                // If the two colliders of the pair were colliding in the previous frame
                if (overlappingPair.collidingInPreviousFrame) {

                    // Create a new lost contact pair
                    addLostContactPair(overlappingPair);
                }

                mOverlappingPairs.removePair(i, false);
                i--;
            }
        }
    }
}