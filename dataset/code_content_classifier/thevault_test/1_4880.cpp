void OverlappingPairs::updateCollidingInPreviousFrame() {

    RP3D_PROFILE("OverlappingPairs::updateCollidingInPreviousFrame()", mProfiler);

    // For each convex overlapping pair
    const uint64 nbConvexPairs = mConvexPairs.size();
    for (uint64 i=0; i < nbConvexPairs; i++) {

        mConvexPairs[i].collidingInPreviousFrame = mConvexPairs[i].collidingInCurrentFrame;
    }

    // For each concave overlapping pair
    const uint64 nbConcavePairs = mConcavePairs.size();
    for (uint64 i=0; i < nbConcavePairs; i++) {

        mConcavePairs[i].collidingInPreviousFrame = mConcavePairs[i].collidingInCurrentFrame;
    }
}