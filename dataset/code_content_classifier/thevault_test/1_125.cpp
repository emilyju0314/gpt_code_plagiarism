void Set(const LeaderData &aLeaderData)
    {
        mPartitionId       = HostSwap32(aLeaderData.GetPartitionId());
        mWeighting         = aLeaderData.GetWeighting();
        mDataVersion       = aLeaderData.GetDataVersion();
        mStableDataVersion = aLeaderData.GetStableDataVersion();
        mLeaderRouterId    = aLeaderData.GetLeaderRouterId();
    }