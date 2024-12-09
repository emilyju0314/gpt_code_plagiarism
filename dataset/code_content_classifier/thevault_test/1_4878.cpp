void OverlappingPairs::removePair(uint64 pairIndex, bool isConvexVsConvex) {

    RP3D_PROFILE("OverlappingPairs::removePair()", mProfiler);

    if (isConvexVsConvex) {

        const uint64 nbConvexPairs = mConvexPairs.size();

        assert(pairIndex < nbConvexPairs);

        // Remove the involved overlapping pair from the two colliders
        assert(mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider1).find(mConvexPairs[pairIndex].pairID) != mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider1).end());
        assert(mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider2).find(mConvexPairs[pairIndex].pairID) != mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider2).end());
        mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider1).remove(mConvexPairs[pairIndex].pairID);
        mColliderComponents.getOverlappingPairs(mConvexPairs[pairIndex].collider2).remove(mConvexPairs[pairIndex].pairID);

        assert(mMapConvexPairIdToPairIndex[mConvexPairs[pairIndex].pairID] == pairIndex);
        mMapConvexPairIdToPairIndex.remove(mConvexPairs[pairIndex].pairID);

        // Change the mapping between the pairId and the index in the convex pairs array if we swap the last item with the one to remove
        if (mConvexPairs.size() > 1 && pairIndex < (nbConvexPairs - 1)) {

            mMapConvexPairIdToPairIndex[mConvexPairs[nbConvexPairs - 1].pairID] = pairIndex;
        }

        // We want to keep the arrays tightly packed. Therefore, when a pair is removed,
        // we replace it with the last element of the array.
        mConvexPairs.removeAtAndReplaceByLast(pairIndex);
    }
    else {

        const uint64 nbConcavePairs = mConcavePairs.size();

        assert(pairIndex < nbConcavePairs);

        // Remove the involved overlapping pair to the two colliders
        assert(mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider1).find(mConcavePairs[pairIndex].pairID) != mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider1).end());
        assert(mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider2).find(mConcavePairs[pairIndex].pairID) != mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider2).end());
        mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider1).remove(mConcavePairs[pairIndex].pairID);
        mColliderComponents.getOverlappingPairs(mConcavePairs[pairIndex].collider2).remove(mConcavePairs[pairIndex].pairID);

        assert(mMapConcavePairIdToPairIndex[mConcavePairs[pairIndex].pairID] == pairIndex);
        mMapConcavePairIdToPairIndex.remove(mConcavePairs[pairIndex].pairID);

        // Destroy all the LastFrameCollisionInfo objects
        mConcavePairs[pairIndex].destroyLastFrameCollisionInfos();

        // Change the mapping between the pairId and the index in the convex pairs array if we swap the last item with the one to remove
        if (mConcavePairs.size() > 1 && pairIndex < (nbConcavePairs - 1)) {

            mMapConcavePairIdToPairIndex[mConcavePairs[nbConcavePairs - 1].pairID] = pairIndex;
        }

        // We want to keep the arrays tightly packed. Therefore, when a pair is removed,
        // we replace it with the last element of the array.
        mConcavePairs.removeAtAndReplaceByLast(pairIndex);
    }
}