AStarSearch(const GraphType* pGraph)
    : mGraph(pGraph), mShortestPathTree( pGraph->getNumberOfAllNodes() ), mSearchFrontier( pGraph->getNumberOfAllNodes() ),
    mGCosts(pGraph->getNumberOfAllNodes(), 0.f), mFCosts(pGraph->getNumberOfAllNodes(), 0.f),
    mSourceIndex(GraphCommons::INVALID_NODE_INDEX), mTargetIndex(GraphCommons::INVALID_NODE_INDEX)
    { }