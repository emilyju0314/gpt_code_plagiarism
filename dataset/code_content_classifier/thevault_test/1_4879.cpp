void OverlappingPairs::clearObsoleteLastFrameCollisionInfos() {

    RP3D_PROFILE("OverlappingPairs::clearObsoleteLastFrameCollisionInfos()", mProfiler);

    // For each concave overlapping pair
    const uint64 nbConcavePairs = mConcavePairs.size();
    for (uint64 i=0; i < nbConcavePairs; i++) {

        mConcavePairs[i].clearObsoleteLastFrameInfos();
    }
}