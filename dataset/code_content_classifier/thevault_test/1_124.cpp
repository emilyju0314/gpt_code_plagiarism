void Get(LeaderData &aLeaderData) const
    {
        aLeaderData.SetPartitionId(HostSwap32(mPartitionId));
        aLeaderData.SetWeighting(mWeighting);
        aLeaderData.SetDataVersion(mDataVersion);
        aLeaderData.SetStableDataVersion(mStableDataVersion);
        aLeaderData.SetLeaderRouterId(mLeaderRouterId);
    }