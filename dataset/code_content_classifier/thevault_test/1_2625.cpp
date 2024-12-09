AStarSearch(const GraphType* pGraph, int pSourceIndex, int pTargetIndex)
        :   mGraph(pGraph), mShortestPathTree( pGraph->getNumberOfAllNodes() ), mSearchFrontier( pGraph->getNumberOfAllNodes() ),
            mGCosts(pGraph->getNumberOfAllNodes(), 0.f), mFCosts(pGraph->getNumberOfAllNodes(), 0.f),
            mSourceIndex(pSourceIndex), mTargetIndex(pTargetIndex)
    {
        getPreparedForSearch(mSourceIndex, mTargetIndex);
    }